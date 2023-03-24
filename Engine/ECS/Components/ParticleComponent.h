#ifndef PARTICLECOMPONENT_H
#define PARTICLECOMPONENT_H

#include "Vec2D.h"
#include "Graphics.h"

struct ParticleComponent
{
    float mass;
    float invMass;
    int radius;
    Color color;
    Vec2D sumForces;

    ParticleComponent(float mass = 1.0, int radius = 1, Color color= Color::white())
    {
        this->mass = mass;

        if (mass != 0.0)
        {
            this->invMass = 1.0 / mass;
        }
        else
        {
            this->invMass = 0.0;
        }
        
        this->radius = radius;
        this->color = color;
        this->sumForces = Vec2D(0, 0);
    }

    void AddForce(const Vec2D& force)
    {
        sumForces += force;
    }

    Vec2D getSumForce()
    {
        return sumForces;
    }
    void ClearForces()
    {
        sumForces = Vec2D(0.0, 0.0);
    }
};


#endif