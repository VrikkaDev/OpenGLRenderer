//
// Created by VrikkaDev on 05/04/2023.
//

#ifndef OPENMAL_MODELLOADER_H
#define OPENMAL_MODELLOADER_H

#include <iostream>
#include <filesystem>
#include "Model.h"
#include "loaders/ObjLoader.h"
#include "loaders/StlLoader.h"

namespace OpenMAL {

    // Including this header is slow, include loaders/ neededloader instead

    class ModelLoader {
    public:
        static std::unique_ptr<Model> LoadModel(const char* modelpath) {

            auto type = getModelFileType(std::filesystem::path(modelpath).extension().string());

            switch (type) {
                case modelFileType::Obj:
                    return OpenMAL::ObjLoader::Load(modelpath);
                case modelFileType::Stl:
                    return OpenMAL::StlLoader::Load(modelpath);
                default:
                    throw std::runtime_error("OpenMAL does not support this file format yet.");
            }
            return nullptr;
        }

    private:
        enum modelFileType {
            None,
            Obj,
            Stl
        };

        static modelFileType getModelFileType(const std::string_view filepath) {
            const size_t dot_pos = filepath.find_last_of('.');
            if (dot_pos != std::string_view::npos && dot_pos < filepath.size() - 1) {
                const std::string_view extension = filepath.substr(dot_pos + 1);
                if (extension == "obj") {
                    return modelFileType::Obj;
                } else if (extension == "stl") {
                    return modelFileType::Stl;
                }
            }
            return modelFileType::None;
        }
    };
}

#endif //OPENMAL_MODELLOADER_H
