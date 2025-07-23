#pragma once


#include <glm/glm.hpp>

struct GLFWwindow
{
    /* data */
};


class Window{
public:
    Window(const char* name, int width, int height);
    Window() = default;
    ~Window();

    void Clear();
    void Present();
    void PollEvents();
    bool isRunning() const;
    inline glm::ivec2 GetWindowSize() const { return glm::ivec2(m_Width, m_Height); }
    inline GLFWwindow* getID() const { return m_Window; }

private:
    GLFWwindow* m_Window;
    int m_Width;
    int m_Height;
};