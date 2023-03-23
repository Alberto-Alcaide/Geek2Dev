#ifndef RIGIDBODYCOMPONENT_H
#define RIGIDBODYCOMPONENT_H

#include "Vec2D.h"

struct RigidBodyComponent
{
    // Mass
    float mass;
    float invMass;
    float I;
    float invI;
};







#endif