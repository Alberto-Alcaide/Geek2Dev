#include "Engine2D.h"
#include <cmath>
#include <string>

struct object{
    Vec2D position;
    int height;
    int width;
    Color color;
} player, enemy;
#define PI 3.14159265358979323846
int main(int argc, char *args[])
{
    // Initialize game engine
    Engine2D engine(640, 400);
    

    // Entities initialization
    Vec2D player_speed(50,50);
    player.height = 10;
    player.width = 10;
    player.position = Vec2D(10,10);
    player.color = Color::blue();
    enemy.height = 10;
    enemy.width = 10;
    enemy.position = Vec2D(400, 200);
    enemy.color = Color::red();
    Vec2D dirfov_enemy = Vec2D(1,0);//the direction of the eyes
    float fov_enemy=2*PI/3;//this is the angle from dirfov_enemy that he can see

    while (engine.nextFrame())
    {
        engine.update();

        // Code of the game
        Vec2D direction = player.position-enemy.position;

        // we need to chose if the enemy is gonna move or not, that depends of the dot product of the dirfov_enemy and direction
        if(dirfov_enemy.normalize().dotProduct(direction.normalize()) > cos(fov_enemy/2)){
            // We normalize de vector in order to make the velocity const
            Log::Info("i see you");
            enemy.position += player_speed*direction.normalize() * engine.getDeltaTime(); 
        }else{
            Log::Warning("i dont see you");
        }

        player.position = engine.mouse->position;

        // int x, int y, int radius, Color color
        Graphics::drawFillRect(player.position.x, player.position.y, player.width, player.height, player.color);
        Graphics::drawRect(enemy.position.x, enemy.position.y, enemy.width, enemy.height, enemy.color);

        engine.render();
        
    }
    engine.~Engine2D();

    return 0;

}