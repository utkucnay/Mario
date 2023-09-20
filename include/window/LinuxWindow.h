#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>
#include <X11/Xutil.h>

class LinuxWindow {
public:
    LinuxWindow(LinuxWindow &&)                 = delete;
    LinuxWindow(const LinuxWindow &)            = delete;
    LinuxWindow &operator=(LinuxWindow &&)      = delete;
    LinuxWindow &operator=(const LinuxWindow &) = delete;
    LinuxWindow();
    ~LinuxWindow();

public:
    void CreateWindow(int height, int widthsss);
    void ConnectGL(void);

public:
    Display*    m_display;
    Window      m_window;
private:
    Window      m_rootWindow;
    GLint       m_att[5] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
    XVisualInfo* m_xVisualInfo;
    Colormap    m_colorMap;
    XSetWindowAttributes    m_swa;
    GLXContext  m_glxContext;
    XWindowAttributes m_windowAtr;
};
