#pragma once

#include <vector>
#include <glm/glm.hpp>

class VertexBuffer
{
public:
    void Bind() const;
    void Unbind() const;

    VertexBuffer(const std::vector<glm::vec4>& data);
    VertexBuffer(const std::vector<glm::vec3>& data);
    VertexBuffer(const std::vector<glm::vec2>& data);
    ~VertexBuffer();
private:
    unsigned int m_RendererID;
};
