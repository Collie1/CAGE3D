#pragma once

class Shader
{
public:
    void Use();

    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

private:
    unsigned int m_RendererID;

private:
    int getUniformLocation(const char* name);

};
