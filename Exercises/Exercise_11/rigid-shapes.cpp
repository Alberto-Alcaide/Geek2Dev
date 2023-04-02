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

    const auto rectangle = engine.world.create();
    engine.world.emplace<TransformComponent>(rectangle, Vec2D(200,600));
    engine.world.emplace<KinematicsComponent>(rectangle);
    engine.world.emplace<RigidBodyComponent>(rectangle, mass, RectangleShape(200, 100, Color::green(), false));

    while (engine.nextFrame())
    {
        engine.update();

        auto& circleRb = engine.world.get<RigidBodyComponent>(circle);
        auto& rectangleRb = engine.world.get<RigidBodyComponent>(rectangle);

        if (engine.keyboard->rightKeyPressed)
        {
            circleRb.AddTorque(500);
            rectangleRb.AddTorque(500);
        }
        if (engine.keyboard->leftKeyPressed)
        {
            circleRb.AddTorque(-500);
            rectangleRb.AddTorque(-500);
        }

        
        //std::cout << "Torque: " << circleRb.sumTorques << "\n";

        //Log::Info("Circle Angular acceleration: ");
        std::cout << "Acceleration: " <<  engine.world.get<KinematicsComponent>(circle).angularAcceleration;

        //Log::Info("Circle Angular velocity: ");
        std::cout << " Velocity: " << engine.world.get<KinematicsComponent>(circle).angularVelocity;

        //Log::Info("Circle Angular position: ");
        std::cout << " Rotation: " << engine.world.get<TransformComponent>(circle).rotation << "\n";
 
        engine.render();
    }

    return 0;
}