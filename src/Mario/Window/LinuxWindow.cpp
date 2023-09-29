#include "Window/LinuxWindow.h"

LinuxWindow::LinuxWindow(Window window, LinuxDisplay* linuxDisplay) {
    _Window = window;
    m_linuxDisplay = linuxDisplay;
}

LinuxWindow::~LinuxWindow() {

}

void LinuxWindow::glMakeCurrent() {
    glXMakeCurrent(m_linuxDisplay->_display,
            _Window, m_linuxDisplay->_glxContext);
}

void LinuxWindow::glSwapBuffers() {
    glXSwapBuffers(m_linuxDisplay->_display, _Window);
}
