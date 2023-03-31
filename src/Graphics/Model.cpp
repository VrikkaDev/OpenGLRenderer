//
// Created by VrikkaDev on 30/03/2023.
//

#include "Model.h"

Model::Model(Mesh& mesh, Shader& shader) : m_Mesh(mesh), m_Shader(shader){
}

void Model::Render(Transform* transform, Camera* camera) {
    // Bind the shader program for rendering
    m_Shader.Bind();

    // Create transformation matrix
    glm::mat4 matrix = transform->CreateTransformationMatrix();


    // Get view projection matrix from camera
    glm::mat4 vp = camera->GetViewProjectionMatrix();

    // Calculate model-view-projection matrix
    glm::mat4 mvp = vp * matrix;

    auto view = camera->GetViewMatrix();
    auto proj = camera->GetProjectionMatrix();
    auto trans = matrix;

    // Load the matrices to the shader
    m_Shader.LoadUniform("viewMatrix", view);
    m_Shader.LoadUniform("projectionMatrix", proj);
    m_Shader.LoadUniform("transformationMatrix", trans);

    // Bind mesh VAO and draw
    glBindVertexArray(m_Mesh.getVAO());
    //(m_Mesh.GetVertexCount()*sizeof(float))
    glDrawArrays(GL_TRIANGLES, 0, m_Mesh.GetVertexCount());

    // Unbind mesh VAO and shader program
    glBindVertexArray(0);
    m_Shader.UnBind();
}
