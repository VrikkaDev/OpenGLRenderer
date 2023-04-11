#version 330 core

struct Material{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
    sampler2D modeltexture;
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
    FragColor = texture(material.modeltexture, TexCoord) * vec4(1.0f, 1.0f, 1.0f, 1.0f);
}