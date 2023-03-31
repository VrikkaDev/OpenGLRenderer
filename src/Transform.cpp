//
// Created by VrikkaDev on 30/03/2023.
//

#include "Transform.h"

glm::vec3 Orientation::UP = glm::vec3(0.0f, 1.0f, 0.0f);

Orientation::Orientation() {
    SetOrientation(0.f,0.f);
}

void Orientation::SetYaw(float yaw) {
    // Create a quaternion for the yaw rotation
    glm::quat y = glm::angleAxis(glm::radians(yaw), UP);
    // Create a quaternion for the current pitch rotation
    glm::quat p = glm::angleAxis(Pitch, glm::vec3(1.f, 0.f, 0.f));
    // Combine the two quaternions to get the new orientation
    this->Quaternion = p * y;
    // Store the new yaw value
    Yaw = glm::radians(yaw);
}

void Orientation::SetPitch(float pitch) {
    // Create a quaternion for the pitch rotation
    glm::quat p = glm::angleAxis(glm::radians(pitch), glm::vec3(1.f, 0.f, 0.f));
    // Create a quaternion for the current yaw rotation
    glm::quat y = glm::angleAxis(Yaw, UP);
    // Combine the two quaternions to get the new orientation
    this->Quaternion = p * y;
    // Store the new pitch value
    Pitch = glm::radians(pitch);
}

float Orientation::GetYaw() {
    // Calculate the yaw from the current orientation quaternion
    Yaw = atan2(2 * (Quaternion.y * Quaternion.w + Quaternion.x * Quaternion.z),
                1 - 2 * (Quaternion.y * Quaternion.y + Quaternion.z * Quaternion.z));
    return Yaw;
}

float Orientation::GetPitch() {
    // Calculate the pitch from the current orientation quaternion
    Pitch = atan2(2 * (Quaternion.w * Quaternion.x + Quaternion.y * Quaternion.z),
                  1 - 2 * (Quaternion.x * Quaternion.x + Quaternion.y * Quaternion.y));
    return Pitch;
}

void Orientation::SetOrientation(float yaw, float pitch) {
    this->SetYaw(yaw);
    this->SetPitch(pitch);
}

glm::vec3 Orientation::FORWARD() const {
    // Compute the forward direction vector using quaternion rotation
    glm::vec3 forward = glm::vec3(-(2 * (Quaternion.x * Quaternion.z + Quaternion.w * Quaternion.y)),
                                  0.f,
                                  1 - 2 * (Quaternion.x * Quaternion.x + Quaternion.y * Quaternion.y));
    return forward;
}

glm::vec3 Orientation::RIGHT() const {
    // Compute the right direction vector using quaternion rotation
    glm::vec3 right = glm::vec3(1 - 2 * (Quaternion.y * Quaternion.y + Quaternion.z * Quaternion.z),
                                0.f,
                                -(2 * (Quaternion.x * Quaternion.z - Quaternion.w * Quaternion.y)));
    return right;
}

glm::mat4 Transform::CreateTransformationMatrix() const {
    // Create a 4x4 identity matrix
    glm::mat4 unit = glm::mat4(1.0f);
    // Create a translation matrix with the Position vector
    glm::mat4 t = glm::translate(unit, Position);
    // Create a rotation matrix for each axis (X, Y, Z) using quaternion rotation
    glm::mat4 rotx = glm::rotate(unit, glm::radians(Rotation.Quaternion.x), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 roty = glm::rotate(unit, glm::radians(Rotation.Quaternion.y), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rotz = glm::rotate(unit, glm::radians(Rotation.Quaternion.z), glm::vec3(0.0f, 0.0f, 1.0f));
    // Combine the rotation matrices into a single rotation matrix
    glm::mat4 r = rotx * roty * rotz;
    // Create a scaling matrix with a uniform scale factor of 0.1
    glm::mat4 s = glm::scale(unit, glm::vec3(0.1f));
    // Combine the translation, rotation, and scaling matrices into a single transformation matrix
    glm::mat4 matrix = t * r * s;
    // Return the computed transformation matrix
    return matrix;
}
