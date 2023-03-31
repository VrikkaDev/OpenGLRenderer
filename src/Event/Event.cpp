//
// Created by VrikkaDev on 30/03/2023.
//

#include "Event.h"

std::vector<WindowEvent*> WindowEventDispatcher::m_WRecievers;

WindowEvent::WindowEvent() {
    // Register this event as a receiver
    WindowEventDispatcher::AddReciever(this);
}

void WindowEventDispatcher::AddReciever(WindowEvent* event) {
    // Add the receiver to the vector of receivers
    m_WRecievers.push_back(event);
}

// Method to dispatch a window resize event to all receivers
void WindowEventDispatcher::DispatchWindowResize(GLFWwindow* window, int width, int height) {
    // Loop through all the registered receivers and call their OnWindowResize method
    for(WindowEvent* event : m_WRecievers){
        event->OnWindowResize(window, width, height);
    }
}
