#include "Force.h"

Vec2D Force::generateDragVector(float k, Vec2D velocity)
{
    Vec2D dragForce = Vec2D(0,0);

    if(velocity.magnitudeSquared() > 0)
    {
        // Calculates drag direction (inverse of velocity unit vector)
        Vec2D dragDirection = velocity.unitVector()*-1;

        // Calculate the drag magnitude, k * |v|^2
        float dragMagnitude = k * velocity.magnitudeSquared();

        // Generate the final drag force with direction and magnitude
        dragForce = dragDirection * dragMagnitude;
    }

    return dragForce;
}

Vec2D Force::generateSpringVector(Vec2D position, Vec2D anchor, float restLeng, float k)
{
    Vec2D d = position - anchor;
    float displacement = d.magnitude() - restLeng;
    Vec2D springDirection = d.unitVector();
    float springMagnitude = -k*displacement;
    Vec2D springForce = springDirection * springMagnitude;
    return springForce;
}
