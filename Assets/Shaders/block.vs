#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aUV;
layout (location = 2) in vec3 aNormal;

out vec2 TexCoords;
out vec3 Normal;

uniform mat4 u_MVP;

void main()
{
    gl_Position = u_MVP * vec4(aPos,1.0);
    TexCoords = aUV;
    Normal = aNormal;
}