CXX = clang++
CXXFlags = -lglut -lGLU -lGL -lX11
Exe = ./src/Mario/window.cpp ./src/Mario/main.cpp
OutDir = ./.out

main: $(Exe)
	$(CXX) $(Exe) -o main $(CXXFlags) -I./include/
