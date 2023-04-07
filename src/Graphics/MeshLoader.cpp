//
// Created by VrikkaDev on 07/04/2023.
//

#include "MeshLoader.h"

std::unique_ptr<Mesh> MeshLoader::LoadMesh(const char* filepath) {

    auto malmodel = OpenMAL::ObjLoader::Load(filepath);

    std::vector<float> vertices;

    for(auto & position : malmodel->positions){
        for(auto f : position.array){
            vertices.push_back(f);
        }
    }

    auto mesh = std::make_unique<Mesh>(vertices, malmodel->indices);

    return mesh;
}
