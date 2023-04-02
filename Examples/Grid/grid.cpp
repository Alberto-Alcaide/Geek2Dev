#include "Engine2D.h"

int main(int argc, char *args[])
{
    int width=800;
    int height=800;
    Engine2D engine(width, height);
    int gridSize = 50;
    int radius = gridSize * 0.5;

    const auto circle = engine.world.create();
    engine.world.emplace<TransformComponent>(circle, Vec2D(425,425));
    engine.world.emplace<GridMovementComponent>(circle, gridSize);

    const auto enemy = engine.world.create();
    engine.world.emplace<TransformComponent>(enemy, Vec2D(225,425));
    engine.world.emplace<GridMovementComponent>(enemy, gridSize);
  

    while (engine.nextFrame())
    {
        engine.update();

        Graphics::drawGrid(gridSize);
        const auto circleTransformComp =  engine.world.get<TransformComponent>(circle);
        const auto enemyTransformComp =  engine.world.get<TransformComponent>(enemy);

        Graphics::drawFillCircle(
            circleTransformComp.position.x, 
            circleTransformComp.position.y, 
            radius, 
            Color::white()
        );

        Graphics::drawFillCircle(
            enemyTransformComp.position.x, 
            enemyTransformComp.position.y, 
            radius, 
            Color::red()
        );

        engine.render();
    }

    return 0;
}