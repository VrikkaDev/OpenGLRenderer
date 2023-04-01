//
// Created by VrikkaDev on 30/03/2023.
//

#include "Camera.h"

Camera::Camera(Transform& mTransform) : m_Transform(mTransform) {
    UpdateProjection(Window::Instance()->GetWindowSize().x, Window::Instance()->GetWindowSize().y);
}

void Camera::UpdateView() {
    // Create rotation matrix from quaternion
    glm::mat4 matrix(1.f);
    glm::mat3 rot = glm::mat3_cast(m_Transform.GetQuat());

    // Translate matrix by the inverse of camera position
    matrix = glm::translate(matrix, -m_Transform.Position);

    // Compute view matrix by multiplying rotation and translation matrices
    m_ViewMatrix = glm::mat4(rot) * matrix;

    // Load view matrix to current OpenGL matrix
    //glLoadMatrixf(glm::value_ptr(m_ViewMatrix));
}

void Camera::UpdateProjection(uint32_t width, uint32_t height) {
    float aspect_ratio = width/height;

    // Compute projection matrix using perspective projection
    m_ProjectionMatrix = glm::perspective(glm::radians(Fov), aspect_ratio, NearPlane, FarPlane);
}

void Camera::RenderBackground(float r, float g, float b, float a) {
    // Set clear color
    glClearColor(r,g,b,a);
    // Clear color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

glm::mat4 Camera::GetViewMatrix() {
    return m_ViewMatrix;
}

glm::mat4 Camera::GetProjectionMatrix() {
    return m_ProjectionMatrix;
}

glm::mat4 Camera::GetViewProjectionMatrix() {
    return m_ProjectionMatrix * m_ViewMatrix;
}

void Camera::OnWindowResize(GLFWwindow* window, int width, int height) {
    // Update projection matrix on window resize
    UpdateProjection(width, height);
}
