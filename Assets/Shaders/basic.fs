#version 450 core

in vec3 VertColor;
in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D u_TextureDiffuse;

void main()
{
    FragColor = texture(u_TextureDiffuse, TexCoords) * vec4(VertColor, 1.0);
}