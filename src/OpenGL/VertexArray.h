#pragma once

#include "VertexBuffer.h"

class VertexArray{
public:
    void Bind() const;
    void Unbind() const;

    template<typename T>
    void AddAttribute(const VertexBuffer& buffer, unsigned int count);

    VertexArray();
    ~VertexArray();
private:
    void AddAttributeP(const VertexBuffer& buffer, unsigned int count, int GLType);
private:
    unsigned int m_RendererID;
    unsigned int m_CurrentAttribute;
};

template<>
inline void VertexArray::AddAttribute<float>(const VertexBuffer& buffer, unsigned int count)
{
    AddAttributeP(buffer, count, 0x1406);
}
template<>
inline void VertexArray::AddAttribute<int>(const VertexBuffer& buffer, unsigned int count)
{
    AddAttributeP(buffer, count, 0x1404);
}
template<>
inline void VertexArray::AddAttribute<unsigned int>(const VertexBuffer& buffer, unsigned int count)
{
    AddAttributeP(buffer, count, 0x1405);
}
template<>
inline void VertexArray::AddAttribute<char>(const VertexBuffer& buffer, unsigned int count)
{
    AddAttributeP(buffer, count, 0x1400);
}
template<>
inline void VertexArray::AddAttribute<unsigned char>(const VertexBuffer& buffer, unsigned int count)
{
    AddAttributeP(buffer, count, 0x1401);
}