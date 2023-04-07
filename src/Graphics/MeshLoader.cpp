//
// Created by VrikkaDev on 07/04/2023.
//

#include "MeshLoader.h"

std::unique_ptr<Mesh> MeshLoader::LoadMesh(const char* filepath) {

    // Load the model from filepath using my OpenMAL
    auto malmodel = OpenMAL::ObjLoader::Load(filepath);

    std::vector<float> vertices;

    // Get the position vectors from malmodel and put the values into the vertices vector
    for(auto & position : malmodel->positions){
        vertices.insert(vertices.end(), std::begin(position.array), std::end(position.array));
    }

    // Create unique_ptr of the mesh
    auto mesh = std::make_unique<Mesh>(vertices, malmodel->indices);

    return mesh;
}
