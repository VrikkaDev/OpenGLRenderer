#version 330 core

struct Material{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light{
    vec3 position;
    vec3 color;
};

uniform Material material;
uniform Light light;

in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;

void main()
{
    float r, g, b;
    r = (gl_PrimitiveID % 256) / 255.0f;
    g = ((gl_PrimitiveID / 256) % 256) / 255.0f;
    b = ((gl_PrimitiveID / (256 * 256)) % 256) / 255.0f;
    FragColor = vec4(r,g,b, 1.0);
}