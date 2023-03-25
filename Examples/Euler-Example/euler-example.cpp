#include "Engine2D.h"

int main(int argc, char *args[])
{
    double t = 0.0;
    float dt = 1.0/100.0;
    float velocity = 0.0f;
    float position = 0.0f;
    float force = 10.0f;
    float mass = 1.0f;

    while( t <= 10.0)
    {
        velocity = velocity + (force / mass) * dt;
        position = position + velocity * dt;

        t += dt;

        std::cout << "t = " << t << "  position = " << position << "  velocity = " << velocity << "\n";
    }

    return 0;
}

