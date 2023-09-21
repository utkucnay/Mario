CXX = clang++
CXXFlags = -lglut -lGLU -lGL -lX11
Exe = ./src/Mario/window/LinuxWindow.cpp ./src/Mario/window/LinuxDisplay.cpp ./src/Mario/main.cpp ./src/Mario/application.cpp
OutDir = ./.out

main: $(Exe)
	$(CXX) $(Exe) -o $(OutDir)/main $(CXXFlags) -I./include/
