//
// Created by VrikkaDev on 30/03/2023.
//

#include "Model.h"

Model::Model(Mesh& mesh, Material& material) : m_Mesh(mesh), m_Material(material){
}

void Model::Render(Transform* transform, Camera* camera) {
    // Bind the shader program for rendering
    m_Material.shader.Bind();

    // Create transformation matrix
    glm::mat4 matrix = transform->CreateTransformationMatrix();


    // Get view projection matrix from camera
    glm::mat4 vp = camera->GetViewProjectionMatrix();

    // Calculate model-view-projection matrix
    glm::mat4 mvp = vp * matrix;

    auto view = camera->GetViewMatrix();
    auto proj = camera->GetProjectionMatrix();
    auto trans = matrix;

    // Load the material variables to shader
    m_Material.Bind();

    // Load the matrices to the shader
    m_Material.shader.LoadUniform("viewMatrix", view);
    m_Material.shader.LoadUniform("projectionMatrix", proj);
    m_Material.shader.LoadUniform("transformationMatrix", trans);

    // Bind mesh and draw
    m_Mesh.Bind();

    glDrawElements(GL_TRIANGLES, m_Mesh.GetIndexCount(), GL_UNSIGNED_INT, (void*)nullptr);

    // UnBind mesh, material and shader program
    m_Mesh.UnBind();
    m_Material.UnBind();
    m_Material.shader.UnBind();
}
