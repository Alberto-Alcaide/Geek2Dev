#include "Engine2D.h"

int main(int argc, char *args[])
{
    int width=800;
    int height=800;
    Engine2D engine(width, height);

    KinematicSystem kinematicSystem;
    

    const double dt = 1.0/100.0;

    // Variables of Objects
    float inertia=1;
    float mass=1;

    const auto circle = engine.world_.create();
    engine.world_.emplace<TransformComponent>(circle, Vec2D(200,200));
    engine.world_.emplace<KinematicsComponent>(circle);
    engine.world_.emplace<RigidBodyComponent>(circle, mass, inertia, CircleShape(100, Color::red(), false));

    const auto circleFilled = engine.world_.create();
    engine.world_.emplace<TransformComponent>(circleFilled, Vec2D(600,200));
    engine.world_.emplace<KinematicsComponent>(circleFilled);
    engine.world_.emplace<RigidBodyComponent>(circleFilled, mass, inertia, CircleShape(100, Color::green(), true));

    while (engine.nextFrame())
    {
        //engine.update();
        kinematicSystem.Update(dt, engine.world_);

        auto& circleRb = engine.world_.get<RigidBodyComponent>(circle);
        circleRb.AddTorque(500);

        std::cout << "Circle Angular velocity: " << engine.world_.get<KinematicsComponent>(circle).angularVelocity << "\n";

        
        kinematicSystem.Render(engine.world_);
        //engine.render();
    }

    return 0;
}