#pragma once

#include <glm/glm.hpp>

struct Transform
{
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    Transform() { position = glm::vec3(0.0f); rotation = glm::vec3(0.0f); scale = glm::vec3(1.0f); }
};
