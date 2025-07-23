#include "InputManager.h"

#include <GLFW/glfw3.h>

void InputManager::SetWindow(const Window& window) {
    

    // Store a pointer to this InputManager instance in the GLFW window
    glfwSetCursorPosCallback(window.getID(), InputManager::OnMouseMove);
}

void InputManager::OnMouseMove(GLFWwindow* window, double xpos, double ypos)
{
}
