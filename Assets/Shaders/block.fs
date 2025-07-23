#version 450 core

in vec2 TexCoords;
uniform sampler2D u_TextureDiffuse;


in vec3 Normal; // Already in object space
out vec4 FragColor;


void main()
{
    vec4 ShadeColor;
    vec3 n = normalize(Normal);

    // Get absolute values to handle both directions (positive or negative)
    float absX = abs(n.x);
    float absY = abs(n.y);
    float absZ = abs(n.z);

    // Find which axis the normal is closest to
    if (absX > absY && absX > absZ)
    {
        ShadeColor = vec4(vec3(0.7), 1.0);  // facing X axis
    }
    else if (absZ > absX && absZ > absY)
    {
        ShadeColor = vec4(vec3(0.5), 1.0);  // facing Z axis
    }
    else
    {
        ShadeColor = vec4(vec3(1.0), 1.0);  // facing Y axis
    }

    FragColor = ShadeColor * texture(u_TextureDiffuse, TexCoords);

}