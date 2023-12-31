#pragma once

#include<X11/X.h>
#include<X11/Xlib.h>
#include <X11/Xutil.h>
#include <vector>
#include <string>
#include "Window/LinuxWindow.h"
#include "OpenGL/GLAD/glad.h"
#include "OpenGL/GLAD/glad_glx.h"

class LinuxWindow;

class LinuxDisplay {
public:
    LinuxDisplay(LinuxDisplay &&)                 = delete;
    LinuxDisplay(const LinuxDisplay &)            = delete;
    LinuxDisplay &operator=(LinuxDisplay &&)      = delete;
    LinuxDisplay &operator=(const LinuxDisplay &) = delete;
    LinuxDisplay();
    ~LinuxDisplay();

public:
    LinuxWindow* CreateWindow(unsigned int width, unsigned int height, const std::string& name);

public:
    Display*    _display;
    Window      _rootWindow;
    GLXContext  _glxContext;
private:
    XVisualInfo *m_xVI;
    std::vector<LinuxWindow> m_windows;
    Colormap    m_colorMap;
};
