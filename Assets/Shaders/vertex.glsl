#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in vec3 aNormal;

uniform mat4 transformationMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 Normal;
out vec2 TexCoord;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * transformationMatrix * vec4(aPos, 1.0);
    Normal = aNormal;
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}