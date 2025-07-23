#pragma once

#include <glm/glm.hpp>
#include "Window.h"

class InputManager {
public:
    void OnMouseMove(double xpos, double ypos);

    void SetWindow(const Window& window);  // to link the callback
private:
    
};
