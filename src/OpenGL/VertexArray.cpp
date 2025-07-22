#include "VertexArray.h"

#include <glad/glad.h>
#include <type_traits>
#include <iostream>

void VertexArray::Bind() const
{
    glBindVertexArray(m_RendererID);  
}

void VertexArray::Unbind() const
{    
    glBindVertexArray(0);  
}

template<typename T>
void VertexArray::AddAttribute(const VertexBuffer& buffer, unsigned int count)
{
    Bind();
    buffer.Bind();
    GL_FLOAT
}

VertexArray::VertexArray()
    : m_CurrentAttribute(0)
{ glGenVertexArrays(1, &m_RendererID); }

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::AddAttributeP(const VertexBuffer& buffer, unsigned int count, int GLTYPE)
{
    buffer.Bind();
    Bind();
    glVertexAttribPointer(m_CurrentAttribute, count, GLTYPE, GL_FALSE, 0,0);
    glEnableVertexAttribArray(m_CurrentAttribute);
    m_CurrentAttribute++;
}
