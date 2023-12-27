import polyscope_bindings as psb

import os, sys
from functools import partial

import numpy as np

from polyscope.core import get_render_engine_backend_name

device_interop_funcs = None

#############################################################################
### Default CUDA implementation of interop functions
#############################################################################

# Device interoperability requires directly copying data from user's arrays
# on the GPU into Polyscope's openGL buffers. This cannot be done directly
# through openGL, it requires a memcopy from device compute library (generally CUDA).
#
# Unfortunately, CUDA is is a nontrivial dependency, and many things could go wrong
# with installation and mismatched versions. To give more flexibility, all of the
# function calls related to the CUDA memcpy are abstracted as a dictionary of callbacks;
# as long as this dictionary is populated, Polyscope can call the functions to access
# user arrays and do the copies.
#
# There are two options for users to get the needed functions
#
# - [Default Case] The python packages `cuda` and `cupy` can be installed as additional
#   optional dependencies. They offer the necessary CUDA functions. This is the default 
#   path if device interop functions are used. The result is that any array type which
#   implements __cuda_array_interface__ or __dlpack__ (aka almost all libraries) 
#   can be automatically read from.
# 
# - [Custom Case] In some cases, the `cuda` and `cupy` packages may not install correctly,
#   or the user's own codebase may already have its own preferred bindings to cuda functions.
#   in this case the user can call set_device_interop_funcs() once, and pass a dictionary 
#   with a handful of callbacks to do the necessary mapping and copying. See below for 
#   the meaning of these callbacks.

def ensure_device_interop_funcs_resolve():
    check_device_module_availibility()
    if device_interop_funcs is not None:
        return
    resolve_default_device_interop_funcs()

def set_device_interop_funcs(func_dict):
    global device_interop_funcs
    device_interop_funcs = func_dict

def resolve_default_device_interop_funcs():

    # Try both of these imports, but fail silently if they don't work (we will try 
    # again and print an informative error below only if a relevant function is called)
    try: 
        import cuda
        from cuda import cudart
        import cupy
    except ImportError: 
        raise ImportError('This Polyscope functionality requires cuda bindings to be installed. Please install the packages `cuda` and `cupy`. Try `python -m pip install cuda-python cupy`. See https://nvidia.github.io/cuda-python/ & https://cupy.dev/.')


    # TODO is it possible to implement this without relying on exceptions?
    '''
    def is_dlpack(obj):
        return hasattr(obj, '__dlpack__') and hasattr(obj, '__dlpack_device__')
    '''

    def is_cuda_array_interface(obj):
        return hasattr(obj, '__cuda_array_interface__')


    def format_cudart_err(err):
        return (
            f"{cudart.cudaGetErrorName(err)[1].decode('utf-8')}({int(err)}): "
            f"{cudart.cudaGetErrorString(err)[1].decode('utf-8')}"
        )


    # helper function: check errors
    def check_cudart_err(args):
        if isinstance(args, tuple):
            assert len(args) >= 1
            err = args[0]
            if len(args) == 1:
                ret = None
            elif len(args) == 2:
                ret = args[1]
            else:
                ret = args[1:]
        else:
            err = args
            ret = None

        assert isinstance(err, cudart.cudaError_t), type(err)
        if err != cudart.cudaError_t.cudaSuccess:
            raise RuntimeError(format_cudart_err(err))

        return ret
    
    # helper function: dispatch to one of the kinds of objects that we can read from
    def get_array_from_unknown_data(arr):

        # __cuda_array_interface__
        if is_cuda_array_interface(arr):
            cupy_arr = cupy.ascontiguousarray(cupy.asarray(arr))

        else:
            # __dlpack__
            # (I can't figure out any way to check this except try-catch)
            try:
                cupy_arr = cupy.ascontiguousarray(cupy.from_dlpack(arr))
            except ValueError:
                pass 
           
            raise ValueError("Cannot read from device data object. Must be a _dlpack_ array or implement the __cuda_array_interface__.")

        shape = cupy_arr.shape
        dtype = cupy_arr.dtype
        n_bytes = cupy_arr.nbytes

        return cupy_arr.data.ptr, shape, dtype, n_bytes

    def map_resource_and_get_array(handle):
        check_cudart_err(cudart.cudaGraphicsMapResources(1, handle, None)),
        return check_cudart_err(cudart.cudaGraphicsSubResourceGetMappedArray(handle, 0, 0))
    
    def map_resource_and_get_pointer(handle):
        check_cudart_err(cudart.cudaGraphicsMapResources(1, handle, None)),
        raw_ptr, size = check_cudart_err(cudart.cudaGraphicsResourceGetMappedPointer(handle))
        return raw_ptr, size

    func_dict = {
        
        # returns tuple `(desc, extent, flags)`, as in cudaArrayGetInfo()
        # this function is optional, and only used for sanity checks it can be left undefined
        'get_array_info' : lambda array: 
            check_cudart_err(
                cudart.cudaArrayGetInfo(array)
            ),

        # as cudaGraphicsUnmapResources(1, handle, None)
        'unmap_resource' : lambda handle :
            check_cudart_err(cudart.cudaGraphicsUnmapResources(1, handle, None)),


        # returns a registered handle
        # as cudaGraphicsGLRegisterBuffer()
        'register_gl_buffer' : lambda native_id :
            check_cudart_err(cudart.cudaGraphicsGLRegisterBuffer(
                native_id,
                cudart.cudaGraphicsRegisterFlags.cudaGraphicsRegisterFlagsWriteDiscard
            )),
       

        # returns a registered handle
        # as in cudaGraphicsGLRegisterImage ()
        'register_gl_image_2d' : lambda native_id :
            check_cudart_err(cudart.cudaGraphicsGLRegisterImage(
                native_id,
                _CONSTANT_GL_TEXTURE_2D,
                cudart.cudaGraphicsRegisterFlags.cudaGraphicsRegisterFlagsWriteDiscard
            )),
      

        # as in cudaGraphicsUnregisterResource()
        'unregister_resource' : lambda handle :
            check_cudart_err(cudart.cudaGraphicsUnregisterResource(handle)),


        # returns array
        # as in cudaGraphicsMapResources() + cudaGraphicsSubResourceGetMappedArray()
        'map_resource_and_get_array' : map_resource_and_get_array,
        
        # returns ptr
        # as in cudaGraphicsMapResources() + cudaGraphicsResourceGetMappedPointer()
        'map_resource_and_get_pointer' : map_resource_and_get_pointer,
       

        # returns a tuple (arr_ptr, shape, dtype, nbytes)
        # The last three entries are all optional and can be None. If given they will be used for additional sanity checks.
        'get_array_ptr' : lambda input_array: 
            get_array_from_unknown_data(input_array),

        # as in cudaMemcpy
        'memcpy' : lambda dst_ptr, src_ptr, size : 
            check_cudart_err(cuda.cudart.cudaMemcpy(
                 dst_ptr, src_ptr, size, cudart.cudaMemcpyKind.cudaMemcpyDeviceToDevice
            )),


        # as in cudaMemcpy2DToArray
        'memcpy_2d' : lambda dst_ptr, src_ptr, width, height : 
            check_cudart_err(cuda.cudart.cudaMemcpy2DToArray(
                 dst_ptr, 0, 0, src_ptr, width, width, height, cudart.cudaMemcpyKind.cudaMemcpyDeviceToDevice
            )),

    }

    set_device_interop_funcs(func_dict)

        
# This seems absurd! These constants are needed for cuda.cudart calls, but there is apparently no canonical way to get them without introducing an additional dependency.
# See discussion https://discourse.panda3d.org/t/allowing-torch-tensorflow-to-directly-access-rendered-image-in-gpu/29119/3
# As a workaround, we hardcord their constant values, fetched from https://cvs.khronos.org/svn/repos/ogl/trunk/doc/registry/public/api/GL/glcorearb.h
_CONSTANT_GL_TEXTURE_2D = int('0DE1',16)
_CONSTANT_GL_TEXTURE_3D = int('806F',16)



#############################################################################
### Mapped buffer interop interface
#############################################################################

def check_device_module_availibility():

    supported_backends = ["openGL3_glfw"]
    if get_render_engine_backend_name() not in supported_backends:
        raise ValueError(f"This Polyscope functionality is not supported by the current rendering backend ({get_render_engine_backend_name()}. Supported backends: {','.join(supported_backends)}.")


class CUDAOpenGLMappedAttributeBuffer:

    # Roughly based on this, see for more goodies: https://gist.github.com/keckj/e37d312128eac8c5fca790ce1e7fc437

    def __init__(self, gl_attribute_native_id, buffer_type):

        self.gl_attribute_native_id = gl_attribute_native_id
        self.buffer_type = buffer_type
        self.resource_handle = None
        self.cuda_buffer_ptr = None
        self.cuda_buffer_size = -1
        self.finished_init = False

        ensure_device_interop_funcs_resolve()

        # Sanity checks
        if self.buffer_type != psb.DeviceBufferType.attribute:
            raise ValueError("device buffer type should be attribute")
        

        # Register the buffer 
        self.resource_handle = device_interop_funcs['register_gl_buffer'](self.gl_attribute_native_id)
        
        self.finished_init = True
        
    def __del__(self):
        if self.finished_init: 
            self.unregister()

    def unregister(self):
        self.unmap()
        device_interop_funcs['unregister_resource'](self.resource_handle)

    def map(self):
        """
        Returns a cupy memory pointer to the buffer
        """

        if self.cuda_buffer_ptr is not None:
            return 

        self.cuda_buffer_ptr, self.cuda_buffer_size = device_interop_funcs['map_resource_and_get_pointer'](self.resource_handle)

    def unmap(self):
        if not hasattr(self, 'cuda_buffer_ptr') or self.cuda_buffer_ptr is None:
            return

        device_interop_funcs['unmap_resource'](self.resource_handle)

        self.cuda_buffer_ptr = None
        self.cuda_buffer_size = -1
    
    def set_data_from_array(self, arr, buffer_size_in_bytes=None, expected_shape=None, expected_dtype=None):
        
        self.map()
      
        # cupy_arr = self.get_array_from_unknown_data(arr)

        # access the input array
        arr_ptr, arr_shape, arr_dtype, arr_nbytes = device_interop_funcs['get_array_ptr'](arr)
        
        if arr_nbytes is not None and arr_nbytes != self.cuda_buffer_size: 
            # if cupy_arr has the right size/dtype, it should have exactly the same 
            # number of bytes as the destination. This is just lazily saving us 
            # from repeating the math, and also directly validates the copy we 
            # are about to do below.
            raise ValueError(f"Mapped buffer write has wrong size, expected {arr_nbytes} bytes but got {self.cuda_buffer_size} bytes. Could it be the wrong size/shape or wrong dtype?")


        # perform the actual copy
        device_interop_funcs['memcpy'](self.cuda_buffer_ptr, arr_ptr, self.cuda_buffer_size)

        self.unmap() 


class CUDAOpenGLMappedTextureBuffer:


    def __init__(self, gl_attribute_native_id, buffer_type):

        self.gl_attribute_native_id = gl_attribute_native_id
        self.buffer_type = buffer_type
        self.resource_handle = None
        self.cuda_buffer_array = None # NOTE: 'array' has a special cuda meaning here relating to texture memory
        self.finished_init = False
        
        ensure_device_interop_funcs_resolve()

        # Register the buffer 

        if self.buffer_type == psb.DeviceBufferType.attribute:
            raise ValueError("type should be texture*")
        
        elif self.buffer_type == psb.DeviceBufferType.texture1d:
            raise ValueError("1d texture writes are not supported")
            # apparently not supported (?!) 
            # see cudaGraphicsGLRegisterImage in these docs https://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__OPENGL.html

        elif self.buffer_type == psb.DeviceBufferType.texture2d:
            self.resource_handle = device_interop_funcs['register_gl_image_2d'](self.gl_attribute_native_id)

        elif self.buffer_type == psb.DeviceBufferType.texture3d:
            # TODO
            raise ValueError("3d texture writes are not implemented")
        

        self.finished_init = True

    def __del__(self):
        if self.finished_init: 
            self.unregister()

    def unregister(self):
        self.unmap()
        device_interop_funcs['unregister_resource'](self.resource_handle)

    def map(self):
        if self.cuda_buffer_array is not None:
            return
        
        self.cuda_buffer_array = device_interop_funcs['map_resource_and_get_array'](self.resource_handle)


    def unmap(self):
        if not hasattr(self, 'cuda_buffer_array') or self.cuda_buffer_array is None:
            return

        device_interop_funcs['unmap_resource'](self.resource_handle)

        self.cuda_buffer_array = None
    
    def set_data_from_array(self, arr, texture_dims, entry_size_in_bytes):
        
        self.map()

        # get some info about the buffer we just mapped
        # NOTE: this used to be necessary to get the size of the copy, but now it is optional and just use it for sanity checking

        extent_tup = None
        if 'get_array_info' in device_interop_funcs:
            extent_tup = device_interop_funcs['get_array_info'](self.cuda_buffer_array)

        # access the input array
        arr_ptr, arr_shape, arr_dtype, arr_nbytes = device_interop_funcs['get_array_ptr'](arr)


        if self.buffer_type == psb.DeviceBufferType.texture2d:
           
            # if we got extent info from the destination array, use it to do additional sanity checks
            if extent_tup is not None:

                desc, extent, flags = extent_tup
                dst_buff_width = extent.width
                dst_buff_height = extent.height
                dst_buff_width_pad = 0

                dst_buff_bytes_per = (desc.x + desc.y + desc.z + desc.w) // 8
                dst_buff_width_in_bytes = dst_buff_width * dst_buff_bytes_per

                dst_n_cmp = (1 if desc.x > 0 else 0) + \
                            (1 if desc.y > 0 else 0) + \
                            (1 if desc.z > 0 else 0) + \
                            (1 if desc.w > 0 else 0)
            
                dst_n_elems = dst_buff_width*dst_buff_height*dst_n_cmp

                if extent.width != texture_dims[0]: raise ValueError(f"Mapped buffer width mismatch,  {extent.width} vs. {texture_dims[0]}.")
                if extent.height != texture_dims[1]: raise ValueError(f"Mapped buffer height mismatch,  {extent.height} vs. {texture_dims[1]}.")
                if extent.depth != texture_dims[2]: raise ValueError(f"Mapped buffer depth mismatch,  {extent.depth} vs. {texture_dims[2]}.")
                if dst_buff_bytes_per != entry_size_in_bytes : raise ValueError(f"Mapped buffer entry byte size mismatch,  {dst_buff_bytes_per} vs. {entry_size_in_bytes}.")
                    

            # if we got shape info from the source array, use it to do sanity checks
            if arr_shape is not None:
                # TODO this test is broken as-written, doesn't account for presence/asbsence of channel count
                pass

    #             # size of the input array
    #             arr_size = 1
    #             for s in arr_shape: arr_size *= s
    # 
    #             # size of the destination array
    #             dst_size = 1
    #             for s in texture_dims:
    #                 if s > 0: dst_size *= s
    #
    #             if arr_size != dst_size:
    #                 raise ValueError(f"Mapped buffer write has wrong size, destination buffer has {dst_size} elements, but source buffer has {arr_size}.")


            # if we got bytesize info from the source AND destination array, use it to do more sanity checks
            if arr_nbytes is not None and extent_tup is not None:
                expected_bytes = dst_buff_width * dst_buff_height * dst_buff_bytes_per
                if arr_nbytes != expected_bytes:
                    # if cupy_arr has the right size/dtype, it should have exactly the same 
                    # number of bytes as the destination. This is just lazily saving us 
                    # from repeating the math, and also directly validates the copy we 
                    # are about to do below.
                    raise ValueError(f"Mapped buffer write has wrong size, expected {arr_nbytes} bytes but got {expected_bytes} bytes. Could it be the wrong size/shape or wrong dtype?")


            device_interop_funcs['memcpy_2d'](
                    self.cuda_buffer_array, arr_ptr, texture_dims[0]*entry_size_in_bytes, texture_dims[1] 
                )

        else:
            raise ValueError("not implemented")

        self.unmap() 


