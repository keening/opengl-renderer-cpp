#include "../include/input.hpp"

Input::Input()
{
    glfwSetCursorPosCallback(glfwGetCurrentContext(), cursor_callback);
}

Input::~Input() {}

void Input::handle_input(GLFWwindow *window, float delta_time)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        s_main_camera.process_keyboard(FORWARD, delta_time);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        s_main_camera.process_keyboard(BACKWARD, delta_time);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        s_main_camera.process_keyboard(LEFT, delta_time);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        s_main_camera.process_keyboard(RIGHT, delta_time);
}

void Input::cursor_callback(GLFWwindow *window, double x_pos, double y_pos)
{
    if (s_first_movement) {
        s_last_x = x_pos;
        s_last_y = y_pos;
        s_first_movement = false;
    }

    float x_offset = x_pos - s_last_x;
    float y_offset = s_last_y - y_pos;

    s_last_x = x_pos;
    s_last_y = y_pos;

    s_main_camera.process_mouse(x_offset, y_offset);
}