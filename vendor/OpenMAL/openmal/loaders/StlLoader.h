//
// Created by VrikkaDev on 06/04/2023.
//

#ifndef OPENMAL_STLLOADER_H
#define OPENMAL_STLLOADER_H

#include <memory>
#include <fstream>
#include <iostream>
#include "OpenMAL/openmal/Model.h"

namespace OpenMAL {
    class StlLoader {
    public:
        static std::unique_ptr<Model> Load(const char* filepath){
            std::ifstream file(filepath, std::ios::in | std::ios::binary);
            if (!file.is_open()) {
                std::cerr << "Failed to open STL file: " << filepath << std::endl;
                return nullptr;
            }

            // Read the header (80 bytes) and discard it
            char header[80];
            file.read(header, 80);

            // Read the number of triangles (4 bytes)
            uint32_t num_triangles = 0;
            file.read(reinterpret_cast<char*>(&num_triangles), sizeof(num_triangles));

            std::unique_ptr<Model> model = std::make_unique<Model>();

            // Read each triangle (50 bytes each)
            for (uint32_t i = 0; i < num_triangles; i++) {
                char buffer[50];
                file.read(buffer, 50);

                Vec3 normal = read_vec3(buffer + 0);
                Vec3 v1 = read_vec3(buffer + 12);
                Vec3 v2 = read_vec3(buffer + 24);
                Vec3 v3 = read_vec3(buffer + 36);

                model->positions.push_back(v1);
                model->positions.push_back(v2);
                model->positions.push_back(v3);

                model->normals.push_back(normal);
                model->normals.push_back(normal);
                model->normals.push_back(normal);

                model->indices.push_back(i * 3 + 0);
                model->indices.push_back(i * 3 + 1);
                model->indices.push_back(i * 3 + 2);
            }


            return model;
        }
    };
}

#endif //OPENMAL_STLLOADER_H
