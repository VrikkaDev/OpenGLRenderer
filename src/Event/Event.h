//
// Created by VrikkaDev on 30/03/2023.
//

#ifndef OPENGLRENDERING_EVENT_H
#define OPENGLRENDERING_EVENT_H

#include "pch.h"

class Event{

};

struct WindowEvent{
    WindowEvent();
    virtual void OnWindowResize(GLFWwindow* window, int width, int height){};
};
class WindowEventDispatcher{
public:
    static void AddReciever(WindowEvent* event);
    static void DispatchWindowResize(GLFWwindow* window, int width, int height);
    static std::vector<WindowEvent*> m_WRecievers;
};

#endif //OPENGLRENDERING_EVENT_H
