#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window();
    ~Window();

    void present();
    uint32_t get_width();
    uint32_t get_height(); 
    static void framebuffer_callback(GLFWwindow *window, int width, int height);
private:
    void init();

    GLFWwindow *m_window = NULL;
    const uint32_t m_screen_width = 1280, m_screen_height = 720;
};

#endif
