#include "application.h"
#include <GL/gl.h>
#include <X11/Xlib.h>

Application::Application() {
    m_display = new LinuxDisplay();
    m_window = m_display->CreateWindow(800, 600, "Mario");
    m_window->glMakeCurrent();
}

Application::~Application() {

}

void Application::Update() {
    while(1) {
        glClearColor(0, 0, 0, 1);
        m_window->glSwapBuffers();
    }
}

void Application::Exit() {
    delete m_display;
}

void Application::EventHandle() {
    XEvent event;
    XNextEvent(m_display->_display, &event);
}
