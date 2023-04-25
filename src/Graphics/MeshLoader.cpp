//
// Created by VrikkaDev on 07/04/2023.
//

#include "MeshLoader.h"

std::unique_ptr<Mesh> MeshLoader::LoadMesh(const char* filepath) {

    // Load the model from filepath using my OpenMAL
    auto malmodel = OpenMAL::ModelLoader::LoadModel(filepath);

    std::vector<Vertex> vertices;

    for(auto vert : malmodel->vertices){
        Vertex vertex{};
        vertex.position = glm::make_vec3(vert.position.array);
        vertex.normal = glm::make_vec3(vert.normal.array);
        vertex.texcoord = glm::make_vec2(vert.texcoord.array);
        vertices.push_back(vertex);
    }

    // Create unique_ptr of the mesh
    auto mesh = std::make_unique<Mesh>(vertices, malmodel->indices);

    return mesh;
}
