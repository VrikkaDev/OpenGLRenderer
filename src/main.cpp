#define STB_IMAGE_IMPLEMENTATION
#include "pch.h"
#include "Graphics/Window.h"
#include "Transform.h"
#include "Graphics/Camera.h"
#include "Graphics/Shader.h"
#include "Graphics/Mesh.h"
#include "Graphics/Model.h"
#include "Graphics/MeshLoader.h"
#include "Graphics/Light.h"

int main() {

    Window window = Window(640, 480, "Bread is tasty");

    Transform cameraTransform = Transform();
    // Makes it so the camera doesnt spawn on 0, 0, 0
    cameraTransform.Position += cameraTransform.FORWARD() * 2.f;
    Camera camera = Camera(cameraTransform);

    // Create light with transform and color
    Transform lightTransform = Transform();
    lightTransform.Position.y += 2;
    glm::vec3 lightColor = {1.f,0.2f,0.5f};
    CubeLight light = CubeLight(lightTransform, lightColor);

    // Create Material variable for the model
    Material material = Material();

    // Create a cube mesh and a model with the loaded shader and mesh
    Mesh mesh = *MeshLoader::LoadMesh("../Assets/Meshes/Knight.obj");
    Model model = Model(mesh, material);

    Transform* modelTransform = new Transform();

    Mesh mesh2 = *MeshLoader::LoadMesh("../Assets/Meshes/kinghhhht.obj");
    Model model2 = Model(mesh2, material);

    Transform* model2transform = new Transform();
    model2transform ->Position.x = 5;

    // Set the movement speed for the camera
    float movementSpeed;
    float yaw = 0.f, pitch = 0.f;

    // Run the game loop
    while(window.IsRunning){
        // Render a background color
        camera.RenderBackground(0.1f, 0.7f, 0.6f, 1.0f);

        // Move camera with keyboard input
        movementSpeed = window.keyboard->GetKey(GLFW_KEY_LEFT_SHIFT) ? 0.05f : 0.01f;

        if(window.keyboard->GetKey(GLFW_KEY_W)){
            cameraTransform.Position += cameraTransform.FORWARD() * -movementSpeed;
        }else if(window.keyboard->GetKey(GLFW_KEY_S)){
            cameraTransform.Position += cameraTransform.FORWARD() * movementSpeed;
        }

        if(window.keyboard->GetKey(GLFW_KEY_A)) {
            cameraTransform.Position += cameraTransform.RIGHT() * -movementSpeed;
        }else if(window.keyboard->GetKey(GLFW_KEY_D)){
            cameraTransform.Position += cameraTransform.RIGHT() * movementSpeed;
        }

        if(window.keyboard->GetKey(GLFW_KEY_E)) {
            cameraTransform.Position += cameraTransform.UP * movementSpeed;
        }else if(window.keyboard->GetKey(GLFW_KEY_Q)){
            cameraTransform.Position += cameraTransform.UP * -movementSpeed;
        }

        // Change the camera yaw and pitch with keyboard input
        if(window.keyboard->GetKey(GLFW_KEY_UP)){
            pitch--;
            cameraTransform.Rotation.x = pitch;
        }else if(window.keyboard->GetKey(GLFW_KEY_DOWN)){
            pitch++;
            cameraTransform.Rotation.x = pitch;
        }

        if(window.keyboard->GetKey(GLFW_KEY_LEFT)){
            yaw--;
            cameraTransform.Rotation.y = yaw;
        }else if(window.keyboard->GetKey(GLFW_KEY_RIGHT)){
            yaw++;
            cameraTransform.Rotation.y = yaw;
        }

        // Update the camera view matrix
        camera.UpdateView();
        // Render the model with the current transform and camera
        model.Render(modelTransform, &camera);
        model2.Render(model2transform, &camera);

        // Swap the front and back buffers of the window to display the rendered frame
        window.SwapBuffers();
    }

    // Destroy the window and cleanup resources
    window.Destroy();

    return 0;
}
