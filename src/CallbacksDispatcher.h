#ifndef GRAPHICS_CALLBACKSDISPATCHER_H
#define GRAPHICS_CALLBACKSDISPATCHER_H

#include <iostream>
#include <array>

class CallbacksDispatcher
{
public:
    static void Init() 
    {
        pressedKeys.fill(false);
    }

    static void KeyReleaseCallback(unsigned char key, int, int)
    {
        pressedKeys[key] = false;
    }

    static void KeyPressCallback(unsigned char key, int, int)
    {
        pressedKeys[key] = true;
    }

    static bool IsKeyPressed(unsigned char Key)
    {
        return pressedKeys[Key];
    }

private:
    inline static std::array<bool, 256> pressedKeys;
};

#endif //GRAPHICS_CALLBACKSDISPATCHER_H
