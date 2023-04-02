#include "Engine2D.h"

int main(int argc, char *args[])
{
    Engine2D engine(800,800);

    // Creates an object in our world
    const auto ball = engine.world.create();

    // Attaches components to an object
    engine.world.emplace<TransformComponent>(ball, Vec2D(400.0,100.0));
    engine.world.emplace<KinematicsComponent>(ball, Vec2D(0, 0), Vec2D(0, 200));

    int radius=40;

    while(engine.nextFrame())
    {
        // The kinematic system update function will be called in the engine update
        engine.update();

        // Manually introducing the new coordenates in our render.
        const auto transform = engine.world.get<TransformComponent>(ball);
        Graphics::drawFillCircle(transform.position.x, transform.position.y, radius, Color::blue());

        // Render the buffer
        engine.render();
    }



    return 0;
}