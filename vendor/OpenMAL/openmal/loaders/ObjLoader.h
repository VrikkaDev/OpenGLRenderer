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

            std::vector<Vec3> positions;
            std::vector<Vec3> normals;
            std::vector<Vec2> texcoords;
            std::vector<unsigned int> indices;

            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string type;
                iss >> type;

                if (type == "v") {
                    Vec3 position{};
                    iss >> position.x >> position.y >> position.z;
                    positions.push_back(position);
                }
                else if (type == "vn") {
                    Vec3 normal{};
                    iss >> normal.x >> normal.y >> normal.z;
                    normals.push_back(normal);
                }
                else if (type == "vt") {
                    Vec2 texcoord{};
                    iss >> texcoord.x >> texcoord.y;
                    texcoords.push_back(texcoord);
                }
                else if (type == "f") {
                    unsigned int position_index, texcoord_index, normal_index;
                    char slash;
                    for (int i = 0; i < 3; i++) {
                        iss >> position_index >> slash >> texcoord_index >> slash >> normal_index;
                        indices.push_back(position_index - 1);
                    }
                }
            }

            // Copy vertex data from temporary vectors into model struct
            model->positions = positions;
            model->normals = normals;
            model->texcoords = texcoords;
            model->indices = indices;

            return model;
        }
    };
}

#endif //OPENMAL_OBJLOADER_H
