#include "Engine2D.h"

int main(int argc, char* args[])
{
    // Screen size
    int width = 800;
    int height = 800;

    // Engine start up
    Engine2D engine(width, height);

    // Example variables
    Vec2D gravityForce = Vec2D(0, 50);
    float drag = 0.01;

    // Object initialization
    const auto projectile = engine.world_.create();
    engine.world_.emplace<TransformComponent>(projectile, Vec2D(0.0, width/2));
    engine.world_.emplace<KinematicsComponent>(projectile, Vec2D(150, -150), Vec2D(0, 9.81));
    engine.world_.emplace<ParticleComponent>(projectile, 1, 10, Color::red());

    // Get reference to componenets
    auto& kinematicComp = engine.world_.get<KinematicsComponent>(projectile);
    auto& particleComp = engine.world_.get<ParticleComponent>(projectile);

    // Game loop
    while(engine.nextFrame())
    {
        engine.update();

        // Add forces to our projectile particle
        particleComp.AddForce(gravityForce);
        particleComp.AddForce(Force::generateDragVector(drag, kinematicComp.velocity));

        // Paint background in buffer
        Graphics::drawFillRect(0, 0, width, height/2, Color(179, 237, 252));
        Graphics::drawFillRect(0, height * 0.5, width, height/2, Color(11, 99, 23));

        engine.render();
    }

    return 0;
}