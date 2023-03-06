#include "Engine2D.h"

int main(int argc, char *args[])
{
    Engine2D engine(800,800);

    const auto ball= engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2D(400.0,400.0));
    engine.world.emplace<KinematicComponent>(ball, Vec2D(0, -200), Vec2D(0, 100));
    int radius=40;

    while(engine.nextFrame())
    {
        engine.update();

        // Code of example
        // The kinematic system is updating the positing behind the scenes
        const auto transform = engine.world.get<TransformComponent>(ball);
        Graphics::drawFillCircle(transform.position.x, transform.position.y, radius, Color::blue());

        engine.render();
    }



    return 0;
}