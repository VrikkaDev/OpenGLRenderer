//
// Created by VrikkaDev on 09/04/2023.
//

#ifndef OPENGLRENDERING_MATERIAL_H
#define OPENGLRENDERING_MATERIAL_H

#include "pch.h"
#include "Texture.h"
#include "Shader.h"

//todo need to make whole thing expandable
struct Material {
public:
    Material();
    glm::vec3 ambient = {0.1f,0.1f,0.1f};
    glm::vec3 diffuse = {0.5f, 0.5f, 0.5f};
    glm::vec3 specular = {1.0f, 1.0f, 1.0f};
    float shininess = 32.0f;
    std::optional<Texture> texture;
    Shader shader = Shader("Assets/Shaders/vertex.glsl", "Assets/Shaders/fragment.glsl");
    virtual void LoadToShader();
private:
    int m_LocationAmbient = 0, m_LocationDiffuse = 0, m_LocationSpecular = 0, m_LocationShininess = 0;
};


#endif //OPENGLRENDERING_MATERIAL_H
