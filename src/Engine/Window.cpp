#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../Util/errorReporting.h"

Window::Window(const char* name, int width, int height)
    :   m_Width(width),
        m_Height(height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true); 

    m_Window = glfwCreateWindow(width, height, name, NULL,NULL);

    if(m_Window == NULL) {
        std::cout << "Failed to init window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed To Initialize a valid OpenGL context" << std::endl;
        exit(-1);
    }

    enableReportGlErrors();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

Window::~Window()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}


void Window::Present()
{
    glfwSwapBuffers(m_Window);
}

void Window::PollEvents()
{
    glfwPollEvents();
}

bool Window::isRunning() const
{
    return !glfwWindowShouldClose(m_Window);
}
