#include "Shader.h"

#include <glad/glad.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>

void Shader::Use()
{
    glUseProgram(m_RendererID);
}

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    std::ifstream vsFile;
    std::ifstream fsFile;

    vsFile.exceptions(std::ifstream::badbit);
    fsFile.exceptions(std::ifstream::badbit);

    std::stringstream vertexShaderSource, fragmentShaderSource;
    try
    {
        vsFile.open(vertexPath);
        fsFile.open(fragmentPath);

        vertexShaderSource   << vsFile.rdbuf();
        fragmentShaderSource << fsFile.rdbuf();

        vsFile.close();
        fsFile.close();
    }
    catch(const std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << e.code() <<  std::endl;
    }
    
    int success;
    char infoLog[512];

    const char* vertexCode   =     vertexShaderSource.str().c_str();
    const char* fragmentCode =   fragmentShaderSource.str().c_str();

    unsigned int vs,fs;
    vs = glCreateShader(GL_VERTEX_SHADER);
    fs = glCreateShader(GL_FRAGMENT_SHADER);

    
    glShaderSource(vs, 1, &vertexCode, NULL);
    glCompileShader(vs);
    glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vs, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentCode, NULL);
    glCompileShader(fs);
    glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fs, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }


    

    

    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, vs);
    glAttachShader(m_RendererID, fs);

    glLinkProgram(m_RendererID);
    
    glGetProgramiv(m_RendererID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_RendererID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    
}


Shader::~Shader()
{
    glDeleteProgram(m_RendererID);
}


void Shader::SetUniform1I(const char* name, int value)
{
    glUniform1i(getUniformLocation(name), value);
}

void Shader::SetUniform1UI(const char* name, unsigned int value)
{
    glUniform1ui(getUniformLocation(name), value);
}

void Shader::SetUniform1F(const char* name, float value)
{
    glUniform1f(getUniformLocation(name), value);
}

void Shader::SetUniform3f(const char* name, glm::vec3& value)
{
    glUniform3f(getUniformLocation(name), value.x,value.y,value.z);
}

void Shader::SetUniform4f(const char* name, glm::vec4& value)
{
    glUniform4f(getUniformLocation(name), value.x, value.y, value.z, value.w);
}

void Shader::SetUniformMat4f(const char* name, glm::mat4& value)
{
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetUniformBool(const char* name, bool value)
{
    glUniform1f(getUniformLocation(name), value);
}

int Shader::getUniformLocation(const char* name)
{
    Use();
    if (m_ShaderLocCache.find(name) != m_ShaderLocCache.end())
        return m_ShaderLocCache[name];

    GLint location = glGetUniformLocation(m_RendererID, name);
    m_ShaderLocCache[name] = location;
    return location;
}
