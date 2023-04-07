//
// Created by VrikkaDev on 31/03/2023.
//

#ifndef OPENGLRENDERING_KEYBOARD_H
#define OPENGLRENDERING_KEYBOARD_H

#include "pch.h"

class Keyboard {
public:
    Keyboard(GLFWwindow* window);
    bool GetKey(int keycode);
private:
    GLFWwindow* m_Window;
};


#endif //OPENGLRENDERING_KEYBOARD_H
