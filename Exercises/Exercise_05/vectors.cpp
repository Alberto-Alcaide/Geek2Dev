#include <iostream>
#include "Vec2D.h"

int main()
{
    Vec2D v1(1,1);
    Vec2D v2(1,1);

    std::cout << "v1 = " << v1 << ", v2 = " << v2 << std::endl;

    std::cout << "v1 + v2: " << v1 + v2 << std::endl;
    std::cout << "v1 - v2: " << v1 - v2 << std::endl;
    std::cout << "v1 * v2: " << v1 * v2 << std::endl;
    std::cout << "v2 scale(2): " << v2.scale(2) << std::endl;
    std::cout << "v1 * 2: " << v1 * 2 << std::endl;

    std::cout << "v1 magnitude =  " << v1.magnitude() << std::endl;
    std::cout << "v1 magnitude squared = " << v1.magnitudeSquared() << std::endl;
    std::cout << "v1 angle =  " << v1.angle() << std::endl;



    return 0;
}