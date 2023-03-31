//
// Created by VrikkaDev on 31/03/2023.
//

#include "Keyboard.h"

Keyboard::Keyboard(GLFWwindow* window) {
    m_Window = window;
}

bool Keyboard::GetKey(int keycode) {
    return glfwGetKey(m_Window, keycode);
}
