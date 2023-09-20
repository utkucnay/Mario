#include "window/LinuxWindow.h"
#include <GL/gl.h>
#include <GL/glx.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <cstdio>

LinuxWindow::LinuxWindow() {
    m_display = XOpenDisplay(NULL);

    if (m_display == NULL) {
        printf("Cant connect to X server");
    }

    m_rootWindow = DefaultRootWindow(m_display);
    m_xVisualInfo = glXChooseVisual(m_display, 0, m_att);

    if (m_xVisualInfo == NULL) {
        printf("No Visual Found");
    }

    m_colorMap = XCreateColormap(m_display, m_rootWindow,
            m_xVisualInfo->visual, AllocNone);

    m_swa.colormap = m_colorMap;

    m_window = XCreateWindow(m_display, m_rootWindow, 0, 0, 800, 600, 0,
            m_xVisualInfo->depth, InputOutput,
            m_xVisualInfo->visual,
            CWColormap | CWEventMask, &m_swa);

    XMapWindow(m_display, m_window);
    XStoreName(m_display, m_window, "Mario");

    m_glxContext = glXCreateContext(m_display, m_xVisualInfo, NULL, GL_TRUE);
    glXMakeCurrent(m_display, m_window, m_glxContext);
}

LinuxWindow::~LinuxWindow() {
    glXMakeCurrent(m_display, None, NULL);
    glXDestroyContext(m_display, m_glxContext);
    XDestroyWindow(m_display, m_window);
    XCloseDisplay(m_display);
}

void LinuxWindow::ConnectGL() {

}


