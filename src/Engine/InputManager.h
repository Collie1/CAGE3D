#pragma once

#include <glm/glm.hpp>
#include "Window.h"

class InputManager {
public:
    static void OnMouseMove(GLFWwindow* window, double xpos, double ypos);

    void SetWindow(const Window& window);  // to link the callback
private:
    
};
