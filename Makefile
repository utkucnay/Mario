CXX = clang++
CXXFlags = -lglut -lGLU -lGL -lX11
Exe = ./src/Mario/Window/LinuxWindow.cpp ./src/Mario/Window/LinuxDisplay.cpp ./src/Mario/main.cpp ./src/Mario/Application.cpp ./src/Mario/OpenGL/GLAD/glad.c ./src/Mario/OpenGL/GLAD/glad_glx.c
OutDir = ./.out

main: $(Exe)
	$(CXX) $(Exe) -o $(OutDir)/main $(CXXFlags) -I./include/
