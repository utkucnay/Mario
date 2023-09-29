#pragma once

#include "Window/LinuxDisplay.h"
#include "Window/LinuxWindow.h"

class Application {
public:
    Application(Application &&) = delete;
    Application(const Application &) = delete;
    Application &operator=(Application &&) = delete;
    Application &operator=(const Application &) = delete;
    Application();
    ~Application();

public:
    void Update();
    bool ShouldClose();
    void EventHandle();
    void Exit();

private:
    LinuxDisplay* m_display;
    LinuxWindow* m_window;
};
