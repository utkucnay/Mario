#pragma once

#include <X11/X.h>

#include "window/LinuxDisplay.h"
class LinuxDisplay;

class LinuxWindow {
public:
    LinuxWindow(LinuxWindow &&)                 = delete;
    LinuxWindow(const LinuxWindow &)            = delete;
    LinuxWindow &operator=(LinuxWindow &&)      = delete;
    LinuxWindow &operator=(const LinuxWindow &) = delete;
    LinuxWindow(Window window, LinuxDisplay* linuxDisplay);
    ~LinuxWindow();

public:
    void glMakeCurrent();
    void glSwapBuffers();

public:
    Window          _Window;
private:
    LinuxDisplay*    m_linuxDisplay;
    friend class LinuxDisplay;
};
