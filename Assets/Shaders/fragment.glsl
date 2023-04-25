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

uniform sampler2D modeltexture;
uniform Material material;
uniform Light light;

in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;



float near = 0.1f;
float far = 100.0f;

float linearizeDepth(float depth)
{
    return (2.0 * near * far) / (far + near - (depth * 2.0 - 1.0) * (far - near));
}

float logisticDepth(float depth, float steepness, float offset)
{
    float zVal = linearizeDepth(depth);
    return (1 / (1 + exp(-steepness * (zVal - offset))));
}

void main()
{
    float a = 1.0f;
    if(TexCoord.x >= 0.8f || TexCoord.y >= 0.8 ||TexCoord.x <= -0.8f || TexCoord.y <= -0.8f){
        a = 0;
    }

    float b = 1.0f;

    float depth = logisticDepth(gl_FragCoord.z, 0.5f, 5.0f);
    FragColor = texture2D(modeltexture, TexCoord) * vec4(vec3(depth), 1.0f);
}