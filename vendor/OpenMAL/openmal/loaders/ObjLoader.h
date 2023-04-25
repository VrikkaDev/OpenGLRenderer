//
// Created by VrikkaDev on 05/04/2023.
//

#ifndef OPENMAL_OBJLOADER_H
#define OPENMAL_OBJLOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "OpenMAL/openmal/Model.h"

namespace OpenMAL{

    class ObjLoader{
    public:
        static std::unique_ptr<Model> Load(const char* filepath){

            std::ifstream file(filepath);
            if (!file.is_open()) {
                std::cerr << "Failed to open OBJ file: " << filepath << std::endl;
                return nullptr;
            }
            std::unique_ptr<Model> model = std::make_unique<Model>();

            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string type;
                iss >> type;

                if (type == "v") {
                    Vec3 position;
                    iss >> position.x >> position.y >> position.z;
                    model->positions.push_back(position);
                } else if (type == "vn") {
                    Vec3 normal;
                    iss >> normal.x >> normal.y >> normal.z;
                    model->normals.push_back(normal);
                } else if (type == "vt") {
                    Vec2 texcoord;
                    iss >> texcoord.x >> texcoord.y;
                    model->texcoords.push_back(texcoord);
                } else if (type == "f") {
                    std::vector<std::string> tokens;
                    std::string token;
                    while (iss >> token) {
                        tokens.push_back(token);
                    }

                    if (tokens.size() != 3) {
                        std::cerr << "Invalid face: " << line << std::endl;
                        continue;
                    }

                    for (int i = 0; i < 3; i++) {
                        unsigned int position_index, texcoord_index, normal_index;
                        std::sscanf(tokens[i].c_str(), "%u/%u/%u", &position_index,
                                    &texcoord_index, &normal_index);

                        Vertex vertex{};
                        vertex.position = model->positions[position_index - 1];
                        vertex.normal = model->normals[normal_index - 1];
                        vertex.texcoord = model->texcoords[texcoord_index - 1];

                        auto it = std::find(model->vertices.begin(), model->vertices.end(), vertex);
                        if (it != model->vertices.end()) {
                            model->indices.push_back(std::distance(model->vertices.begin(), it));
                        } else {
                            model->vertices.push_back(vertex);
                            model->indices.push_back(model->vertices.size() - 1);
                        }
                    }
                }
            }

            return model;
        }
    };
}

#endif //OPENMAL_OBJLOADER_H
