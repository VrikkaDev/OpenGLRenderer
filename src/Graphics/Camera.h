//
// Created by VrikkaDev on 30/03/2023.
//

#ifndef OPENGLRENDERING_CAMERA_H
#define OPENGLRENDERING_CAMERA_H

#include "pch.h"
#include "Transform.h"
#include "Window.h"

class Camera : public WindowEvent{
public:
    explicit Camera(Transform& mTransform);

    float Fov = 80, NearPlane = 0.00001, FarPlane = 1000;

    void UpdateView();
    void UpdateProjection(uint32_t width, uint32_t height);

    void RenderBackground(float r, float g, float b, float a);

    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix();
    glm::mat4 GetViewProjectionMatrix();

    Transform* GetTransform(){
        return &m_Transform;
    }

    void OnWindowResize(GLFWwindow* window, int width, int height) override;
private:

    Transform& m_Transform;

    glm::mat4 m_ViewMatrix;
    glm::mat4 m_ProjectionMatrix;
};


#endif //OPENGLRENDERING_CAMERA_H
