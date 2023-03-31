//
// Created by VrikkaDev on 30/03/2023.
//

#ifndef DUCKENGINE_1_TRANSFORM_H
#define DUCKENGINE_1_TRANSFORM_H

#include "pch.h"

struct Orientation{
public:
    Orientation();
    glm::quat Quaternion = glm::quat(0.f,0.f,0.f,1.f);
    void SetYaw(float yaw);
    void SetPitch(float pitch);
    float GetYaw();
    float GetPitch();
    void SetOrientation(float yaw, float pitch);
    glm::vec3 FORWARD() const;
    glm::vec3 RIGHT() const;
    static glm::vec3 UP;
private:
    float Pitch = 0.f,Yaw = 0.f;
};

class Transform{
public:
    Transform() = default;
    glm::vec3 Position = {0,0,0};
    Orientation Rotation = Orientation();
    glm::vec3 Scale = {1,1,1};
    glm::mat4 CreateTransformationMatrix() const;
};


#endif //DUCKENGINE_1_TRANSFORM_H
