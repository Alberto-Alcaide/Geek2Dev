#include "Engine2D.h"

int main(int argc, char *args[])
{
    int width=800;
    int height=800;
    Engine2D engine(width, height);


    // Variables of Objects
    float mass=1;

    const auto circle = engine.world.create();
    engine.world.emplace<TransformComponent>(circle, Vec2D(200,200));
    engine.world.emplace<KinematicsComponent>(circle);
    engine.world.emplace<RigidBodyComponent>(circle, mass, CircleShape(100, Color::red(), false));

    const auto circleFilled = engine.world.create();
    engine.world.emplace<TransformComponent>(circleFilled, Vec2D(600,200));
    engine.world.emplace<KinematicsComponent>(circleFilled);
    engine.world.emplace<RigidBodyComponent>(circleFilled, mass, CircleShape(100, Color::green(), true));

    while (engine.nextFrame())
    {
        engine.update();

        auto& circleRb = engine.world.get<RigidBodyComponent>(circle);

        if (engine.keyboard->rightKeyPressed)
        {
            circleRb.AddTorque(500);
        }
        if (engine.keyboard->leftKeyPressed)
        {
            circleRb.AddTorque(-500);
        }

        
        std::cout << "Torque: " << circleRb.sumTorques << "\n";
        //std::cout << "Circle Angular acceleration: " << engine.world.get<KinematicsComponent>(circle).angularAcceleration << "\n";
        //std::cout << "Circle Angular velocity: " << engine.world.get<KinematicsComponent>(circle).angularVelocity << "\n";
        //std::cout << "Circle Angular position: " << engine.world.get<TransformComponent>(circle).rotation << "\n";


        
        engine.render();
    }

    return 0;
}