#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Util/errorReporting.h"

#include <memory>

#include "OpenGL/Shader.h"
#include "OpenGL/VertexBuffer.h"
#include "OpenGL/IndexBuffer.h"
#include "OpenGL/VertexArray.h"

#include "OpenGL/Texture2D.h"

GLFWwindow* createWindow(int width, int height)
{
    GLFWwindow* window;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "LearnOGL", NULL,NULL);

    if(window == NULL) {
        std::cout << "Failed to init window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed To Initialize a valid OpenGL context" << std::endl;
        exit(-1);
    }

    return window;
}

int clean()
{
    glfwTerminate();
    return 0;
}

void start()
{

    GLFWwindow* window = createWindow(1280, 720);
    enableReportGlErrors();


    std::vector<glm::vec3> positions = {
        glm::vec3(-0.5f, -0.5f, 0.0f),
        glm::vec3( 0.5f, -0.5f, 0.0f),
        glm::vec3( 0.5f,  0.5f, 0.0f),
        glm::vec3(-0.5f,  0.5f, 0.0f),
    };

    std::vector<glm::vec3> colors = {
        glm::vec3(1.0f, 0.0f, 0.0),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
    };

    std::vector<glm::vec2> uvCoords = {
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f)
    };


    std::vector<unsigned int> indices = {
        0,1,2,
        2,3,0
    };

    VertexArray vertexArray;

    VertexBuffer positionBuffer(positions);
    VertexBuffer colorBuffer(colors);
    VertexBuffer uvBuffer(uvCoords);
    IndexBuffer indexBuffer(indices);

    vertexArray.AddAttribute<float>(positionBuffer, 3);
    vertexArray.AddAttribute<float>(colorBuffer, 3);
    vertexArray.AddAttribute<float>(uvBuffer, 2);
    indexBuffer.Bind();
    vertexArray.Unbind();
    
    std::unique_ptr<Texture2D> texture = std::make_unique<Texture2D>("Assets/Textures/crate.bmp");
    std::unique_ptr<Shader> basicShader = std::make_unique<Shader>("Assets/Shaders/basic.vs", "Assets/Shaders/basic.fs");
    

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f,0.1f,0.1f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        basicShader.get()->Use();
        texture.get()->Bind();
        basicShader.get()->SetUniform1I("u_TextureDiffuse", texture.get()->getTexture());
        
        vertexArray.Bind();
        indexBuffer.Bind();

        glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
}

int main()
{   
    start();

    return clean();
    
}