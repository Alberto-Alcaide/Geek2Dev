/**
 * This file tests some functionalities of the Vec2D struct
 */

#include <iostream>
#include "Vec2D.h"

int main()
{

    Vec2D v1;
    Vec2D v2(1,1);
    v1 = v2;

    std::cout << "v1 = " << v1 << ", v2 = " << v2 << std::endl;

    std::cout << "a.dot(b) = " << v1.dotProduct(v2) << std::endl;

    std::cout << "v1 + v2: " << v1 + v2 << std::endl;
    std::cout << "v1 - v2: " << v1 - v2 << std::endl;
    std::cout << "v1 * v2: " << v1 * v2 << std::endl;

    v2.scale(2);
    std::cout << "v2.scale(2): " << v2 << std::endl;
    std::cout << "lerp(a, b, 0.3) = " << Vec2D::lerp(v1, v2, 0.3) << std::endl;
    std::cout << "v1 * 2: " << v1 * 2 << std::endl;

    std::cout << "v1 magnitude =  " << v1.magnitude() << std::endl;
    std::cout << "v1 magnitude squared = " << v1.magnitudeSquared() << std::endl;
    std::cout << "v1 angle =  " << v1.angle() << std::endl;
    std::cout << "from module(4) and angle(45): " << Vec2D::fromModuleAngle(4, 45) << std::endl;


    return 0;
}