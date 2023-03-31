//
// Created by VrikkaDev on 31/03/2023.
//

#ifndef DUCKENGINE_1_KEYBOARD_H
#define DUCKENGINE_1_KEYBOARD_H

#include "pch.h"

class Keyboard {
public:
    Keyboard(GLFWwindow* window);
    bool GetKey(int keycode);
private:
    GLFWwindow* m_Window;
};


#endif //DUCKENGINE_1_KEYBOARD_H
