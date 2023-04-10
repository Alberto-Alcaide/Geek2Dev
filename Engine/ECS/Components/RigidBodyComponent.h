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
    float restitution; // elasticity

    // Forces and torques
    Vec2D sumForces;
    float sumTorques;

    // Shapes
    Shape* shape;

    RigidBodyComponent(float mass, const Shape& shape, float restitution)
    {
        this->restitution=restitution; //Adding elasticity
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

        inertia = shape.GetMomentOfInertia() * mass;

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

    bool IsStatic() const
    {
        const float epsilon = 0.005f;
        return fabs(invMass - 0.0) <epsilon;
    }
};



#endif