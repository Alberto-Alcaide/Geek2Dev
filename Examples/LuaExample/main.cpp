#include "Engine2D.h"
#include <sol/sol.hpp>
#include <iostream>

void TestLua()
{
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script_file("./myfirstscript.lua");

    int someVariableInsideCpp = lua["some_variable"];
    std::cout << "The value of some_variable in C++ is "
                << someVariableInsideCpp << std::endl;
    
    bool isFullScreen = lua["config"]["fullscreen"];
    sol::table config = lua["config"];
    int width = config["resolution"]["width"];
    int height = config["resolution"]["height"];
    std::cout << "We read the value fullscreen:" << isFullScreen
                << ", width:" << width
                << ", height:" << height
                << std::endl;
}

int main(int argc, char* argv[])
{
    TestLua();
    return 0;
}