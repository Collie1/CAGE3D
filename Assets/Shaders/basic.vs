#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aUV;

out vec3 VertColor;
out vec2 TexCoords;

uniform mat4 u_MVP;

void main()
{
    gl_Position = u_MVP * vec4(aPos,1.0);
    TexCoords = aUV;
    VertColor = aColor;
}