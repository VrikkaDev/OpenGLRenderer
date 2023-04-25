//
// Created by VrikkaDev on 30/03/2023.
//

#ifndef OPENGLRENDERING_MESH_H
#define OPENGLRENDERING_MESH_H

#include "pch.h"
#include "Vertex.h"

class Mesh {
public:
    explicit Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices);
    Mesh() = default;

    uint32_t GetVertexCount() const {return m_VertexCount;}
    uint32_t GetIndexCount() const {return m_IndexCount;}
    uint32_t getVAO() const{return m_VAO;}

    void Bind() const;
    void UnBind() const;
private:
    uint32_t m_VAO = 0, m_VBO = 0, m_EBO = 0;
    uint32_t m_VertexCount = 0, m_IndexCount = 0;
};


#endif //OPENGLRENDERING_MESH_H
