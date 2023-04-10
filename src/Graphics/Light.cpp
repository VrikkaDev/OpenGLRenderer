//
// Created by VrikkaDev on 10/04/2023.
//

#include "Light.h"

Light::Light(Transform& transform, glm::vec3 color) : m_Transform(transform), m_Color(color){
}

void Light::LoadToShader(Shader* shader) {

}

CubeLight::CubeLight(Transform& transform, glm::vec3 color) : Light(transform, color) {
}

void CubeLight::LoadToShader(Shader* shader) {
    shader->LoadVector3(shader->GetLocation("light.position"), m_Transform.Position);
    shader->LoadVector3(shader->GetLocation("light.color"), m_Color);
}
