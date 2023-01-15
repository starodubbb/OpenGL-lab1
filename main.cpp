#include <array>
#include <chrono>
#include <iostream>

#include "glut.h"
#include "src/CallbacksDispatcher.h"
#include "src/Doggy.h"
#include "src/Renderer.h"

int main(int argc, char** argv)
{
    //parameters of window
    const char name[] = "Name";
    const int w = 600, h = 600;

    //initialize the GLUT library
    glutInit(&argc, argv);

    //sets initial window position and size
    glutInitWindowSize(w, h);
    glutInitWindowPosition(0, 0);

    //sets initial display mode (single buffered window | RGBA mode window)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    //create window
    glutCreateWindow(name);

    //default state of keyboard keys 
    CallbacksDispatcher::Init();

    // sets GLUT display (render) function. Called on every glutPostRedisplay()
    glutDisplayFunc(Renderer::Display);

    // sets GLUT key press/release callback
    glutKeyboardFunc(CallbacksDispatcher::KeyPressCallback);
    glutKeyboardUpFunc(CallbacksDispatcher::KeyReleaseCallback);

    // sets redisplay window
    Renderer::RequestUpdate();

    // glut main loop: sets window active
    glutMainLoop();
}