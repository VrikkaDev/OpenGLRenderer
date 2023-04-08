//
// Created by VrikkaDev on 05/04/2023.
//

#ifndef OPENMAL_MODEL_H
#define OPENMAL_MODEL_H

#include <vector>
#include "Vectors.h"

namespace OpenMAL {

    struct Model {
        std::vector<Vec3> positions;
        std::vector<Vec3> normals;
        std::vector<Vec2> texcoords;
        std::vector<unsigned int> indices;
    };

}

#endif //OPENMAL_MODEL_H
