#include "Engine2D.h"


struct object{
    Vec2D position;
    int radius;
    Color color;
} player, enemy;

int main(int argc, char *args[])
{
    // Initialize game engine
    Engine2D engine(640, 400);
    

    // Entities initialization
    player.radius = 5;
    player.position = Vec2D(10,10);
    player.color = Color::blue();
    enemy.radius = 5;
    enemy.position = Vec2D(400, 400);
    enemy.color = Color::red();

    while (engine.nextFrame())
    {
        engine.update();

        // Code of the game
        Vec2D direction = player.position-enemy.position;

        // We normalize de vector in order to make the velocity const
        enemy.position += direction.normalize() * engine.getDeltaTime(); 

        player.position = engine.mouse->position;

        // int x, int y, int radius, Color color
        Graphics::drawFillCircle(player.position.x, player.position.y,player.radius,player.color);
        Graphics::drawFillCircle(enemy.position.x, enemy.position.y,enemy.radius,enemy.color);

        engine.render();
        
    }
    engine.~Engine2D();

    return 0;

}