#include "Engine2D.h"

int main(int argc, char *args[])
{
    int width=800;
    int height=800;
    Engine2D engine(width, height);
    int gridSize = 50;
    int radius = gridSize * 0.5;


    // players
    const auto player1 = engine.world.create();
    engine.world.emplace<TransformComponent>(player1, Vec2D(425,425));
    engine.world.emplace<GridMovementComponent>(player1, gridSize);
    engine.world.emplace<NameGroupComponent>(player1, "player1", "players");

    // TODO spawn objects when key pressed
    
    while (engine.nextFrame())
    {
        engine.update();

        Graphics::drawGrid(gridSize);
        const auto player1TransformComp =  engine.world.get<TransformComponent>(player1);

        // draw players
        Graphics::drawFillCircle(
            player1TransformComp.position.x, 
            player1TransformComp.position.y, 
            radius, 
            Color::blue()
        );

 

        engine.render();
    }

    return 0;
}