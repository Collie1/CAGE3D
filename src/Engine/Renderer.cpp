#include "Renderer.h"

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

Renderer::Renderer(const Window& window)
    :   projectionMatrix(glm::perspective(glm::radians(40.0f), (float)window.GetWindowSize().x / (float)window.GetWindowSize().y, 0.01f, 100.0f)),
        viewMatrix(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f,-2.0f)))
{
    blockShader = std::make_unique<Shader>("Assets/Shaders/block.vs", "Assets/Shaders/block.fs");
    temporaryTexture = std::make_unique<Texture2D>("Assets/Textures/crate.png");
}

Renderer::~Renderer()
{
    
}

void Renderer::Clear(glm::vec3 clearColor)
{
    glClearColor(clearColor.x, clearColor.y, clearColor.z, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, Transform transform)
{
    blockShader.get()->Use();
    temporaryTexture.get()->Bind();
    blockShader.get()->SetUniform1I("u_TextureDiffuse", temporaryTexture.get()->getTexture());
    blockShader.get()->SetUniformMat4f("u_MVP", projectionMatrix * viewMatrix * (
        glm::translate(glm::mat4(1.0f), transform.position) *
        glm::rotate(glm::mat4(1.0f), glm::radians(transform.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)) *
        glm::rotate(glm::mat4(1.0f), glm::radians(transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)) *
        glm::rotate(glm::mat4(1.0f), glm::radians(transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)) *
        glm::scale(glm::mat4(1.0f), transform.scale)
    ));
    vertexArray.Bind();
    glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);
}
