#ifndef GRAPHICS_RENDERER_H
#define GRAPHICS_RENDERER_H

#include <glut.h>
#include "Doggy.h"
#include "CallbacksDispatcher.h"

class Renderer
{
public:
    // Clears the current window and draws a triangle.
    static void Display()
    {
        const float clearColor[4] = { 0.81F, 0.91F, 0.15F, 1.0F };

        // set every pixel in the frame buffer to the current clear color.
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);

        const float doggySpeed = 5.0F;
        Vec2 doggyDeltaMove;

        // position shift on keystroke
        if (CallbacksDispatcher::IsKeyPressed('w'))
        {
            doggyDeltaMove.y += doggySpeed * deltaTime;
        }
        if (CallbacksDispatcher::IsKeyPressed('a'))
        {
            doggyDeltaMove.x += - doggySpeed * deltaTime;
        }
        if (CallbacksDispatcher::IsKeyPressed('s'))
        {
            doggyDeltaMove.y += - doggySpeed * deltaTime;
        }
        if (CallbacksDispatcher::IsKeyPressed('d'))
        {
            doggyDeltaMove.x += doggySpeed * deltaTime;
        }
        if (CallbacksDispatcher::IsKeyPressed('q'))
        {
            exit(0);
        }

        //set new vertices positions
        doggy.Move(doggyDeltaMove);

        // drawing a figure
        doggy.Display();
        doggy.DisplayGrid();

        // Swapping buffers i. e. submiting primitives to the OpenGL renderer
        glutSwapBuffers();
    }

    // sets redisplay window
    static void RequestUpdate(int = 0)
    {
        glutTimerFunc((int) (deltaTime * 1000.0F), RequestUpdate, 0);
        glutPostRedisplay();
    }
private:
    inline static Doggy doggy;
    static const int framesTarget = 60;
    constexpr static const float deltaTime = 1.0F / framesTarget;
};
#endif //GRAPHICS_RENDERER_H
