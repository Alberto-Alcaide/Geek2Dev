#include "Engine2D.h"

int main(int argc, char *args[])
{
    Engine2D engine(800,800);

    Vec2D smallWindowForce = Vec2D(10,0);
    Vec2D bigWindForce = Vec2D(30,0);

    const auto smallBall = engine.world_.create();
    engine.world_.emplace<TransformComponent>(smallBall, Vec2D(100, 700));
    engine.world_.emplace<KinematicsComponent>(smallBall, Vec2D(0, -100));
    engine.world_.emplace<ParticleComponent>(smallBall, 1, 10, Color::red());

    const auto bigBall = engine.world_.create();
    engine.world_.emplace<TransformComponent>(bigBall, Vec2D(200, 700));
    engine.world_.emplace<KinematicsComponent>(bigBall, Vec2D(0, -100));
    engine.world_.emplace<ParticleComponent>(bigBall, 5, 20, Color::green());

    auto& smallParticleComponent = engine.world_.get<ParticleComponent>(smallBall);
    auto& bigParticleComponent = engine.world_.get<ParticleComponent>(bigBall);

    while (engine.nextFrame())
    {
        engine.update();

        //Graphics::drawGrid(100);

        smallParticleComponent.AddForce(smallWindowForce);
        bigParticleComponent.AddForce(bigWindForce);

        engine.render();
    }

    return 0;


}