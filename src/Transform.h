//
// Created by VrikkaDev on 30/03/2023.
//

#ifndef OPENGLRENDERING_TRANSFORM_H
#define OPENGLRENDERING_TRANSFORM_H

#include "pch.h"

class Transform{
public:
    Transform() = default;
    glm::vec3 Position = {0,0,0};
    glm::vec3 Rotation = {0,0,0};
    glm::vec3 Scale = {1,1,1};

    glm::vec3 FORWARD() const;
    glm::vec3 RIGHT() const;
    static glm::vec3 UP;

    glm::quat GetQuat() const;
    glm::mat4 CreateTransformationMatrix() const;
};


#endif //OPENGLRENDERING_TRANSFORM_H
