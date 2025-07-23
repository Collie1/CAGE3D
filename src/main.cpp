
#include "Engine/Engine.h"
#include "Util/errorReporting.h"




int clean()
{
    // empty for now
    return 0;
}

void start()
{
    Window window("Hello !", 1280, 720);
    Renderer renderer(window);


    /*float rawVertexData[] = {
        // Front face
        -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   0.0f,  0.0f,  1.0f,
        0.5f, -0.5f,  0.5f,   1.0f, 0.0f,   0.0f,  0.0f,  1.0f,
        0.5f,  0.5f,  0.5f,   1.0f, 1.0f,   0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,   0.0f, 1.0f,   0.0f,  0.0f,  1.0f,

        // Back face
        -0.5f, -0.5f, -0.5f,   1.0f, 0.0f,   0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   0.0f,  0.0f, -1.0f,
        0.5f,  0.5f, -0.5f,   0.0f, 1.0f,   0.0f,  0.0f, -1.0f,
        0.5f, -0.5f, -0.5f,   0.0f, 0.0f,   0.0f,  0.0f, -1.0f,

        // Left face
        -0.5f, -0.5f, -0.5f,   0.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,   1.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,   1.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,  -1.0f,  0.0f,  0.0f,

        // Right face
        0.5f, -0.5f, -0.5f,   1.0f, 0.0f,   1.0f,  0.0f,  0.0f,
        0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   1.0f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,   0.0f, 1.0f,   1.0f,  0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   1.0f,  0.0f,  0.0f,

        // Bottom face
        -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,   0.0f, -1.0f,  0.0f,
        0.5f, -0.5f, -0.5f,   1.0f, 1.0f,   0.0f, -1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,   1.0f, 0.0f,   0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   0.0f, -1.0f,  0.0f,

        // Top face
        -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,   0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,   0.0f, 0.0f,   0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,   1.0f, 0.0f,   0.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   0.0f,  1.0f,  0.0f
    };

    // 12 triangles (36 indices)
    std::vector<unsigned int> indices = {
        0,  1,  2,   2,  3,  0,       // Front
        4,  5,  6,   6,  7,  4,       // Back
        8,  9, 10,  10, 11,  8,       // Left
        12, 13, 14,  14, 15, 12,       // Right
        16, 17, 18,  18, 19, 16,       // Bottom
        20, 21, 22,  22, 23, 20        // Top
    };

    
    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;
    std::vector<glm::vec3> normals;


    VertexArray vertexArray;

    for (int i = 0; i < 24; ++i) {
        int base = i * 8;
        positions.emplace_back(rawVertexData[base + 0], rawVertexData[base + 1], rawVertexData[base + 2]);
        texCoords.emplace_back(rawVertexData[base + 3], rawVertexData[base + 4]);
        normals.emplace_back(rawVertexData[base + 5],   rawVertexData[base + 6], rawVertexData[base + 7]);
    }

    VertexBuffer positionBuffer(positions);
    VertexBuffer texCoordBuffer(texCoords);
    VertexBuffer normalBuffer(normals);
    IndexBuffer indexBuffer(indices);

    vertexArray.AddAttribute<float>(positionBuffer, 3);
    vertexArray.AddAttribute<float>(texCoordBuffer, 2);
    vertexArray.AddAttribute<float>(normalBuffer, 3);


    std::unique_ptr<Texture2D> texture = std::make_unique<Texture2D>("Assets/Textures/crate.png");
    std::unique_ptr<Shader> basicShader = std::make_unique<Shader>("Assets/Shaders/basic.vs", "Assets/Shaders/basic.fs");
    
    Transform transform;
    transform.rotation.y = 45;*/

    CAGEEngine engine;
    engine.Initialize();
    while (engine.window.)
    {
        /* code */
    }
    

    while (window.isRunning())
    {

        renderer.Clear(glm::vec3(0.125f));
        window.Present();
        window.PollEvents();

    }
    
}

int main()
{   
    start();

    return clean();
    
}