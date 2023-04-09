//
// Created by VrikkaDev on 30/03/2023.
//

#ifndef OPENGLRENDERING_MODEL_H
#define OPENGLRENDERING_MODEL_H


#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "Camera.h"
#include "Material.h"

class Model {
public:
    Model(Mesh& mesh, Material& material);
    void Render(Transform* transform, Camera* camera);
private:
    Mesh& m_Mesh;
    Material& m_Material;
};


#endif //OPENGLRENDERING_MODEL_H
