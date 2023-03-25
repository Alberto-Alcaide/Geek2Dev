#ifndef RIGIDBODYCOMPONENT_H
#define RIGIDBODYCOMPONENT_H

#include "CircleShape.h"
#include "Vec2D.h"


struct RigidBodyComponent
{
    // Mass
    float mass;
    float invMass;
    float inertia;
    float invInertia;

    // Forces and torques
    Vec2D sumForces;
    float sumTorques;

    // Shapes
    CircleShape* circleShape;

    RigidBodyComponent(float mass, CircleShape circleShape)
    {
        this->circleShape = circleShape.Clone();
        this->mass = mass;

        if (mass != 0.0)
        {
            this->invMass = 1.0 / mass;
        } 
        else
        {
            this->invMass = 0.0;
        }

        inertia = circleShape.GetMomentOfInertia() * mass;

        if (inertia != 0.0)
        {
            this->invInertia = 1.0 / inertia;
        } 
        else
        {
            this->invInertia = 0.0;
        }

        this->sumForces = Vec2D(0,0);
        this->sumTorques = 0.0;
    }


    void AddForce(const Vec2D& force)
    {
        sumForces +=force;
    }

    void ClearForces()
    {
        sumForces = Vec2D(0.0, 0.0);
    }

    void AddTorque(float torque)
    {
        sumTorques += torque;
    }

    void ClearTorque()
    {
        sumTorques = 0.0;
    }
};

#endif