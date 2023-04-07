#include "pch.h"
#include "Graphics/Window.h"
#include "Transform.h"
#include "Graphics/Camera.h"
#include "Graphics/Shader.h"
#include "Graphics/Mesh.h"
#include "Graphics/Model.h"
#include "Graphics/MeshLoader.h"

int main() {

    Window window = Window(640, 480, "Bread is tasty");

    Transform cameraTransform = Transform();
    // Makes it so the camera doesnt spawn on 0, 0, 0
    cameraTransform.Position += cameraTransform.FORWARD() * 2.f;
    Camera camera = Camera(cameraTransform);

    // Load the vertex and fragment shaders from file
    Shader shader = Shader("Assets/Shaders/vertex.glsl", "Assets/Shaders/fragment.glsl");

    // Create a cube mesh and a model with the loaded shader and mesh
    Mesh mesh = *MeshLoader::LoadMesh("C:/Users/veikk/CLionProjects/OpenGLRenderer/Assets/Meshes/Knight.obj");
    Model model = Model(mesh, shader);

    Transform* modelTransform = new Transform();

    // Set the movement speed for the camera
    float movementSpeed;
    float yaw = 0.f, pitch = 0.f;

    // Run the game loop
    while(window.IsRunning){
        // Render a background color
        camera.RenderBackground(0.5f, 0.3f, 0.3f, 1.0f);

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

        // Swap the front and back buffers of the window to display the rendered frame
        window.SwapBuffers();
    }

    // Destroy the window and cleanup resources
    window.Destroy();

    return 0;
}
