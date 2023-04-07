//
// Created by VrikkaDev on 30/03/2023.
//

#ifndef OPENGLRENDERING_MODEL_H
#define OPENGLRENDERING_MODEL_H


#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "Camera.h"

class Model {
public:
    Model(Mesh &mesh, Shader &shader);
    void Render(Transform* transform, Camera* camera);
private:
    Mesh& m_Mesh;
    Shader& m_Shader;
};


#endif //OPENGLRENDERING_MODEL_H
