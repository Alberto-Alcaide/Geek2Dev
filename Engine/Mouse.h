#ifndef MOUSE_H
#define MOUSE_H
#include "Vec2D.h"


struct Mouse
{
    Vec2D position;
    Vec2D prevPosition;

    bool leftButtonPressed = false;
    bool rightButtonPressed = false;

    Mouse() = default;
    ~Mouse() = default;

    const Vec2D& getPosition() const;
    const Vec2D& getPrevPosition() const;
    void updatePosition(int x, int y);
};



#endif