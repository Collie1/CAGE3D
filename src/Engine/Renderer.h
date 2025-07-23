#pragma once

#include "../OpenGL/IndexBuffer.h"
#include "../OpenGL/VertexArray.h"
#include "../OpenGL/Shader.h"

#include <memory>

class Renderer
{
public:
    Renderer(/* args */);
    ~Renderer();
    void Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer);
private:
    std::unique_ptr<Shader> blockShader;

};
