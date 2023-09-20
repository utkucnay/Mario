#include "window/LinuxWindow.h"
#include <GL/gl.h>

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

int main(int argc, char *argv[]) {
    LinuxWindow* window = new LinuxWindow();

    unsigned int VBO;

    while (1) {
        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glXSwapBuffers(window->m_display, window->m_window);
    }

    delete window;
}
