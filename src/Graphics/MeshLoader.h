//
// Created by VrikkaDev on 07/04/2023.
//

#ifndef OPENGLRENDERING_MESHLOADER_H
#define OPENGLRENDERING_MESHLOADER_H

#include "Mesh.h"

class MeshLoader {
public:
    static std::unique_ptr<Mesh> LoadMesh(const char* filepath);
};


#endif //OPENGLRENDERING_MESHLOADER_H
