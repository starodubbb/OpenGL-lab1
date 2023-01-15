cmake_minimum_required(VERSION 3.17)
project(Graphics)

set(CMAKE_CXX_STANDARD 17)

include_directories(vendors/include/GLUT)
link_directories(vendors/lib/GLUT)

include_directories(vendors/include)

add_executable(Graphics main.cpp src/CallbacksDispatcher.h src/Doggy.h src/Structs.h src/Renderer.h)

target_link_libraries(Graphics OpenGL32.lib freeglut)
