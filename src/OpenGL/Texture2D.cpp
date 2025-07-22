#include "Texture2D.h"

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

void Texture2D::Bind(int slot)
{
    glActiveTexture(GL_TEXTURE0+slot);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
    m_Slot = slot;
}

void Texture2D::Unbind()
{
    glActiveTexture(GL_TEXTURE0+m_Slot);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
    
}

Texture2D::Texture2D(const char* filePath)
{
    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(filePath, &width, &height, &nrChannels, 0);
    if (data)
    {
        std::cout << nrChannels << std::endl;
        GLenum format;
        switch (nrChannels)
        {
        case 3:
            format = GL_RGB;
            break;
        
        case 4:
            format = GL_RGBA;
            break;
        default:

            break;
        }
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

Texture2D::~Texture2D()
{
    
}
