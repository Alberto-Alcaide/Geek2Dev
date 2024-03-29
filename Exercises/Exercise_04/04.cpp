#include "Engine2D.h"
#include <cmath>
#include <string>

struct object{
    Vec2D position;
    int radius;
    int height;
    int width;
    Color color;
} player, enemy;

int main(int argc, char *args[])
{

    // Initialize game engine
    Engine2D engine(640, 400);
    

    // Entities initialization
    player.height = 10;
    player.width = 10;
    player.position = Vec2D(10,10);
    player.color = Color::blue();
    enemy.height = 10;
    enemy.width = 10;
    enemy.position = Vec2D(400, 200);
    enemy.color = Color::red();

while (engine.nextFrame())
    {
        engine.update();

        player.position = engine.mouse->position;

        // int x, int y, int radius, Color color
        Graphics::drawFillRect(player.position.x, player.position.y, player.width, player.height, player.color);
        Graphics::drawRect(enemy.position.x, enemy.position.y, enemy.width, enemy.height, enemy.color);

        engine.render();
        
    }
    engine.~Engine2D();

    return 0;
}
