#pragma once

#include <unordered_map>
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
    void Use();

    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void SetUniform1I(const char* name, int value);
    void SetUniform1UI(const char* name, unsigned int value);
    void SetUniform1F(const char* name, float value);
    void SetUniform3f(const char* name, glm::vec3& value);
    void SetUniform4f(const char* name, glm::vec4& value);
    void SetUniformMat4f(const char* name, glm::mat4& value);
    void SetUniformBool(const char* name, bool value);

private:
    unsigned int m_RendererID;
    std::unordered_map<std::string, unsigned int> m_ShaderLocCache;

private:
    int getUniformLocation(const char* name);

};
