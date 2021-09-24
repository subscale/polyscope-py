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


void bind_imgui(py::module& m) {
  m.def("is_key_pressed", [](char c) { return ps::render::engine->isKeyPressed(c); });
  m.def("is_key_code_pressed", [](ImGuiKey code) { return ImGui::IsKeyPressed(code); });

  py::class_<KeyCode>(m, "KeyCode")
      .def_property_readonly_static("KEY_SPACE", [](py::object /* self */) { return KeyCode::KEY_SPACE; })
      .def_property_readonly_static("KEY_APOSTROPHE", [](py::object /* self */) { return KeyCode::KEY_APOSTROPHE; })
      .def_property_readonly_static("KEY_COMMA", [](py::object /* self */) { return KeyCode::KEY_COMMA; })
      .def_property_readonly_static("KEY_MINUS", [](py::object /* self */) { return KeyCode::KEY_MINUS; })
      .def_property_readonly_static("KEY_PERIOD", [](py::object /* self */) { return KeyCode::KEY_PERIOD; })
      .def_property_readonly_static("KEY_SLASH", [](py::object /* self */) { return KeyCode::KEY_SLASH; })
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
      .def_property_readonly_static("KEY_SEMICOLON", [](py::object /* self */) { return KeyCode::KEY_SEMICOLON; })
      .def_property_readonly_static("KEY_EQUAL", [](py::object /* self */) { return KeyCode::KEY_EQUAL; })
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
      .def_property_readonly_static("KEY_LEFT_BRACKET", [](py::object /* self */) { return KeyCode::KEY_LEFT_BRACKET; })
      .def_property_readonly_static("KEY_BACKSLASH", [](py::object /* self */) { return KeyCode::KEY_BACKSLASH; })
      .def_property_readonly_static("KEY_RIGHT_BRACKET",
                                    [](py::object /* self */) { return KeyCode::KEY_RIGHT_BRACKET; })
      .def_property_readonly_static("KEY_GRAVE_ACCENT", [](py::object /* self */) { return KeyCode::KEY_GRAVE_ACCENT; })
      .def_property_readonly_static("KEY_WORLD_1", [](py::object /* self */) { return KeyCode::KEY_WORLD_1; })
      .def_property_readonly_static("KEY_WORLD_2", [](py::object /* self */) { return KeyCode::KEY_WORLD_2; })
      .def_property_readonly_static("KEY_ESCAPE", [](py::object /* self */) { return KeyCode::KEY_ESCAPE; })
      .def_property_readonly_static("KEY_ENTER", [](py::object /* self */) { return KeyCode::KEY_ENTER; })
      .def_property_readonly_static("KEY_TAB", [](py::object /* self */) { return KeyCode::KEY_TAB; })
      .def_property_readonly_static("KEY_BACKSPACE", [](py::object /* self */) { return KeyCode::KEY_BACKSPACE; })
      .def_property_readonly_static("KEY_INSERT", [](py::object /* self */) { return KeyCode::KEY_INSERT; })
      .def_property_readonly_static("KEY_DELETE", [](py::object /* self */) { return KeyCode::KEY_DELETE; })
      .def_property_readonly_static("KEY_RIGHT", [](py::object /* self */) { return KeyCode::KEY_RIGHT; })
      .def_property_readonly_static("KEY_LEFT", [](py::object /* self */) { return KeyCode::KEY_LEFT; })
      .def_property_readonly_static("KEY_DOWN", [](py::object /* self */) { return KeyCode::KEY_DOWN; })
      .def_property_readonly_static("KEY_UP", [](py::object /* self */) { return KeyCode::KEY_UP; })
      .def_property_readonly_static("KEY_PAGE_UP", [](py::object /* self */) { return KeyCode::KEY_PAGE_UP; })
      .def_property_readonly_static("KEY_PAGE_DOWN", [](py::object /* self */) { return KeyCode::KEY_PAGE_DOWN; })
      .def_property_readonly_static("KEY_HOME", [](py::object /* self */) { return KeyCode::KEY_HOME; })
      .def_property_readonly_static("KEY_END", [](py::object /* self */) { return KeyCode::KEY_END; })
      .def_property_readonly_static("KEY_CAPS_LOCK", [](py::object /* self */) { return KeyCode::KEY_CAPS_LOCK; })
      .def_property_readonly_static("KEY_SCROLL_LOCK", [](py::object /* self */) { return KeyCode::KEY_SCROLL_LOCK; })
      .def_property_readonly_static("KEY_NUM_LOCK", [](py::object /* self */) { return KeyCode::KEY_NUM_LOCK; })
      .def_property_readonly_static("KEY_PRINT_SCREEN", [](py::object /* self */) { return KeyCode::KEY_PRINT_SCREEN; })
      .def_property_readonly_static("KEY_PAUSE", [](py::object /* self */) { return KeyCode::KEY_PAUSE; })
      .def_property_readonly_static("KEY_F1", [](py::object /* self */) { return KeyCode::KEY_F1; })
      .def_property_readonly_static("KEY_F2", [](py::object /* self */) { return KeyCode::KEY_F2; })
      .def_property_readonly_static("KEY_F3", [](py::object /* self */) { return KeyCode::KEY_F3; })
      .def_property_readonly_static("KEY_F4", [](py::object /* self */) { return KeyCode::KEY_F4; })
      .def_property_readonly_static("KEY_F5", [](py::object /* self */) { return KeyCode::KEY_F5; })
      .def_property_readonly_static("KEY_F6", [](py::object /* self */) { return KeyCode::KEY_F6; })
      .def_property_readonly_static("KEY_F7", [](py::object /* self */) { return KeyCode::KEY_F7; })
      .def_property_readonly_static("KEY_F8", [](py::object /* self */) { return KeyCode::KEY_F8; })
      .def_property_readonly_static("KEY_F9", [](py::object /* self */) { return KeyCode::KEY_F9; })
      .def_property_readonly_static("KEY_F10", [](py::object /* self */) { return KeyCode::KEY_F10; })
      .def_property_readonly_static("KEY_F11", [](py::object /* self */) { return KeyCode::KEY_F11; })
      .def_property_readonly_static("KEY_F12", [](py::object /* self */) { return KeyCode::KEY_F12; })
      .def_property_readonly_static("KEY_F13", [](py::object /* self */) { return KeyCode::KEY_F13; })
      .def_property_readonly_static("KEY_F14", [](py::object /* self */) { return KeyCode::KEY_F14; })
      .def_property_readonly_static("KEY_F15", [](py::object /* self */) { return KeyCode::KEY_F15; })
      .def_property_readonly_static("KEY_F16", [](py::object /* self */) { return KeyCode::KEY_F16; })
      .def_property_readonly_static("KEY_F17", [](py::object /* self */) { return KeyCode::KEY_F17; })
      .def_property_readonly_static("KEY_F18", [](py::object /* self */) { return KeyCode::KEY_F18; })
      .def_property_readonly_static("KEY_F19", [](py::object /* self */) { return KeyCode::KEY_F19; })
      .def_property_readonly_static("KEY_F20", [](py::object /* self */) { return KeyCode::KEY_F20; })
      .def_property_readonly_static("KEY_F21", [](py::object /* self */) { return KeyCode::KEY_F21; })
      .def_property_readonly_static("KEY_F22", [](py::object /* self */) { return KeyCode::KEY_F22; })
      .def_property_readonly_static("KEY_F23", [](py::object /* self */) { return KeyCode::KEY_F23; })
      .def_property_readonly_static("KEY_F24", [](py::object /* self */) { return KeyCode::KEY_F24; })
      .def_property_readonly_static("KEY_F25", [](py::object /* self */) { return KeyCode::KEY_F25; })
      .def_property_readonly_static("KEY_KP_0", [](py::object /* self */) { return KeyCode::KEY_KP_0; })
      .def_property_readonly_static("KEY_KP_1", [](py::object /* self */) { return KeyCode::KEY_KP_1; })
      .def_property_readonly_static("KEY_KP_2", [](py::object /* self */) { return KeyCode::KEY_KP_2; })
      .def_property_readonly_static("KEY_KP_3", [](py::object /* self */) { return KeyCode::KEY_KP_3; })
      .def_property_readonly_static("KEY_KP_4", [](py::object /* self */) { return KeyCode::KEY_KP_4; })
      .def_property_readonly_static("KEY_KP_5", [](py::object /* self */) { return KeyCode::KEY_KP_5; })
      .def_property_readonly_static("KEY_KP_6", [](py::object /* self */) { return KeyCode::KEY_KP_6; })
      .def_property_readonly_static("KEY_KP_7", [](py::object /* self */) { return KeyCode::KEY_KP_7; })
      .def_property_readonly_static("KEY_KP_8", [](py::object /* self */) { return KeyCode::KEY_KP_8; })
      .def_property_readonly_static("KEY_KP_9", [](py::object /* self */) { return KeyCode::KEY_KP_9; })
      .def_property_readonly_static("KEY_KP_DECIMAL", [](py::object /* self */) { return KeyCode::KEY_KP_DECIMAL; })
      .def_property_readonly_static("KEY_KP_DIVIDE", [](py::object /* self */) { return KeyCode::KEY_KP_DIVIDE; })
      .def_property_readonly_static("KEY_KP_MULTIPLY", [](py::object /* self */) { return KeyCode::KEY_KP_MULTIPLY; })
      .def_property_readonly_static("KEY_KP_SUBTRACT", [](py::object /* self */) { return KeyCode::KEY_KP_SUBTRACT; })
      .def_property_readonly_static("KEY_KP_ADD", [](py::object /* self */) { return KeyCode::KEY_KP_ADD; })
      .def_property_readonly_static("KEY_KP_ENTER", [](py::object /* self */) { return KeyCode::KEY_KP_ENTER; })
      .def_property_readonly_static("KEY_KP_EQUAL", [](py::object /* self */) { return KeyCode::KEY_KP_EQUAL; })
      .def_property_readonly_static("KEY_LEFT_SHIFT", [](py::object /* self */) { return KeyCode::KEY_LEFT_SHIFT; })
      .def_property_readonly_static("KEY_LEFT_CONTROL", [](py::object /* self */) { return KeyCode::KEY_LEFT_CONTROL; })
      .def_property_readonly_static("KEY_LEFT_ALT", [](py::object /* self */) { return KeyCode::KEY_LEFT_ALT; })
      .def_property_readonly_static("KEY_LEFT_SUPER", [](py::object /* self */) { return KeyCode::KEY_LEFT_SUPER; })
      .def_property_readonly_static("KEY_RIGHT_SHIFT", [](py::object /* self */) { return KeyCode::KEY_RIGHT_SHIFT; })
      .def_property_readonly_static("KEY_RIGHT_CONTROL",
                                    [](py::object /* self */) { return KeyCode::KEY_RIGHT_CONTROL; })
      .def_property_readonly_static("KEY_RIGHT_ALT", [](py::object /* self */) { return KeyCode::KEY_RIGHT_ALT; })
      .def_property_readonly_static("KEY_RIGHT_SUPER", [](py::object /* self */) { return KeyCode::KEY_RIGHT_SUPER; })
      .def_property_readonly_static("KEY_MENU", [](py::object /* self */) { return KeyCode::KEY_MENU; });
}
