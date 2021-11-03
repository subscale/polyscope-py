#include <pybind11/eigen.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// #include "Eigen/Dense"

// #include "polyscope/polyscope.h"
// #include "polyscope/surface_mesh.h"

#include "polyscope/render/engine.h"
#include "polyscope/render/opengl/gl_engine.h"

// #include "utils.h"

namespace py = pybind11;
namespace ps = polyscope;

struct KeyCode {
    static const int KEY_SPACE = GLFW_KEY_SPACE;
    static const int KEY_APOSTROPHE = GLFW_KEY_APOSTROPHE;
    static const int KEY_COMMA = GLFW_KEY_COMMA;
    static const int KEY_MINUS = GLFW_KEY_MINUS;
    static const int KEY_PERIOD = GLFW_KEY_PERIOD;
    static const int KEY_SLASH = GLFW_KEY_SLASH;
    static const int KEY_0 = GLFW_KEY_0;
    static const int KEY_1 = GLFW_KEY_1;
    static const int KEY_2 = GLFW_KEY_2;
    static const int KEY_3 = GLFW_KEY_3;
    static const int KEY_4 = GLFW_KEY_4;
    static const int KEY_5 = GLFW_KEY_5;
    static const int KEY_6 = GLFW_KEY_6;
    static const int KEY_7 = GLFW_KEY_7;
    static const int KEY_8 = GLFW_KEY_8;
    static const int KEY_9 = GLFW_KEY_9;
    static const int KEY_SEMICOLON = GLFW_KEY_SEMICOLON;
    static const int KEY_EQUAL = GLFW_KEY_EQUAL;
    static const int KEY_A = GLFW_KEY_A;
    static const int KEY_B = GLFW_KEY_B;
    static const int KEY_C = GLFW_KEY_C;
    static const int KEY_D = GLFW_KEY_D;
    static const int KEY_E = GLFW_KEY_E;
    static const int KEY_F = GLFW_KEY_F;
    static const int KEY_G = GLFW_KEY_G;
    static const int KEY_H = GLFW_KEY_H;
    static const int KEY_I = GLFW_KEY_I;
    static const int KEY_J = GLFW_KEY_J;
    static const int KEY_K = GLFW_KEY_K;
    static const int KEY_L = GLFW_KEY_L;
    static const int KEY_M = GLFW_KEY_M;
    static const int KEY_N = GLFW_KEY_N;
    static const int KEY_O = GLFW_KEY_O;
    static const int KEY_P = GLFW_KEY_P;
    static const int KEY_Q = GLFW_KEY_Q;
    static const int KEY_R = GLFW_KEY_R;
    static const int KEY_S = GLFW_KEY_S;
    static const int KEY_T = GLFW_KEY_T;
    static const int KEY_U = GLFW_KEY_U;
    static const int KEY_V = GLFW_KEY_V;
    static const int KEY_W = GLFW_KEY_W;
    static const int KEY_X = GLFW_KEY_X;
    static const int KEY_Y = GLFW_KEY_Y;
    static const int KEY_Z = GLFW_KEY_Z;
    static const int KEY_LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET;
    static const int KEY_BACKSLASH = GLFW_KEY_BACKSLASH;
    static const int KEY_RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET;
    static const int KEY_GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT;
    static const int KEY_WORLD_1 = GLFW_KEY_WORLD_1;
    static const int KEY_WORLD_2 = GLFW_KEY_WORLD_2;
    static const int KEY_ESCAPE = GLFW_KEY_ESCAPE;
    static const int KEY_ENTER = GLFW_KEY_ENTER;
    static const int KEY_TAB = GLFW_KEY_TAB;
    static const int KEY_BACKSPACE = GLFW_KEY_BACKSPACE;
    static const int KEY_INSERT = GLFW_KEY_INSERT;
    static const int KEY_DELETE = GLFW_KEY_DELETE;
    static const int KEY_RIGHT = GLFW_KEY_RIGHT;
    static const int KEY_LEFT = GLFW_KEY_LEFT;
    static const int KEY_DOWN = GLFW_KEY_DOWN;
    static const int KEY_UP = GLFW_KEY_UP;
    static const int KEY_PAGE_UP = GLFW_KEY_PAGE_UP;
    static const int KEY_PAGE_DOWN = GLFW_KEY_PAGE_DOWN;
    static const int KEY_HOME = GLFW_KEY_HOME;
    static const int KEY_END = GLFW_KEY_END;
    static const int KEY_CAPS_LOCK = GLFW_KEY_CAPS_LOCK;
    static const int KEY_SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK;
    static const int KEY_NUM_LOCK = GLFW_KEY_NUM_LOCK;
    static const int KEY_PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN;
    static const int KEY_PAUSE = GLFW_KEY_PAUSE;
    static const int KEY_F1 = GLFW_KEY_F1;
    static const int KEY_F2 = GLFW_KEY_F2;
    static const int KEY_F3 = GLFW_KEY_F3;
    static const int KEY_F4 = GLFW_KEY_F4;
    static const int KEY_F5 = GLFW_KEY_F5;
    static const int KEY_F6 = GLFW_KEY_F6;
    static const int KEY_F7 = GLFW_KEY_F7;
    static const int KEY_F8 = GLFW_KEY_F8;
    static const int KEY_F9 = GLFW_KEY_F9;
    static const int KEY_F10 = GLFW_KEY_F10;
    static const int KEY_F11 = GLFW_KEY_F11;
    static const int KEY_F12 = GLFW_KEY_F12;
    static const int KEY_F13 = GLFW_KEY_F13;
    static const int KEY_F14 = GLFW_KEY_F14;
    static const int KEY_F15 = GLFW_KEY_F15;
    static const int KEY_F16 = GLFW_KEY_F16;
    static const int KEY_F17 = GLFW_KEY_F17;
    static const int KEY_F18 = GLFW_KEY_F18;
    static const int KEY_F19 = GLFW_KEY_F19;
    static const int KEY_F20 = GLFW_KEY_F20;
    static const int KEY_F21 = GLFW_KEY_F21;
    static const int KEY_F22 = GLFW_KEY_F22;
    static const int KEY_F23 = GLFW_KEY_F23;
    static const int KEY_F24 = GLFW_KEY_F24;
    static const int KEY_F25 = GLFW_KEY_F25;
    static const int KEY_KP_0 = GLFW_KEY_KP_0;
    static const int KEY_KP_1 = GLFW_KEY_KP_1;
    static const int KEY_KP_2 = GLFW_KEY_KP_2;
    static const int KEY_KP_3 = GLFW_KEY_KP_3;
    static const int KEY_KP_4 = GLFW_KEY_KP_4;
    static const int KEY_KP_5 = GLFW_KEY_KP_5;
    static const int KEY_KP_6 = GLFW_KEY_KP_6;
    static const int KEY_KP_7 = GLFW_KEY_KP_7;
    static const int KEY_KP_8 = GLFW_KEY_KP_8;
    static const int KEY_KP_9 = GLFW_KEY_KP_9;
    static const int KEY_KP_DECIMAL = GLFW_KEY_KP_DECIMAL;
    static const int KEY_KP_DIVIDE = GLFW_KEY_KP_DIVIDE;
    static const int KEY_KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY;
    static const int KEY_KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT;
    static const int KEY_KP_ADD = GLFW_KEY_KP_ADD;
    static const int KEY_KP_ENTER = GLFW_KEY_KP_ENTER;
    static const int KEY_KP_EQUAL = GLFW_KEY_KP_EQUAL;
    static const int KEY_LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT;
    static const int KEY_LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL;
    static const int KEY_LEFT_ALT = GLFW_KEY_LEFT_ALT;
    static const int KEY_LEFT_SUPER = GLFW_KEY_LEFT_SUPER;
    static const int KEY_RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT;
    static const int KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;
    static const int KEY_RIGHT_ALT = GLFW_KEY_RIGHT_ALT;
    static const int KEY_RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER;
    static const int KEY_MENU = GLFW_KEY_MENU;
};

struct pyImGuiCond {
};
struct pyImGuiStyleVar {
};
struct pyImGuiTreeNodeFlags {
};
struct pyImGuiColorEditFlags {
};

using Vec2T = std::tuple<float, float>;
using Vec4T = std::tuple<float, float, float, float>;

ImVec2 to_vec2(const Vec2T& v) { return ImVec2(std::get<0>(v), std::get<1>(v)); }
ImVec4 to_vec4(const Vec4T& v)
{
    return ImVec4(std::get<0>(v), std::get<1>(v), std::get<2>(v), std::get<3>(v));
}

Vec2T from_vec2(const ImVec2& v) { return std::make_tuple(v.x, v.y); }
Vec4T from_vec4(const ImVec4& v) { return std::make_tuple(v.x, v.y, v.z, v.w); }

struct InputTextCallback_UserData {
    std::string* str;
    ImGuiInputTextCallback chain_callback;
    void* chain_callback_user_data;
};

static int input_text_callback(ImGuiInputTextCallbackData* data)
{
    auto* user_data = reinterpret_cast<InputTextCallback_UserData*>(data->UserData);
    if (data->EventFlag == ImGuiInputTextFlags_CallbackResize) {
        // Resize string callback
        // If for some reason we refuse the new length (BufTextLen) and/or capacity (BufSize) we
        // need to set them back to what we want.
        auto* str = user_data->str;
        IM_ASSERT(data->Buf == str->c_str());
        str->resize(data->BufTextLen);
        data->Buf = (char*)str->c_str();
    }
    else if (user_data->chain_callback) {
        // Forward to user callback, if any
        data->UserData = user_data->chain_callback_user_data;
        return user_data->chain_callback(data);
    }
    return 0;
}

void bind_imgui(py::module& m)
{
    m.def("is_key_pressed", [](char c) { return ps::render::engine->isKeyPressed(c); });
    m.def("is_key_code_pressed", [](ImGuiKey code) { return ImGui::IsKeyPressed(code); });

    py::class_<KeyCode>(m, "KeyCode")
        .def_property_readonly_static("KEY_SPACE",
                                      [](py::object /* self */) { return KeyCode::KEY_SPACE; })
        .def_property_readonly_static("KEY_APOSTROPHE",
                                      [](py::object /* self */) { return KeyCode::KEY_APOSTROPHE; })
        .def_property_readonly_static("KEY_COMMA",
                                      [](py::object /* self */) { return KeyCode::KEY_COMMA; })
        .def_property_readonly_static("KEY_MINUS",
                                      [](py::object /* self */) { return KeyCode::KEY_MINUS; })
        .def_property_readonly_static("KEY_PERIOD",
                                      [](py::object /* self */) { return KeyCode::KEY_PERIOD; })
        .def_property_readonly_static("KEY_SLASH",
                                      [](py::object /* self */) { return KeyCode::KEY_SLASH; })
        .def_property_readonly_static("KEY_0", [](py::object /* self */) { return KeyCode::KEY_0; })
        .def_property_readonly_static("KEY_1", [](py::object /* self */) { return KeyCode::KEY_1; })
        .def_property_readonly_static("KEY_2", [](py::object /* self */) { return KeyCode::KEY_2; })
        .def_property_readonly_static("KEY_3", [](py::object /* self */) { return KeyCode::KEY_3; })
        .def_property_readonly_static("KEY_4", [](py::object /* self */) { return KeyCode::KEY_4; })
        .def_property_readonly_static("KEY_5", [](py::object /* self */) { return KeyCode::KEY_5; })
        .def_property_readonly_static("KEY_6", [](py::object /* self */) { return KeyCode::KEY_6; })
        .def_property_readonly_static("KEY_7", [](py::object /* self */) { return KeyCode::KEY_7; })
        .def_property_readonly_static("KEY_8", [](py::object /* self */) { return KeyCode::KEY_8; })
        .def_property_readonly_static("KEY_9", [](py::object /* self */) { return KeyCode::KEY_9; })
        .def_property_readonly_static("KEY_SEMICOLON",
                                      [](py::object /* self */) { return KeyCode::KEY_SEMICOLON; })
        .def_property_readonly_static("KEY_EQUAL",
                                      [](py::object /* self */) { return KeyCode::KEY_EQUAL; })
        .def_property_readonly_static("KEY_A", [](py::object /* self */) { return KeyCode::KEY_A; })
        .def_property_readonly_static("KEY_B", [](py::object /* self */) { return KeyCode::KEY_B; })
        .def_property_readonly_static("KEY_C", [](py::object /* self */) { return KeyCode::KEY_C; })
        .def_property_readonly_static("KEY_D", [](py::object /* self */) { return KeyCode::KEY_D; })
        .def_property_readonly_static("KEY_E", [](py::object /* self */) { return KeyCode::KEY_E; })
        .def_property_readonly_static("KEY_F", [](py::object /* self */) { return KeyCode::KEY_F; })
        .def_property_readonly_static("KEY_G", [](py::object /* self */) { return KeyCode::KEY_G; })
        .def_property_readonly_static("KEY_H", [](py::object /* self */) { return KeyCode::KEY_H; })
        .def_property_readonly_static("KEY_I", [](py::object /* self */) { return KeyCode::KEY_I; })
        .def_property_readonly_static("KEY_J", [](py::object /* self */) { return KeyCode::KEY_J; })
        .def_property_readonly_static("KEY_K", [](py::object /* self */) { return KeyCode::KEY_K; })
        .def_property_readonly_static("KEY_L", [](py::object /* self */) { return KeyCode::KEY_L; })
        .def_property_readonly_static("KEY_M", [](py::object /* self */) { return KeyCode::KEY_M; })
        .def_property_readonly_static("KEY_N", [](py::object /* self */) { return KeyCode::KEY_N; })
        .def_property_readonly_static("KEY_O", [](py::object /* self */) { return KeyCode::KEY_O; })
        .def_property_readonly_static("KEY_P", [](py::object /* self */) { return KeyCode::KEY_P; })
        .def_property_readonly_static("KEY_Q", [](py::object /* self */) { return KeyCode::KEY_Q; })
        .def_property_readonly_static("KEY_R", [](py::object /* self */) { return KeyCode::KEY_R; })
        .def_property_readonly_static("KEY_S", [](py::object /* self */) { return KeyCode::KEY_S; })
        .def_property_readonly_static("KEY_T", [](py::object /* self */) { return KeyCode::KEY_T; })
        .def_property_readonly_static("KEY_U", [](py::object /* self */) { return KeyCode::KEY_U; })
        .def_property_readonly_static("KEY_V", [](py::object /* self */) { return KeyCode::KEY_V; })
        .def_property_readonly_static("KEY_W", [](py::object /* self */) { return KeyCode::KEY_W; })
        .def_property_readonly_static("KEY_X", [](py::object /* self */) { return KeyCode::KEY_X; })
        .def_property_readonly_static("KEY_Y", [](py::object /* self */) { return KeyCode::KEY_Y; })
        .def_property_readonly_static("KEY_Z", [](py::object /* self */) { return KeyCode::KEY_Z; })
        .def_property_readonly_static(
            "KEY_LEFT_BRACKET", [](py::object /* self */) { return KeyCode::KEY_LEFT_BRACKET; })
        .def_property_readonly_static("KEY_BACKSLASH",
                                      [](py::object /* self */) { return KeyCode::KEY_BACKSLASH; })
        .def_property_readonly_static(
            "KEY_RIGHT_BRACKET", [](py::object /* self */) { return KeyCode::KEY_RIGHT_BRACKET; })
        .def_property_readonly_static(
            "KEY_GRAVE_ACCENT", [](py::object /* self */) { return KeyCode::KEY_GRAVE_ACCENT; })
        .def_property_readonly_static("KEY_WORLD_1",
                                      [](py::object /* self */) { return KeyCode::KEY_WORLD_1; })
        .def_property_readonly_static("KEY_WORLD_2",
                                      [](py::object /* self */) { return KeyCode::KEY_WORLD_2; })
        .def_property_readonly_static("KEY_ESCAPE",
                                      [](py::object /* self */) { return KeyCode::KEY_ESCAPE; })
        .def_property_readonly_static("KEY_ENTER",
                                      [](py::object /* self */) { return KeyCode::KEY_ENTER; })
        .def_property_readonly_static("KEY_TAB",
                                      [](py::object /* self */) { return KeyCode::KEY_TAB; })
        .def_property_readonly_static("KEY_BACKSPACE",
                                      [](py::object /* self */) { return KeyCode::KEY_BACKSPACE; })
        .def_property_readonly_static("KEY_INSERT",
                                      [](py::object /* self */) { return KeyCode::KEY_INSERT; })
        .def_property_readonly_static("KEY_DELETE",
                                      [](py::object /* self */) { return KeyCode::KEY_DELETE; })
        .def_property_readonly_static("KEY_RIGHT",
                                      [](py::object /* self */) { return KeyCode::KEY_RIGHT; })
        .def_property_readonly_static("KEY_LEFT",
                                      [](py::object /* self */) { return KeyCode::KEY_LEFT; })
        .def_property_readonly_static("KEY_DOWN",
                                      [](py::object /* self */) { return KeyCode::KEY_DOWN; })
        .def_property_readonly_static("KEY_UP",
                                      [](py::object /* self */) { return KeyCode::KEY_UP; })
        .def_property_readonly_static("KEY_PAGE_UP",
                                      [](py::object /* self */) { return KeyCode::KEY_PAGE_UP; })
        .def_property_readonly_static("KEY_PAGE_DOWN",
                                      [](py::object /* self */) { return KeyCode::KEY_PAGE_DOWN; })
        .def_property_readonly_static("KEY_HOME",
                                      [](py::object /* self */) { return KeyCode::KEY_HOME; })
        .def_property_readonly_static("KEY_END",
                                      [](py::object /* self */) { return KeyCode::KEY_END; })
        .def_property_readonly_static("KEY_CAPS_LOCK",
                                      [](py::object /* self */) { return KeyCode::KEY_CAPS_LOCK; })
        .def_property_readonly_static(
            "KEY_SCROLL_LOCK", [](py::object /* self */) { return KeyCode::KEY_SCROLL_LOCK; })
        .def_property_readonly_static("KEY_NUM_LOCK",
                                      [](py::object /* self */) { return KeyCode::KEY_NUM_LOCK; })
        .def_property_readonly_static(
            "KEY_PRINT_SCREEN", [](py::object /* self */) { return KeyCode::KEY_PRINT_SCREEN; })
        .def_property_readonly_static("KEY_PAUSE",
                                      [](py::object /* self */) { return KeyCode::KEY_PAUSE; })
        .def_property_readonly_static("KEY_F1",
                                      [](py::object /* self */) { return KeyCode::KEY_F1; })
        .def_property_readonly_static("KEY_F2",
                                      [](py::object /* self */) { return KeyCode::KEY_F2; })
        .def_property_readonly_static("KEY_F3",
                                      [](py::object /* self */) { return KeyCode::KEY_F3; })
        .def_property_readonly_static("KEY_F4",
                                      [](py::object /* self */) { return KeyCode::KEY_F4; })
        .def_property_readonly_static("KEY_F5",
                                      [](py::object /* self */) { return KeyCode::KEY_F5; })
        .def_property_readonly_static("KEY_F6",
                                      [](py::object /* self */) { return KeyCode::KEY_F6; })
        .def_property_readonly_static("KEY_F7",
                                      [](py::object /* self */) { return KeyCode::KEY_F7; })
        .def_property_readonly_static("KEY_F8",
                                      [](py::object /* self */) { return KeyCode::KEY_F8; })
        .def_property_readonly_static("KEY_F9",
                                      [](py::object /* self */) { return KeyCode::KEY_F9; })
        .def_property_readonly_static("KEY_F10",
                                      [](py::object /* self */) { return KeyCode::KEY_F10; })
        .def_property_readonly_static("KEY_F11",
                                      [](py::object /* self */) { return KeyCode::KEY_F11; })
        .def_property_readonly_static("KEY_F12",
                                      [](py::object /* self */) { return KeyCode::KEY_F12; })
        .def_property_readonly_static("KEY_F13",
                                      [](py::object /* self */) { return KeyCode::KEY_F13; })
        .def_property_readonly_static("KEY_F14",
                                      [](py::object /* self */) { return KeyCode::KEY_F14; })
        .def_property_readonly_static("KEY_F15",
                                      [](py::object /* self */) { return KeyCode::KEY_F15; })
        .def_property_readonly_static("KEY_F16",
                                      [](py::object /* self */) { return KeyCode::KEY_F16; })
        .def_property_readonly_static("KEY_F17",
                                      [](py::object /* self */) { return KeyCode::KEY_F17; })
        .def_property_readonly_static("KEY_F18",
                                      [](py::object /* self */) { return KeyCode::KEY_F18; })
        .def_property_readonly_static("KEY_F19",
                                      [](py::object /* self */) { return KeyCode::KEY_F19; })
        .def_property_readonly_static("KEY_F20",
                                      [](py::object /* self */) { return KeyCode::KEY_F20; })
        .def_property_readonly_static("KEY_F21",
                                      [](py::object /* self */) { return KeyCode::KEY_F21; })
        .def_property_readonly_static("KEY_F22",
                                      [](py::object /* self */) { return KeyCode::KEY_F22; })
        .def_property_readonly_static("KEY_F23",
                                      [](py::object /* self */) { return KeyCode::KEY_F23; })
        .def_property_readonly_static("KEY_F24",
                                      [](py::object /* self */) { return KeyCode::KEY_F24; })
        .def_property_readonly_static("KEY_F25",
                                      [](py::object /* self */) { return KeyCode::KEY_F25; })
        .def_property_readonly_static("KEY_KP_0",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_0; })
        .def_property_readonly_static("KEY_KP_1",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_1; })
        .def_property_readonly_static("KEY_KP_2",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_2; })
        .def_property_readonly_static("KEY_KP_3",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_3; })
        .def_property_readonly_static("KEY_KP_4",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_4; })
        .def_property_readonly_static("KEY_KP_5",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_5; })
        .def_property_readonly_static("KEY_KP_6",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_6; })
        .def_property_readonly_static("KEY_KP_7",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_7; })
        .def_property_readonly_static("KEY_KP_8",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_8; })
        .def_property_readonly_static("KEY_KP_9",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_9; })
        .def_property_readonly_static("KEY_KP_DECIMAL",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_DECIMAL; })
        .def_property_readonly_static("KEY_KP_DIVIDE",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_DIVIDE; })
        .def_property_readonly_static(
            "KEY_KP_MULTIPLY", [](py::object /* self */) { return KeyCode::KEY_KP_MULTIPLY; })
        .def_property_readonly_static(
            "KEY_KP_SUBTRACT", [](py::object /* self */) { return KeyCode::KEY_KP_SUBTRACT; })
        .def_property_readonly_static("KEY_KP_ADD",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_ADD; })
        .def_property_readonly_static("KEY_KP_ENTER",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_ENTER; })
        .def_property_readonly_static("KEY_KP_EQUAL",
                                      [](py::object /* self */) { return KeyCode::KEY_KP_EQUAL; })
        .def_property_readonly_static("KEY_LEFT_SHIFT",
                                      [](py::object /* self */) { return KeyCode::KEY_LEFT_SHIFT; })
        .def_property_readonly_static(
            "KEY_LEFT_CONTROL", [](py::object /* self */) { return KeyCode::KEY_LEFT_CONTROL; })
        .def_property_readonly_static("KEY_LEFT_ALT",
                                      [](py::object /* self */) { return KeyCode::KEY_LEFT_ALT; })
        .def_property_readonly_static("KEY_LEFT_SUPER",
                                      [](py::object /* self */) { return KeyCode::KEY_LEFT_SUPER; })
        .def_property_readonly_static(
            "KEY_RIGHT_SHIFT", [](py::object /* self */) { return KeyCode::KEY_RIGHT_SHIFT; })
        .def_property_readonly_static(
            "KEY_RIGHT_CONTROL", [](py::object /* self */) { return KeyCode::KEY_RIGHT_CONTROL; })
        .def_property_readonly_static("KEY_RIGHT_ALT",
                                      [](py::object /* self */) { return KeyCode::KEY_RIGHT_ALT; })
        .def_property_readonly_static(
            "KEY_RIGHT_SUPER", [](py::object /* self */) { return KeyCode::KEY_RIGHT_SUPER; })
        .def_property_readonly_static("KEY_MENU",
                                      [](py::object /* self */) { return KeyCode::KEY_MENU; });

    py::class_<pyImGuiCond>(m, "ImGuiCond")
        .def_property_readonly_static(
            "ImGuiCond_Always",
            [](py::object /* self */) { return static_cast<int>(ImGuiCond_Always); })
        .def_property_readonly_static(
            "ImGuiCond_Once",
            [](py::object /* self */) { return static_cast<int>(ImGuiCond_Once); })
        .def_property_readonly_static(
            "ImGuiCond_FirstUseEver",
            [](py::object /* self */) { return static_cast<int>(ImGuiCond_FirstUseEver); })
        .def_property_readonly_static("ImGuiCond_Appearing", [](py::object /* self */) {
            return static_cast<int>(ImGuiCond_Appearing);
        });

    py::class_<pyImGuiStyleVar>(m, "ImGuiStyleVar")
        .def_property_readonly_static(
            "ImGuiStyleVar_Alpha",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_Alpha); })
        .def_property_readonly_static(
            "ImGuiStyleVar_WindowPadding",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_WindowPadding); })
        .def_property_readonly_static(
            "ImGuiStyleVar_WindowRounding",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_WindowRounding); })
        .def_property_readonly_static(
            "ImGuiStyleVar_WindowBorderSize",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_WindowBorderSize); })
        .def_property_readonly_static(
            "ImGuiStyleVar_WindowMinSize",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_WindowMinSize); })
        .def_property_readonly_static(
            "ImGuiStyleVar_WindowTitleAlign",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_WindowTitleAlign); })
        .def_property_readonly_static(
            "ImGuiStyleVar_ChildRounding",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_ChildRounding); })
        .def_property_readonly_static(
            "ImGuiStyleVar_ChildBorderSize",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_ChildBorderSize); })
        .def_property_readonly_static(
            "ImGuiStyleVar_PopupRounding",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_PopupRounding); })
        .def_property_readonly_static(
            "ImGuiStyleVar_PopupBorderSize",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_PopupBorderSize); })
        .def_property_readonly_static(
            "ImGuiStyleVar_FramePadding",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_FramePadding); })
        .def_property_readonly_static(
            "ImGuiStyleVar_FrameRounding",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_FrameRounding); })
        .def_property_readonly_static(
            "ImGuiStyleVar_FrameBorderSize",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_FrameBorderSize); })
        .def_property_readonly_static(
            "ImGuiStyleVar_ItemSpacing",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_ItemSpacing); })
        .def_property_readonly_static(
            "ImGuiStyleVar_ItemInnerSpacing",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_ItemInnerSpacing); })
        .def_property_readonly_static(
            "ImGuiStyleVar_IndentSpacing",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_IndentSpacing); })
        .def_property_readonly_static(
            "ImGuiStyleVar_ScrollbarSize",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_ScrollbarSize); })
        .def_property_readonly_static(
            "ImGuiStyleVar_ScrollbarRounding",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_ScrollbarRounding); })
        .def_property_readonly_static(
            "ImGuiStyleVar_GrabMinSize",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_GrabMinSize); })
        .def_property_readonly_static(
            "ImGuiStyleVar_GrabRounding",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_GrabRounding); })
        .def_property_readonly_static(
            "ImGuiStyleVar_TabRounding",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_TabRounding); })
        .def_property_readonly_static(
            "ImGuiStyleVar_ButtonTextAlign",
            [](py::object /* self */) { return static_cast<int>(ImGuiStyleVar_ButtonTextAlign); })
        .def_property_readonly_static(
            "ImGuiStyleVar_SelectableTextAlign", [](py::object /* self */) {
                return static_cast<int>(ImGuiStyleVar_SelectableTextAlign);
            });

    py::class_<pyImGuiTreeNodeFlags>(m, "ImGuiTreeNodeFlags")
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_None",
            [](py::object /* self */) { return static_cast<int>(ImGuiTreeNodeFlags_None); })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_Selected",
            [](py::object /* self */) { return static_cast<int>(ImGuiTreeNodeFlags_Selected); })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_Framed",
            [](py::object /* self */) { return static_cast<int>(ImGuiTreeNodeFlags_Framed); })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_AllowItemOverlap",
            [](py::object /* self */) {
                return static_cast<int>(ImGuiTreeNodeFlags_AllowItemOverlap);
            })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_NoTreePushOnOpen",
            [](py::object /* self */) {
                return static_cast<int>(ImGuiTreeNodeFlags_NoTreePushOnOpen);
            })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_NoAutoOpenOnLog",
            [](py::object /* self */) {
                return static_cast<int>(ImGuiTreeNodeFlags_NoAutoOpenOnLog);
            })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_DefaultOpen",
            [](py::object /* self */) { return static_cast<int>(ImGuiTreeNodeFlags_DefaultOpen); })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_OpenOnDoubleClick",
            [](py::object /* self */) {
                return static_cast<int>(ImGuiTreeNodeFlags_OpenOnDoubleClick);
            })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_OpenOnArrow",
            [](py::object /* self */) { return static_cast<int>(ImGuiTreeNodeFlags_OpenOnArrow); })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_Leaf",
            [](py::object /* self */) { return static_cast<int>(ImGuiTreeNodeFlags_Leaf); })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_Bullet",
            [](py::object /* self */) { return static_cast<int>(ImGuiTreeNodeFlags_Bullet); })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_FramePadding",
            [](py::object /* self */) { return static_cast<int>(ImGuiTreeNodeFlags_FramePadding); })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_SpanAvailWidth",
            [](py::object /* self */) {
                return static_cast<int>(ImGuiTreeNodeFlags_SpanAvailWidth);
            })
        .def_property_readonly_static("ImGuiTreeNodeFlags_SpanFullWidth",
                                      [](py::object /* self */) {
                                          return static_cast<int>(ImGuiTreeNodeFlags_SpanFullWidth);
                                      })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_NavLeftJumpsBackHere",
            [](py::object /* self */) {
                return static_cast<int>(ImGuiTreeNodeFlags_NavLeftJumpsBackHere);
            })
        .def_property_readonly_static(
            "ImGuiTreeNodeFlags_CollapsingHeader", [](py::object /* self */) {
                return static_cast<int>(ImGuiTreeNodeFlags_CollapsingHeader);
            });

    py::class_<pyImGuiColorEditFlags>(m, "ImGuiColorEditFlags")
        .def_property_readonly_static(
            "ImGuiColorEditFlags_None",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_None); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_NoAlpha",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_NoAlpha); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_NoPicker",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_NoPicker); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_NoOptions",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_NoOptions); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_NoSmallPreview",
            [](py::object /* self */) {
                return static_cast<int>(ImGuiColorEditFlags_NoSmallPreview);
            })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_NoInputs",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_NoInputs); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_NoTooltip",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_NoTooltip); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_NoLabel",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_NoLabel); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_NoSidePreview",
            [](py::object /* self */) {
                return static_cast<int>(ImGuiColorEditFlags_NoSidePreview);
            })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_NoDragDrop",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_NoDragDrop); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_NoBorder",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_NoBorder); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_AlphaBar",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_AlphaBar); })
        .def_property_readonly_static("ImGuiColorEditFlags_AlphaPreview",
                                      [](py::object /* self */) {
                                          return static_cast<int>(ImGuiColorEditFlags_AlphaPreview);
                                      })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_AlphaPreviewHalf",
            [](py::object /* self */) {
                return static_cast<int>(ImGuiColorEditFlags_AlphaPreviewHalf);
            })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_HDR",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_HDR); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_DisplayRGB",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_DisplayRGB); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_DisplayHSV",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_DisplayHSV); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_DisplayHex",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_DisplayHex); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_Uint8",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_Uint8); })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_Float",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_Float); })
        .def_property_readonly_static("ImGuiColorEditFlags_PickerHueBar",
                                      [](py::object /* self */) {
                                          return static_cast<int>(ImGuiColorEditFlags_PickerHueBar);
                                      })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_PickerHueWheel",
            [](py::object /* self */) {
                return static_cast<int>(ImGuiColorEditFlags_PickerHueWheel);
            })
        .def_property_readonly_static(
            "ImGuiColorEditFlags_InputRGB",
            [](py::object /* self */) { return static_cast<int>(ImGuiColorEditFlags_InputRGB); })
        .def_property_readonly_static("ImGuiColorEditFlags_InputHSV", [](py::object /* self */) {
            return static_cast<int>(ImGuiColorEditFlags_InputHSV);
        });

    // Parameters stacks (shared)
    // m.def("push_font")
    // m.def("pop_font")
    m.def(
        "push_style_color",
        [](ImGuiCol idx, ImU32 col) { ImGui::PushStyleColor(idx, col); },
        py::arg("idx"),
        py::arg("col"));
    m.def(
        "push_style_color",
        [](ImGuiCol idx, const Vec4T& col) { ImGui::PushStyleColor(idx, to_vec4(col)); },
        py::arg("idx"),
        py::arg("col"));
    m.def(
        "pop_style_color", [](int count) { ImGui::PopStyleColor(count); }, py::arg("count") = 1);
    m.def(
        "push_style_var",
        [](ImGuiCol idx, float val) { ImGui::PushStyleVar(idx, val); },
        py::arg("idx"),
        py::arg("val"));
    m.def(
        "push_style_var",
        [](ImGuiCol idx, const Vec2T& val) { ImGui::PushStyleVar(idx, to_vec2(val)); },
        py::arg("idx"),
        py::arg("val"));
    m.def(
        "pop_style_var", [](int count) { ImGui::PopStyleVar(count); }, py::arg("count") = 1);
    m.def(
        "get_style_color_vec4",
        [](ImGuiCol idx) { return from_vec4(ImGui::GetStyleColorVec4(idx)); },
        py::arg("idx"));
    // GetFont
    m.def("get_font_size", []() { return ImGui::GetFontSize(); });
    m.def("get_font_tex_uv_white_pixel",
          []() { return from_vec2(ImGui::GetFontTexUvWhitePixel()); });
    m.def(
        "get_color_u32",
        [](ImGuiCol idx, float alpha_mul) { return ImGui::GetColorU32(idx, alpha_mul); },
        py::arg("idx"),
        py::arg("alpha_mul") = 1.0f);
    m.def(
        "get_color_u32", [](const ImVec4& col) { return ImGui::GetColorU32(col); }, py::arg("col"));
    m.def(
        "get_color_u32", [](ImU32 col) { return ImGui::GetColorU32(col); }, py::arg("col"));

    // Cursor / Layout
    m.def("separator", []() { ImGui::Separator(); });
    m.def(
        "same_line",
        [](float offset_from_start_x, float spacing) { ImGui::SameLine(); },
        py::arg("offset_from_start_x") = 0.0f,
        py::arg("offset") = -1.0f);
    m.def("new_line", []() { ImGui::NewLine(); });
    m.def("spacing", []() { ImGui::Spacing(); });
    m.def("dummy", [](const Vec2T& size) { ImGui::Dummy(to_vec2(size)); });
    m.def(
        "indent", [](float indent_w) { ImGui::Indent(indent_w); }, py::arg("indent_w") = 0.f);
    m.def(
        "unindent", [](float indent_w) { ImGui::Unindent(indent_w); }, py::arg("indent_w") = 0.f);
    m.def("begin_group", []() { ImGui::BeginGroup(); });
    m.def("end_group", []() { ImGui::EndGroup(); });
    m.def("get_cursor_pos", []() { return from_vec2(ImGui::GetCursorPos()); });
    m.def("get_cursor_pos_x", []() { return ImGui::GetCursorPosX(); });
    m.def("get_cursor_pos_y", []() { return ImGui::GetCursorPosY(); });
    m.def(
        "set_cursor_pos",
        [](const Vec2T& local_pos) { return ImGui::SetCursorPos(to_vec2(local_pos)); },
        py::arg("local_pos"));
    m.def(
        "set_cursor_pos_x",
        [](float local_x) { return ImGui::SetCursorPosX(local_x); },
        py::arg("local_x"));
    m.def(
        "set_cursor_pos_y",
        [](float local_y) { return ImGui::SetCursorPosY(local_y); },
        py::arg("local_y"));
    m.def("get_cursor_start_pos", []() { return from_vec2(ImGui::GetCursorStartPos()); });
    m.def("get_cursor_screen_pos", []() { return from_vec2(ImGui::GetCursorScreenPos()); });
    m.def(
        "set_cursor_screen_pos",
        [](const Vec2T& pos) { return ImGui::SetCursorScreenPos(to_vec2(pos)); },
        py::arg("pos"));
    m.def("align_text_to_frame_padding", []() { ImGui::AlignTextToFramePadding(); });
    m.def("get_text_line_height", []() { ImGui::GetTextLineHeight(); });
    m.def("get_text_line_height_with_spacing", []() { ImGui::GetTextLineHeightWithSpacing(); });
    m.def("get_frame_height", []() { ImGui::GetFrameHeight(); });
    m.def("get_frame_height_with_spacing", []() { ImGui::GetFrameHeightWithSpacing(); });

    // Parameters stacks (current window)
    m.def(
        "push_item_width",
        [](float item_width) { ImGui::PushItemWidth(item_width); },
        py::arg("item_width"));
    m.def("pop_item_width", []() { ImGui::PopItemWidth(); });
    m.def(
        "push_item_width",
        [](float item_width) { ImGui::SetNextItemWidth(item_width); },
        py::arg("item_width"));
    m.def("calc_item_width", []() { return ImGui::CalcItemWidth(); });
    m.def(
        "push_text_wrap_pos",
        [](float wrap_local_pos_x) { ImGui::PushTextWrapPos(wrap_local_pos_x); },
        py::arg("wrap_local_pos_x") = 0.0f);
    m.def("pop_text_wrap_pos", []() { return ImGui::PopTextWrapPos(); });
    m.def(
        "push_allow_keyboard_focus",
        [](bool allow_keyboard_focus) { ImGui::PushAllowKeyboardFocus(allow_keyboard_focus); },
        py::arg("allow_keyboard_focus"));
    m.def("pop_allow_keyboard_focus", []() { return ImGui::PopAllowKeyboardFocus(); });
    m.def(
        "push_button_repeat",
        [](bool repeat) { ImGui::PushButtonRepeat(repeat); },
        py::arg("allow_keyboard_focus"));
    m.def("pop_button_repeat", []() { return ImGui::PopButtonRepeat(); });

    // ID stack/scopes
    m.def(
        "push_id", [](const char* str_id) { ImGui::PushID(str_id); }, py::arg("str_id"));
    m.def("pop_id", []() { ImGui::PopID(); });
    m.def(
        "get_id", [](const char* str_id) { ImGui::GetID(str_id); }, py::arg("str_id"));

    // Widgets: Text
    m.def(
        "text", [](const char* fmt) { ImGui::Text("%s", fmt); }, py::arg("text"));
    m.def(
        "text_colored",
        [](const Vec4T& color, const char* fmt) { ImGui::TextColored(to_vec4(color), "%s", fmt); },
        py::arg("color"),
        py::arg("text"));
    m.def(
        "text_disabled", [](const char* fmt) { ImGui::TextDisabled("%s", fmt); }, py::arg("text"));
    m.def(
        "text_wrapped", [](const char* fmt) { ImGui::TextWrapped("%s", fmt); }, py::arg("text"));
    m.def(
        "label_text",
        [](const char* label, const char* fmt) { ImGui::LabelText(label, "%s", fmt); },
        py::arg("label"),
        py::arg("text"));
    m.def(
        "bullet_text",
        [](const char* label, const char* fmt) { ImGui::BulletText(label, "%s", fmt); },
        py::arg("label"),
        py::arg("text"));

    // Widgets: Main
    m.def(
        "button",
        [](const char* label, const Vec2T& size) { return ImGui::Button(label, to_vec2(size)); },
        py::arg("label"),
        py::arg("size") = std::make_tuple(0.f, 0.f));
    m.def(
        "small_button",
        [](const char* label) { return ImGui::SmallButton(label); },
        py::arg("label"));
    m.def(
        "invisible_button",
        [](const char* str_id, const Vec2T& size) {
            return ImGui::InvisibleButton(str_id, to_vec2(size));
        },
        py::arg("str_id"),
        py::arg("size"));
    m.def(
        "arrow_button",
        [](const char* str_id, ImGuiDir dir) { return ImGui::ArrowButton(str_id, dir); },
        py::arg("str_id"),
        py::arg("dir"));
    // Image
    // ImageButton
    m.def(
        "checkbox",
        [](const char* label, bool v) {
            auto v_ = v;
            const auto clicked = ImGui::Checkbox(label, &v_);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"));
    m.def(
        "checkbox_flags",
        [](const char* label, unsigned int flags, unsigned int flags_value) {
            auto flags_ = flags;
            const auto clicked = ImGui::CheckboxFlags(label, &flags_, flags_value);
            return std::make_tuple(clicked, flags_);
        },
        py::arg("label"),
        py::arg("flags"),
        py::arg("flags_value"));
    m.def(
        "radio_button",
        [](const char* label, bool active) { return ImGui::RadioButton(label, active); },
        py::arg("label"),
        py::arg("active"));
    m.def(
        "radio_button",
        [](const char* label, unsigned int v, unsigned int v_button) {
            auto v_ = v;
            const auto clicked = ImGui::CheckboxFlags(label, &v_, v_button);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_button"));
    m.def(
        "progress_bar",
        [](float fraction, const Vec2T& size_arg) {
            ImGui::ProgressBar(fraction, to_vec2(size_arg));
        },
        py::arg("fraction"),
        py::arg("size_arg") = std::make_tuple(-1.f, 0.f));
    m.def("bullet", []() { ImGui::Bullet(); });

    // Widgets: Combo Box
    m.def(
        "begin_combo",
        [](const char* label, const char* preview_value, ImGuiComboFlags flags) {
            return ImGui::BeginCombo(label, preview_value, flags);
        },
        py::arg("label"),
        py::arg("preview_value"),
        py::arg("flags"));
    m.def("end_combo", []() { ImGui::EndCombo(); });
    m.def(
        "combo",
        [](const char* label,
           int current_item,
           const std::vector<const char*>& items,
           int popup_max_height_in_items) {
            auto current_item_ = current_item;
            const auto clicked = ImGui::Combo(
                label, &current_item_, items.data(), items.size(), popup_max_height_in_items);
            return std::make_tuple(clicked, current_item_);
        },
        py::arg("label"),
        py::arg("current_item"),
        py::arg("items"),
        py::arg("popup_max_height_in_items") = -1);
    m.def(
        "combo",
        [](const char* label,
           int current_item,
           const char* items_separated_by_zeros,

           int popup_max_height_in_items) {
            auto current_item_ = current_item;
            const auto clicked = ImGui::Combo(
                label, &current_item_, items_separated_by_zeros, popup_max_height_in_items);
            return std::make_tuple(clicked, current_item_);
        },
        py::arg("label"),
        py::arg("current_item"),
        py::arg("items_separated_by_zeros"),
        py::arg("popup_max_height_in_items") = -1);

    // Widgets: Drags
    m.def(
        "drag_float",
        [](const char* label,
           float v,
           float v_speed,
           float v_min,
           float v_max,
           const char* format,
           float power) {
            auto v_ = v;
            auto clicked = ImGui::DragFloat(label, &v_, v_speed, v_min, v_max, format, power);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_speed") = 1.0f,
        py::arg("v_min") = 0.0f,
        py::arg("v_max") = 0.0f,
        py::arg("format") = "%.3f",
        py::arg("power") = 1.0f);
    m.def(
        "drag_float2",
        [](const char* label,
           const std::array<float, 2>& v,
           float v_speed,
           float v_min,
           float v_max,
           const char* format,
           float power) {
            auto v_ = v;
            auto clicked =
                ImGui::DragFloat2(label, v_.data(), v_speed, v_min, v_max, format, power);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_speed") = 1.0f,
        py::arg("v_min") = 0.0f,
        py::arg("v_max") = 0.0f,
        py::arg("format") = "%.3f",
        py::arg("power") = 1.0f);
    m.def(
        "drag_float3",
        [](const char* label,
           const std::array<float, 3>& v,
           float v_speed,
           float v_min,
           float v_max,
           const char* format,
           float power) {
            auto v_ = v;
            auto clicked =
                ImGui::DragFloat3(label, v_.data(), v_speed, v_min, v_max, format, power);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_speed") = 1.0f,
        py::arg("v_min") = 0.0f,
        py::arg("v_max") = 0.0f,
        py::arg("format") = "%.3f",
        py::arg("power") = 1.0f);
    m.def(
        "drag_float4",
        [](const char* label,
           const std::array<float, 4>& v,
           float v_speed,
           float v_min,
           float v_max,
           const char* format,
           float power) {
            auto v_ = v;
            auto clicked =
                ImGui::DragFloat4(label, v_.data(), v_speed, v_min, v_max, format, power);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_speed") = 1.0f,
        py::arg("v_min") = 0.0f,
        py::arg("v_max") = 0.0f,
        py::arg("format") = "%.3f",
        py::arg("power") = 1.0f);
    m.def(
        "drag_float_range2",
        [](const char* label,
           const std::array<float, 2>& v_current_min,
           const std::array<float, 2>& v_current_max,
           float v_speed,
           float v_min,
           float v_max,
           const char* format,
           const char* format_max,
           float power) {
            auto v_current_min_ = v_current_min;
            auto v_current_max_ = v_current_max;
            auto clicked = ImGui::DragFloatRange2(label,
                                                  v_current_min_.data(),
                                                  v_current_max_.data(),
                                                  v_speed,
                                                  v_min,
                                                  v_max,
                                                  format,
                                                  format_max,
                                                  power);
            return std::make_tuple(clicked, v_current_min_, v_current_max_);
        },
        py::arg("label"),
        py::arg("v_current_min"),
        py::arg("v_current_max"),
        py::arg("v_speed") = 1.0f,
        py::arg("v_min") = 0.0f,
        py::arg("v_max") = 0.0f,
        py::arg("format") = "%.3f",
        py::arg("format_max") = nullptr,
        py::arg("power") = 1.0f);

    m.def(
        "drag_int",
        [](const char* label, int v, float v_speed, int v_min, int v_max, const char* format) {
            auto v_ = v;
            auto clicked = ImGui::DragInt(label, &v_, v_speed, v_min, v_max, format);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_speed") = 1.0f,
        py::arg("v_min") = 0,
        py::arg("v_max") = 0,
        py::arg("format") = "%d");
    m.def(
        "drag_int2",
        [](const char* label,
           const std::array<int, 2>& v,
           float v_speed,
           int v_min,
           int v_max,
           const char* format) {
            auto v_ = v;
            auto clicked = ImGui::DragInt2(label, v_.data(), v_speed, v_min, v_max, format);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_speed") = 1.0f,
        py::arg("v_min") = 0,
        py::arg("v_max") = 0,
        py::arg("format") = "%d");
    m.def(
        "drag_int3",
        [](const char* label,
           const std::array<int, 3>& v,
           float v_speed,
           int v_min,
           int v_max,
           const char* format) {
            auto v_ = v;
            auto clicked = ImGui::DragInt3(label, v_.data(), v_speed, v_min, v_max, format);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_speed") = 1.0f,
        py::arg("v_min") = 0,
        py::arg("v_max") = 0,
        py::arg("format") = "%d");
    m.def(
        "drag_int4",
        [](const char* label,
           const std::array<int, 4>& v,
           float v_speed,
           int v_min,
           int v_max,
           const char* format) {
            auto v_ = v;
            auto clicked = ImGui::DragInt4(label, v_.data(), v_speed, v_min, v_max, format);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_speed") = 1.0f,
        py::arg("v_min") = 0,
        py::arg("v_max") = 0,
        py::arg("format") = "%d");
    m.def(
        "drag_int_range2",
        [](const char* label,
           const std::array<int, 2>& v_current_min,
           const std::array<int, 2>& v_current_max,
           float v_speed,
           int v_min,
           int v_max,
           const char* format,
           const char* format_max) {
            auto v_current_min_ = v_current_min;
            auto v_current_max_ = v_current_max;
            auto clicked = ImGui::DragIntRange2(label,
                                                v_current_min_.data(),
                                                v_current_max_.data(),
                                                v_speed,
                                                v_min,
                                                v_max,
                                                format,
                                                format_max);
            return std::make_tuple(clicked, v_current_min_, v_current_max_);
        },
        py::arg("label"),
        py::arg("v_current_min"),
        py::arg("v_current_max"),
        py::arg("v_speed") = 1.0f,
        py::arg("v_min") = 0,
        py::arg("v_max") = 0,
        py::arg("format") = "%d",
        py::arg("format_max") = nullptr);

    // Widgets: Sliders
    m.def(
        "slider_float",
        [](const char* label, float v, float v_min, float v_max, const char* format, float power) {
            auto v_ = v;
            auto clicked = ImGui::SliderFloat(label, &v_, v_min, v_max, format, power);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_min") = 0.0f,
        py::arg("v_max") = 0.0f,
        py::arg("format") = "%.3f",
        py::arg("power") = 1.0f);
    m.def(
        "slider_float2",
        [](const char* label,
           const std::array<float, 2>& v,
           float v_min,
           float v_max,
           const char* format,
           float power) {
            auto v_ = v;
            auto clicked = ImGui::SliderFloat2(label, v_.data(), v_min, v_max, format, power);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_min") = 0.0f,
        py::arg("v_max") = 0.0f,
        py::arg("format") = "%.3f",
        py::arg("power") = 1.0f);
    m.def(
        "slider_float3",
        [](const char* label,
           const std::array<float, 3>& v,
           float v_min,
           float v_max,
           const char* format,
           float power) {
            auto v_ = v;
            auto clicked = ImGui::SliderFloat3(label, v_.data(), v_min, v_max, format, power);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_min") = 0.0f,
        py::arg("v_max") = 0.0f,
        py::arg("format") = "%.3f",
        py::arg("power") = 1.0f);
    m.def(
        "slider_float4",
        [](const char* label,
           const std::array<float, 4>& v,
           float v_min,
           float v_max,
           const char* format,
           float power) {
            auto v_ = v;
            auto clicked = ImGui::SliderFloat4(label, v_.data(), v_min, v_max, format, power);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_min") = 0.0f,
        py::arg("v_max") = 0.0f,
        py::arg("format") = "%.3f",
        py::arg("power") = 1.0f);

    m.def(
        "slider_angle",
        [](const char* label,
           float v_rad,
           float v_degrees_min,
           float v_degrees_max,
           const char* format) {
            auto v_rad_ = v_rad;
            auto clicked = ImGui::SliderAngle(label, &v_rad_, v_degrees_min, v_degrees_max, format);
            return std::make_tuple(clicked, v_rad_);
        },
        py::arg("label"),
        py::arg("v_rad"),
        py::arg("v_degrees_min") = -360.0f,
        py::arg("v_degrees_max") = +360.0f,
        py::arg("format") = "%.0f deg");

    m.def(
        "slider_int",
        [](const char* label, int v, int v_min, int v_max, const char* format) {
            auto v_ = v;
            auto clicked = ImGui::SliderInt(label, &v_, v_min, v_max, format);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_min") = 0,
        py::arg("v_max") = 0,
        py::arg("format") = "%d");
    m.def(
        "slider_int2",
        [](const char* label,
           const std::array<int, 2>& v,
           int v_min,
           int v_max,
           const char* format) {
            auto v_ = v;
            auto clicked = ImGui::SliderInt2(label, v_.data(), v_min, v_max, format);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_min") = 0,
        py::arg("v_max") = 0,
        py::arg("format") = "%d");
    m.def(
        "slider_int3",
        [](const char* label,
           const std::array<int, 3>& v,
           int v_min,
           int v_max,
           const char* format) {
            auto v_ = v;
            auto clicked = ImGui::SliderInt3(label, v_.data(), v_min, v_max, format);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_min") = 0,
        py::arg("v_max") = 0,
        py::arg("format") = "%d");
    m.def(
        "slider_int4",
        [](const char* label,
           const std::array<int, 4>& v,
           int v_min,
           int v_max,
           const char* format) {
            auto v_ = v;
            auto clicked = ImGui::SliderInt4(label, v_.data(), v_min, v_max, format);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("v_min") = 0,
        py::arg("v_max") = 0,
        py::arg("format") = "%d");

    // Widgets: Input with Keyboard
    m.def(
        "input_text",
        [](const char* label, const std::string& buf, ImGuiInputTextFlags flags) {
            IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
            flags |= ImGuiInputTextFlags_CallbackResize;

            auto buf_ = buf;
            InputTextCallback_UserData cb_user_data;
            cb_user_data.str = &buf_;
            cb_user_data.chain_callback = nullptr;
            cb_user_data.chain_callback_user_data = nullptr;
            const auto clicked = ImGui::InputText(label,
                                                  (char*)buf_.c_str(),
                                                  buf_.capacity() + 1,
                                                  flags,
                                                  input_text_callback,
                                                  &cb_user_data);
            return std::make_tuple(clicked, buf_);
        },
        py::arg("label"),
        py::arg("buf"),
        py::arg("flags") = 0);
    m.def(
        "input_text_multiline",
        [](const char* label,
           const std::string& buf,
           const Vec2T& size,
           ImGuiInputTextFlags flags) {
            IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
            flags |= ImGuiInputTextFlags_CallbackResize;

            auto buf_ = buf;
            InputTextCallback_UserData cb_user_data;
            cb_user_data.str = &buf_;
            cb_user_data.chain_callback = nullptr;
            cb_user_data.chain_callback_user_data = nullptr;
            const auto clicked = ImGui::InputTextMultiline(label,
                                                           (char*)buf_.c_str(),
                                                           buf_.capacity() + 1,
                                                           to_vec2(size),
                                                           flags,
                                                           input_text_callback,
                                                           &cb_user_data);
            return std::make_tuple(clicked, buf_);
        },
        py::arg("label"),
        py::arg("buf"),
        py::arg("size") = std::make_tuple(0.f, 0.f),
        py::arg("flags") = 0);
    m.def(
        "input_text_with_hint",
        [](const char* label, const char* hint, const std::string& buf, ImGuiInputTextFlags flags) {
            IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
            flags |= ImGuiInputTextFlags_CallbackResize;

            auto buf_ = buf;
            InputTextCallback_UserData cb_user_data;
            cb_user_data.str = &buf_;
            cb_user_data.chain_callback = nullptr;
            cb_user_data.chain_callback_user_data = nullptr;
            const auto clicked = ImGui::InputTextWithHint(label,
                                                          hint,
                                                          (char*)buf_.c_str(),
                                                          buf_.capacity() + 1,
                                                          flags,
                                                          input_text_callback,
                                                          &cb_user_data);
            return std::make_tuple(clicked, buf_);
        },
        py::arg("label"),
        py::arg("hint"),
        py::arg("buf"),
        py::arg("flags") = 0);
    m.def(
        "input_float",
        [](const char* label,
           float v,
           float step,
           float step_fast,
           const char* format,
           ImGuiInputTextFlags flags) {
            auto v_ = v;
            const auto clicked = ImGui::InputFloat(label, &v_, step, step_fast, format, flags);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("step") = 0.f,
        py::arg("step_fast") = 0.f,
        py::arg("format") = "%.3f",
        py::arg("flags") = 0);
    m.def(
        "input_float2",
        [](const char* label,
           const std::array<float, 2>& v,
           const char* format,
           ImGuiInputTextFlags flags) {
            auto v_ = v;
            const auto clicked = ImGui::InputFloat2(label, v_.data(), format, flags);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("format") = "%.3f",
        py::arg("flags") = 0);
    m.def(
        "input_float3",
        [](const char* label,
           const std::array<float, 3>& v,
           const char* format,
           ImGuiInputTextFlags flags) {
            auto v_ = v;
            const auto clicked = ImGui::InputFloat3(label, v_.data(), format, flags);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("format") = "%.3f",
        py::arg("flags") = 0);
    m.def(
        "input_float4",
        [](const char* label,
           const std::array<float, 4>& v,
           const char* format,
           ImGuiInputTextFlags flags) {
            auto v_ = v;
            const auto clicked = ImGui::InputFloat4(label, v_.data(), format, flags);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("format") = "%.3f",
        py::arg("flags") = 0);
    m.def(
        "input_int",
        [](const char* label, int v, float step, float step_fast, ImGuiInputTextFlags flags) {
            auto v_ = v;
            const auto clicked = ImGui::InputInt(label, &v_, step, step_fast, flags);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("step") = 0.f,
        py::arg("step_fast") = 0.f,
        py::arg("flags") = 0);
    m.def(
        "input_int2",
        [](const char* label, const std::array<int, 2>& v, ImGuiInputTextFlags flags) {
            auto v_ = v;
            const auto clicked = ImGui::InputInt2(label, v_.data(), flags);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("flags") = 0);
    m.def(
        "input_int3",
        [](const char* label, const std::array<int, 3>& v, ImGuiInputTextFlags flags) {
            auto v_ = v;
            const auto clicked = ImGui::InputInt3(label, v_.data(), flags);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("flags") = 0);
    m.def(
        "input_int4",
        [](const char* label, const std::array<int, 4>& v, ImGuiInputTextFlags flags) {
            auto v_ = v;
            const auto clicked = ImGui::InputInt4(label, v_.data(), flags);
            return std::make_tuple(clicked, v_);
        },
        py::arg("label"),
        py::arg("v"),
        py::arg("flags") = 0);

    // Widgets: Color Editor/Picker
    m.def(
        "color_edit3",
        [](const char* label, const std::array<float, 3>& col, ImGuiColorEditFlags flags) {
            auto col_ = col;
            const auto clicked = ImGui::ColorEdit3(label, col_.data(), flags);
            return std::make_tuple(clicked, col_);
        },
        py::arg("label"),
        py::arg("def"),
        py::arg("flags") = 0);
    m.def(
        "color_edit4",
        [](const char* label, const std::array<float, 4>& col, ImGuiColorEditFlags flags) {
            auto col_ = col;
            const auto clicked = ImGui::ColorEdit4(label, col_.data(), flags);
            return std::make_tuple(clicked, col_);
        },
        py::arg("label"),
        py::arg("def"),
        py::arg("flags") = 0);
    m.def(
        "color_picker3",
        [](const char* label, const std::array<float, 3>& col, ImGuiColorEditFlags flags) {
            auto col_ = col;
            const auto clicked = ImGui::ColorPicker3(label, col_.data(), flags);
            return std::make_tuple(clicked, col_);
        },
        py::arg("label"),
        py::arg("def"),
        py::arg("flags") = 0);
    m.def(
        "color_picker4",
        [](const char* label, const std::array<float, 4>& col, ImGuiColorEditFlags flags) {
            auto col_ = col;
            const auto clicked = ImGui::ColorPicker4(label, col_.data(), flags);
            return std::make_tuple(clicked, col_);
        },
        py::arg("label"),
        py::arg("def"),
        py::arg("flags") = 0);
    m.def(
        "color_button",
        [](const char* label, const Vec4T& col, ImGuiColorEditFlags flags, const Vec2T& size) {
            auto col_ = col;
            const auto clicked = ImGui::ColorButton(label, to_vec4(col), flags, to_vec2(size));
            return std::make_tuple(clicked, col_);
        },
        py::arg("label"),
        py::arg("def"),
        py::arg("flags") = 0,
        py::arg("size") = std::make_tuple(0.f, 0.f));
    m.def(
        "set_color_edit_options",
        [](ImGuiColorEditFlags flags) { ImGui::SetColorEditOptions(flags); },
        py::arg("flags"));

    // Widgets: Trees
    m.def(
        "tree_node", [](const char* label) { return ImGui::TreeNode(label); }, py::arg("label"));
    m.def(
        "tree_node_ex",
        [](const char* label, ImGuiTreeNodeFlags flags) { return ImGui::TreeNodeEx(label, flags); },
        py::arg("label"),
        py::arg("flags") = 0);
    m.def(
        "tree_push", [](const char* str_id) { ImGui::TreePush(str_id); }, py::arg("str_id"));
    m.def("tree_pop", []() { ImGui::TreePop(); });
    m.def("get_tree_node_to_label_spacing", []() { return ImGui::GetTreeNodeToLabelSpacing(); });
    m.def(
        "collapsing_header",
        [](const char* label, ImGuiTreeNodeFlags flags) {
            return ImGui::CollapsingHeader(label, flags);
        },
        py::arg("label"),
        py::arg("flags") = 0);
    m.def(
        "collapsing_header",
        [](const char* label, bool open, ImGuiTreeNodeFlags flags) {
            auto open_ = open;
            const auto clicked = ImGui::CollapsingHeader(label, &open_, flags);
            return std::make_tuple(clicked, open_);
        },
        py::arg("label"),
        py::arg("open"),
        py::arg("flags") = 0);
    m.def(
        "set_next_item_open",
        [](bool is_open, ImGuiCond cond) { ImGui::SetNextItemOpen(is_open, cond); },
        py::arg("is_open"),
        py::arg("cond") = 0);

    // Widgets: Selectables
    m.def(
        "selectable",
        [](const char* label, bool selected, ImGuiSelectableFlags flags, const Vec2T& size) {
            auto selected_ = selected;
            const auto clicked = ImGui::Selectable(label, &selected, flags, to_vec2(size));
            return std::make_tuple(clicked, selected_);
        },
        py::arg("label"),
        py::arg("selected"),
        py::arg("flags") = 0,
        py::arg("size") = std::make_tuple(0.f, 0.f));

    // Widgets: List Boxes
    m.def(
        "list_box",
        [](const char* label,
           int current_item,
           const std::vector<const char*>& items,
           int height_in_items) {
            auto current_item_ = current_item;
            const auto clicked =
                ImGui::ListBox(label, &current_item_, items.data(), items.size(), height_in_items);
            return std::make_tuple(clicked, current_item_);
        },
        py::arg("label"),
        py::arg("current_item"),
        py::arg("items"),
        py::arg("height_in_items") = -1);

    // Widgets: Menus
    m.def("begin_menu_bar", []() { return ImGui::BeginMenuBar(); });
    m.def("end_menu_bar", []() { ImGui::EndMenuBar(); });
    m.def("begin_main_menu_bar", []() { return ImGui::BeginMainMenuBar(); });
    m.def("end_main_menu_bar", []() { return ImGui::EndMainMenuBar(); });
    m.def(
        "begin_menu",
        [](const char* label, bool enabled) { return ImGui::BeginMenu(label, enabled); },
        py::arg("label"),
        py::arg("enabled") = true);
    m.def("end_menu", []() { ImGui::EndMenu(); });
    m.def(
        "menu_item",
        [](const char* label, const char* shortcut, bool selected, bool enabled) {
            return ImGui::MenuItem(label, shortcut, selected, enabled);
        },
        py::arg("label"),
        py::arg("shortcut") = nullptr,
        py::arg("selected") = false,
        py::arg("enabled") = true);

    // Popups, Modals
    m.def(
        "open_popup", [](const char* str_id) { ImGui::OpenPopup(str_id); }, py::arg("str_id"));
    m.def(
        "begin_popup",
        [](const char* str_id, ImGuiWindowFlags flags) { return ImGui::BeginPopup(str_id, flags); },
        py::arg("str_id"),
        py::arg("flags") = 0);
    m.def(
        "begin_popup_context_item",
        [](const char* str_id, ImGuiMouseButton mouse_button) {
            return ImGui::BeginPopupContextItem(str_id, mouse_button);
        },
        py::arg("str_id"),
        py::arg("mouse_button") = 1);
    m.def(
        "begin_popup_context_window",
        [](const char* str_id, ImGuiMouseButton mouse_button, bool also_over_items) {
            return ImGui::BeginPopupContextWindow(str_id, mouse_button, also_over_items);
        },
        py::arg("str_id"),
        py::arg("mouse_button") = 1,
        py::arg("also_over_items") = true);
    m.def(
        "begin_popup_context_void",
        [](const char* str_id, ImGuiMouseButton mouse_button) {
            return ImGui::BeginPopupContextVoid(str_id, mouse_button);
        },
        py::arg("str_id"),
        py::arg("mouse_button") = 1);
    m.def(
        "begin_popup_modal",
        [](const char* str_id, bool open, ImGuiWindowFlags flags) {
            auto open_ = open;
            return ImGui::BeginPopupModal(str_id, &open_, flags);
        },
        py::arg("str_id"),
        py::arg("open"),
        py::arg("flags") = 0);
    m.def("end_popup", []() { ImGui::EndPopup(); });
    m.def(
        "open_popup_on_item_click",
        [](const char* str_id, ImGuiMouseButton mouse_button) {
            return ImGui::OpenPopupOnItemClick(str_id, mouse_button);
        },
        py::arg("str_id"),
        py::arg("mouse_button") = 1);
    m.def(
        "is_popup_open",
        [](const char* str_id) { return ImGui::IsPopupOpen(str_id); },
        py::arg("str_id"));
    m.def("close_current_popup", []() { ImGui::CloseCurrentPopup(); });

    // Windows
    m.def(
        "begin",
        [](const char* name, bool open, ImGuiWindowFlags flags) {
            auto open_ = open;
            const auto clicked = ImGui::Begin(name, &open_, flags);
            return std::make_tuple(clicked, open_);
        },
        py::arg("name"),
        py::arg("open"),
        py::arg("flags") = 0);
    m.def("end", []() { ImGui::End(); });

    // Item/Widgets Utilities
    m.def(
        "is_item_hovered",
        [](ImGuiHoveredFlags flags) { return ImGui::IsItemHovered(flags); },
        py::arg("flags") = 0);
    m.def("is_item_active", []() { return ImGui::IsItemActive(); });
    m.def("is_item_focused", []() { return ImGui::IsItemFocused(); });
    m.def(
        "is_item_clicked",
        [](ImGuiMouseButton mouse_button) { return ImGui::IsItemClicked(mouse_button); },
        py::arg("mouse_button") = 0);
    m.def("is_item_visible", []() { return ImGui::IsItemVisible(); });
    m.def("is_item_edited", []() { return ImGui::IsItemEdited(); });
    m.def("is_item_activated", []() { return ImGui::IsItemActivated(); });
    m.def("is_item_deactivated", []() { return ImGui::IsItemDeactivated(); });
    m.def("is_item_deactivated_after_edit", []() { return ImGui::IsItemDeactivatedAfterEdit(); });
    m.def("is_item_toggled_open", []() { return ImGui::IsItemToggledOpen(); });
    m.def("is_any_item_hovered", []() { return ImGui::IsAnyItemHovered(); });
    m.def("is_any_item_active", []() { return ImGui::IsAnyItemActive(); });
    m.def("is_any_item_focused", []() { return ImGui::IsAnyItemFocused(); });
    m.def("get_item_rect_min", []() { return from_vec2(ImGui::GetItemRectMin()); });
    m.def("get_item_rect_max", []() { return from_vec2(ImGui::GetItemRectMax()); });
    m.def("get_item_rect_size", []() { return from_vec2(ImGui::GetItemRectSize()); });
    m.def("set_item_allow_verlap", []() { ImGui::SetItemAllowOverlap(); });

    // Child Windows
    m.def(
        "begin_child",
        [](const char* str_id, const Vec2T& size, bool border, ImGuiWindowFlags flags) {
            return ImGui::BeginChild(str_id, to_vec2(size), border, flags);
        },
        py::arg("str_id"),
        py::arg("size") = std::make_tuple(0.f, 0.f),
        py::arg("border") = false,
        py::arg("flags") = 0);
    m.def(
        "begin_child",
        [](ImGuiID id, const Vec2T& size, bool border, ImGuiWindowFlags flags) {
            return ImGui::BeginChild(id, to_vec2(size), border, flags);
        },
        py::arg("id"),
        py::arg("size") = std::make_tuple(0.f, 0.f),
        py::arg("border") = false,
        py::arg("flags") = 0);
    m.def("end_child", []() { ImGui::EndChild(); });

    // Windows Utilities
    m.def("is_window_appearing", []() { return ImGui::IsWindowAppearing(); });
    m.def("is_window_collapsed", []() { return ImGui::IsWindowCollapsed(); });
    m.def(
        "is_window_focused",
        [](ImGuiFocusedFlags flags) { return ImGui::IsWindowFocused(flags); },
        py::arg("flags") = 0);
    m.def(
        "is_window_hovered",
        [](ImGuiFocusedFlags flags) { return ImGui::IsWindowHovered(flags); },
        py::arg("flags") = 0);
    m.def("get_window_pos", []() { return from_vec2(ImGui::GetWindowPos()); });
    m.def("get_window_size", []() { return from_vec2(ImGui::GetWindowSize()); });
    m.def("get_window_width", []() { return ImGui::GetWindowWidth(); });
    m.def("get_window_height", []() { return ImGui::GetWindowHeight(); });

    m.def(
        "set_next_window_pos",
        [](const Vec2T& pos, ImGuiCond cond, const Vec2T& pivot) {
            ImGui::SetNextWindowPos(to_vec2(pos), cond, to_vec2(pivot));
        },
        py::arg("pos"),
        py::arg("cond") = 0,
        py::arg("pivot") = std::make_tuple(0., 0.));
    m.def(
        "set_next_window_size",
        [](const Vec2T& size, ImGuiCond cond) { ImGui::SetNextWindowSize(to_vec2(size), cond); },
        py::arg("size"),
        py::arg("cond") = 0);
    m.def(
        "set_next_window_size_constraints",
        [](const Vec2T& size_min, const Vec2T& size_max) {
            ImGui::SetNextWindowSizeConstraints(to_vec2(size_min), to_vec2(size_max));
        },
        py::arg("size_min"),
        py::arg("size_max"));
    m.def(
        "set_next_window_context_size",
        [](const Vec2T& size) { ImGui::SetNextWindowContentSize(to_vec2(size)); },
        py::arg("size"));
    m.def(
        "set_next_window_collapsed",
        [](bool collapsed, ImGuiCond cond) { ImGui::SetNextWindowCollapsed(collapsed, cond); },
        py::arg("collapsed"),
        py::arg("cond") = 0);
    m.def("set_next_window_focus", []() { ImGui::SetNextWindowFocus(); });
    m.def("set_next_window_bg_alpha", [](float alpha) { ImGui::SetNextWindowBgAlpha(alpha); });
    m.def(
        "set_window_pos",
        [](const Vec2T& pos, ImGuiCond cond) { ImGui::SetWindowPos(to_vec2(pos), cond); },
        py::arg("pos"),
        py::arg("cond") = 0);
    m.def(
        "set_window_size",
        [](const Vec2T& size, ImGuiCond cond) { ImGui::SetWindowSize(to_vec2(size), cond); },
        py::arg("size"),
        py::arg("cond") = 0);
    m.def(
        "set_window_collapsed",
        [](bool collapsed, ImGuiCond cond) { ImGui::SetWindowCollapsed(collapsed, cond); },
        py::arg("collapsed"),
        py::arg("cond") = 0);
    m.def("set_window_focus", []() { ImGui::SetWindowFocus(); });
    m.def(
        "set_window_font_scale",
        [](float scale) { ImGui::SetWindowFontScale(scale); },
        py::arg("scale"));
    m.def(
        "set_window_pos",
        [](const char* name, const Vec2T& pos, ImGuiCond cond) {
            ImGui::SetWindowPos(name, to_vec2(pos), cond);
        },
        py::arg("name"),
        py::arg("pos"),
        py::arg("cond") = 0);
    m.def(
        "set_window_size",
        [](const char* name, const Vec2T& size, ImGuiCond cond) {
            ImGui::SetWindowSize(name, to_vec2(size), cond);
        },
        py::arg("name"),
        py::arg("size"),
        py::arg("cond") = 0);
    m.def(
        "set_window_collapsed",
        [](const char* name, bool collapsed, ImGuiCond cond) {
            ImGui::SetWindowCollapsed(name, collapsed, cond);
        },
        py::arg("name"),
        py::arg("collapsed"),
        py::arg("cond") = 0);
    m.def(
        "set_window_focus", [](const char* name) { ImGui::SetWindowFocus(name); }, py::arg("name"));
}
