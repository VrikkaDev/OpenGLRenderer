//
// Created by VrikkaDev on 10/04/2023.
//

#ifndef OPENGLRENDERING_LIGHT_H
#define OPENGLRENDERING_LIGHT_H

#include "Transform.h"
#include "Shader.h"

class Light {
public:
    Light(Transform& transform, glm::vec3 color);

    virtual void LoadToShader(Shader* shader);
protected:
    Transform& m_Transform;
    glm::vec3 m_Color;
};

class CubeLight : public Light{
public:
    CubeLight(Transform& transform, glm::vec3 color);
    void LoadToShader(Shader* shader) override;
};


#endif //OPENGLRENDERING_LIGHT_H
