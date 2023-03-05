#include "Engine2D.h"
#include <cmath>
#include <string>

int main()
{

    std::cout << "Color rojo: " << Color::red() << "\n";
    std::cout << "Color verde: " << Color::green() << "\n";
    std::cout << "Color azul: " << Color::blue() << "\n";
    std::cout << "Color Negro: " << Color::black() << "\n";

    std::cout <<"White(255,255,255,1) in hexadecimal is: " << std::hex << Color::white().getColorRGB32() << std::endl;

    return 0;
}

