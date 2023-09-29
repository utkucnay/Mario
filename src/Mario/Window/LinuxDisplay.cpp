#include "Window/LinuxDisplay.h"

GLint       att[5] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };

LinuxDisplay::LinuxDisplay() {
    _display = XOpenDisplay(NULL);

    if (_display == NULL) {
        printf("Dont init Display\n");
    }

    int screen = DefaultScreen(_display);

    if(gladLoadGLX(_display, screen)) {
        printf("error");
    }

    _rootWindow = DefaultRootWindow(_display);
    m_xVI = glXChooseVisual(_display, 0, att);

    if (m_xVI == NULL) {
        printf("Dont init Visual Info\n");
    }

    m_colorMap = XCreateColormap(_display, _rootWindow,
            m_xVI->visual, AllocNone);

    _glxContext = glXCreateContext(_display, m_xVI, NULL, GL_TRUE);

}

LinuxDisplay::~LinuxDisplay() {
    glXMakeCurrent(_display, None, NULL);
    glXDestroyContext(_display, _glxContext);

    XFree(m_xVI);
    XFreeColormap(_display, m_colorMap);

    for(auto& window : m_windows)
        XDestroyWindow(_display, window._Window);

    XCloseDisplay(_display);
}

LinuxWindow* LinuxDisplay::CreateWindow(unsigned int width,
            unsigned int height, const std::string& name) {

    XSetWindowAttributes swa = XSetWindowAttributes();
    swa.colormap = m_colorMap;

    Window window = XCreateWindow(_display, _rootWindow, 0, 0, width, height, 0,
            m_xVI->depth, InputOutput,
            m_xVI->visual,
            CWColormap | CWEventMask, &swa);

    XMapWindow(_display, window);
    XStoreName(_display, window, name.c_str());

    LinuxWindow* lWindow = new LinuxWindow(window, this);

    lWindow->glMakeCurrent();

    int gl_version = gladLoadGL();
    if (!gl_version) {
        printf("Unable to load GL.\n");
    }

    return lWindow;
}
