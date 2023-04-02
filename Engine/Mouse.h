#ifndef mouseH
#define mouseH
#include "Vec2D.h"


struct Mouse
{
    Vec2D position;
    Vec2D prevPosition;

    bool leftButtonPressed = false;
    bool rightButtonPressed = false;

    Mouse() = default;
    ~Mouse() = default;

    inline void updatePosition(int x, int y)
    {
        prevPosition = position;
        position = Vec2D(x, y);
    }
};



#endif