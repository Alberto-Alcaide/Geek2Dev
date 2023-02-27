#include "Mouse.h"

const Vec2D &Mouse::getPosition() const
{
    return position;
}

const Vec2D &Mouse::getPrevPosition() const
{
    return prevPosition;
}

void Mouse::updatePosition(int x, int y)
{
    prevPosition = position;
    position = Vec2D(x, y);
}
