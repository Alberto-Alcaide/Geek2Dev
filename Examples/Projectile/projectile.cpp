#include "Engine2D.h"

int main(int argc, char *args[])
{

    int width = 800;
    int height = 800;
    Engine2D engine(800,800);

    // Creates an object in our world
    const auto ball = engine.world.create();

    // Attaches components to an object
    engine.world.emplace<TransformComponent>(ball, Vec2D(width/2, 10));
    engine.world.emplace<KinematicsComponent>(ball, Vec2D(100, 0), Vec2D(0, 200));

    int radius=40;
    Color ball_color = Color::red();

    while(engine.nextFrame())
    {
        // The kinematic system update function will be called in the engine update
        engine.update();

        // Get references to ball components
        const auto &ball_transform = engine.world.get<TransformComponent>(ball);
        auto &ball_kinematics = engine.world.get<KinematicsComponent>(ball);

        // Check if ball touches ground
        if(ball_transform.position.y >= height * 0.75)
        {
            ball_kinematics.velocity = Vec2D(ball_kinematics.velocity.x, -ball_kinematics.velocity.y);
            ball_color = Color(rand() % 255, rand() % 255, rand() % 255);
        }

        // Check if ball touches left-right sides of screen
        if(ball_transform.position.x >= width || ball_transform.position.x <= 0)
        {
            ball_kinematics.velocity = Vec2D(-ball_kinematics.velocity.x, ball_kinematics.velocity.y);    
            ball_color = Color(rand() % 255, rand() % 255, rand() % 255);
        }

        // draw objects in buffer
        Graphics::drawFillRect(0, 0, width, height*0.75, Color(0, 255, 255));
        Graphics::drawFillRect(0, height*0.75, width, height*0.25, Color::green());
        Graphics::drawFillCircle(ball_transform.position.x, ball_transform.position.y, radius, ball_color);
    

        // Render the buffer
        engine.render();
    }



    return 0;
}