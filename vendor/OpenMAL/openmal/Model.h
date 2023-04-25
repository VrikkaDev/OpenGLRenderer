//
// Created by VrikkaDev on 05/04/2023.
//

#ifndef OPENMAL_MODEL_H
#define OPENMAL_MODEL_H

#include <vector>
#include "Vectors.h"

namespace OpenMAL {

    struct Vertex {
        Vec3 position;
        Vec3 normal;
        Vec2 texcoord;

        bool operator==(const Vertex& other) const {
            return position == other.position && normal == other.normal &&
                   texcoord == other.texcoord;
        }
    };

    struct Model {
        std::vector<Vec3> positions;
        std::vector<Vec3> normals;
        std::vector<Vec2> texcoords;
        std::vector<unsigned int> indices;

        std::vector<Vertex> vertices;
    };
}

#endif //OPENMAL_MODEL_H
