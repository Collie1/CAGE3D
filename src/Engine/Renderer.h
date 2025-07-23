#pragma once

#include "../OpenGL/IndexBuffer.h"
#include "../OpenGL/VertexArray.h"
#include "../OpenGL/Shader.h"
#include "../OpenGL/Texture2D.h"

#include "Transform.h"

#include "Window.h"

#include <glm/glm.hpp>

#include <memory>

class Renderer
{
public:
    Renderer(const Window& window);
    Renderer() {}
    ~Renderer();
    void Clear(glm::vec3 clearColor);
    void Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, Transform transform);
private:
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
    std::unique_ptr<Shader> blockShader;
    std::unique_ptr<Texture2D> temporaryTexture;

};
