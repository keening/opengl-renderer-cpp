#pragma once

#include <GLFW/glfw3.h>
#include "../include/camera.hpp"

class Input {
public:
    Input();
    ~Input();

    void handle_input(GLFWwindow *window, float delta_time);

    inline static Camera s_main_camera;
private:
    static void cursor_callback(GLFWwindow *window, double x_pos, double y_pos);
    inline static float s_last_x, s_last_y;
    inline static bool s_first_movement = true;
};