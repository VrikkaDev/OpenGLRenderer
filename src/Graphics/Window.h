//
// Created by VrikkaDev on 29/03/2023.
//

#ifndef DUCKENGINE_1_WINDOW_H
#define DUCKENGINE_1_WINDOW_H

#include "pch.h"
#include "Event/Event.h"
#include "Input/Keyboard.h"

class Window {
public:
    Window(uint32_t width, uint32_t height, const char* title);
    void SwapBuffers();
    void Destroy();

    bool IsRunning = false;

    glm::vec2 GetWindowSize();

    static Window* Instance(){
        return m_Instance;
    }

    Keyboard* keyboard;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void resize_callback(GLFWwindow* window, int w, int h);
private:
    GLFWwindow* m_Window;
    glm::vec2 m_WindowSize;

    static Window* m_Instance;
};


#endif //DUCKENGINE_1_WINDOW_H
