//
// Created by VrikkaDev on 07/04/2023.
//

#include "MeshLoader.h"

std::unique_ptr<Mesh> MeshLoader::LoadMesh(const char* filepath) {

    // Load the model from filepath using my OpenMAL
    auto malmodel = OpenMAL::ModelLoader::LoadModel(filepath);

    std::vector<Vertex> vertices;
    vertices.resize(malmodel ->positions.size(), Vertex());

    for (size_t i = 0; i < vertices.size(); ++i)
    {
        vertices[i].position = glm::make_vec3(malmodel->positions[i].array);
        vertices[i].normal = glm::make_vec3(malmodel->normals[i].array);
        vertices[i].texcoord = glm::make_vec2(malmodel->texcoords[i].array);
    }

    // Create unique_ptr of the mesh
    auto mesh = std::make_unique<Mesh>(vertices, malmodel->indices);

    return mesh;
}
