//
// Created by VrikkaDev on 30/03/2023.
//

#include "Mesh.h"

Mesh::Mesh(const std::vector<float>& vertices, const std::vector<uint32_t>& indices) {
    // Generate a VAO and VBO
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    // Bind the VAO to configure it
    glBindVertexArray(m_VAO);

    // Bind the VBO to set the vertices data in it and allocate memory using glBufferData function with GL_STATIC_DRAW usage.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, (long)(vertices.size()*sizeof(float)), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // Store the number of vertices and indices in the vertex count variable
    m_VertexCount = (vertices.size()*sizeof(float));
    m_IndexCount = indices.size();

    // Specify how the vertex data is stored in the VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
    glEnableVertexAttribArray(0);

    // Unbind the VBO and VAO to prevent modification of their data outside this constructor
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::Bind() const {
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
}

void Mesh::Unbind() const {
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
