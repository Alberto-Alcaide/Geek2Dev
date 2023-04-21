#include "Engine2D.h"
#include <sol/sol.hpp>
#include <iostream>

void TestLua()
{
    sol::state lua;
    //lua.open_libraries(sol::lib::base);
    lua.script_file("./myfirstscript.lua");

    // Declare a variable to hold the entire lua table and its nested values
    sol::table gamePrices = lua["game_prices"];

    // Directly fetch values from inside the Lua table using square-brackets notation
    double nintendoPrice = gamePrices["nintendo_price"];
    double playstationPrice = gamePrices["playstation_price"];

    // We can first check if the value exists using a sol::optional
    sol::optional<double> gameboyPrice = lua["game_prices"]["gameboy_price"];
    if (gameboyPrice != sol::nullopt)
    {
        // Only perform something if the value exists
        std::cout << "gameboyPrice exists" << std::endl;
        double gameboyPrice1= gamePrices["gameboy_price"];
        std::cout << "Gameboy: " << gameboyPrice1 << std::endl; 
    }

    // Another option is to use the get_or() function to define a default value;
    double xboxPrice = lua["game_prices"]["xbox_prices"].get_or(0.0);

    std::cout << "Nintendo: " << nintendoPrice << std::endl;
    std::cout << "Playstation: " << playstationPrice << std::endl;
    std::cout << "Xbox: " << xboxPrice << std::endl;
/*
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
*/
}

int main(int argc, char* argv[])
{
    TestLua();
    return 0;
}