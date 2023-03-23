#ifndef RIGIDBODYCOMPONENT_H
#define RIGIDBODYCOMPONENT_H

#include "Shape.h"
#include "Vec2D.h"
#include "RigidBodyComponent.h"

struct RigidBodyComponent
{
    // Mass
    float mass;
    float invMass;
    float I;
    float invI;

    // Forces and torques
    Vec2D sumForces;
    float sumTorques;

    Shape* shape;

    RigidBodyComponent(float mass, float I, Shape shape)
    {
        this->shape = shape.Clone();
        this->mass = mass;
        if (mass != 0.0)
        {
            this->invMass = 1.0 / mass;
        } 
        else
        {
            this->invMass = 0.0;
        }
        I = shape.GetMomentOfInertia() * mass;
        if (I != 0.0)
        {
            this->invI = 1.0 / I;
        } 
        else
        {
            this->invI = 0.0;
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