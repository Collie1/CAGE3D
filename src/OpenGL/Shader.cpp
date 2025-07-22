#include "Shader.h"

#include <glad/glad.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

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

int Shader::getUniformLocation(const char* name)
{
    return glGetUniformLocation(m_RendererID, name);
}
