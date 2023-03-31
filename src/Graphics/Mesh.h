//
// Created by VrikkaDev on 30/03/2023.
//

#ifndef DUCKENGINE_1_MESH_H
#define DUCKENGINE_1_MESH_H

#include "pch.h"

class Mesh {
public:
    explicit Mesh(const std::vector<float>& vertices);
    Mesh() = default;

    uint32_t GetVertexCount() const {return m_VertexCount;}
    uint32_t getVAO() const{return m_VAO;}

    static Mesh* CUBE();
private:
    uint32_t m_VAO = 0, m_VBO = 0;
    uint32_t m_VertexCount = 0;
};


#endif //DUCKENGINE_1_MESH_H
