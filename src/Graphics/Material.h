//
// Created by VrikkaDev on 09/04/2023.
//

#ifndef OPENGLRENDERING_MATERIAL_H
#define OPENGLRENDERING_MATERIAL_H

#include "pch.h"
#include "Texture.h"
#include "Shader.h"

struct Material {
    glm::vec3 ambient = {0.1f,0.1f,0.1f};
    glm::vec3 diffuse = {0.5f, 0.5f, 0.5f};
    glm::vec3 specular = {1.0f, 1.0f, 1.0f};
    Shader shader = Shader("Assets/Shaders/vertex.glsl", "Assets/Shaders/fragment.glsl");
    float shininess = 32.0f;
    std::optional<Texture> texture;
};


#endif //OPENGLRENDERING_MATERIAL_H
