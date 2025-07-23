#include "InputManager.h"

#include <GLFW/glfw3.h>

void InputManager::SetWindow(const Window& window) {
    

    // Store a pointer to this InputManager instance in the GLFW window
    glfwSetCursorPosCallback(window.getID(), SetWindow);
}

void InputManager::OnMouseMove(double xpos, double ypos)
{
}
