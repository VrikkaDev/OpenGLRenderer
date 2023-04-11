//
// Created by VrikkaDev on 09/04/2023.
//

#include "Material.h"

void Material::Bind() {
    shader.LoadVector3(m_LocationAmbient, ambient);
    shader.LoadVector3(m_LocationDiffuse, diffuse);
    shader.LoadVector3(m_LocationSpecular, specular);
    shader.LoadFloat(m_LocationShininess, shininess);

    texture.Bind(m_LocationTexture);
}

Material::Material() {
    m_LocationAmbient = shader.GetLocation("material.ambient");
    m_LocationDiffuse = shader.GetLocation("material.diffuse");
    m_LocationSpecular = shader.GetLocation("material.specular");
    m_LocationShininess = shader.GetLocation("material.shininess");

    m_LocationTexture = shader.GetLocation("material.modeltexture");
}

void Material::UnBind() const {
    texture.Unbind();
}
