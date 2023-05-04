#include "Engine2D.h"

int main(int argc, char *args[])
{
    Engine2D engine(800,800);

    Vec2D weight = Vec2D(20,120);
    std::vector<entt::entity> bodies;

    // Walls
    auto bottomWall = engine.world.create();
    engine.world.emplace<TransformComponent>(bottomWall, Vec2D(400,800));
    engine.world.emplace<KinematicsComponent>(bottomWall);
    engine.world.emplace<ColliderComponent>(bottomWall, RectangleShape(800,100, Color::white(), false), true, false);
    engine.world.emplace<RigidBodyComponent>(bottomWall, 0, RectangleShape(800,100, Color::white(), false));

    auto leftWall = engine.world.create();
    engine.world.emplace<TransformComponent>(leftWall, Vec2D(0,0));
    engine.world.emplace<KinematicsComponent>(leftWall);
    engine.world.emplace<ColliderComponent>(leftWall, RectangleShape(100,700, Color::white(), false), true, false);
    engine.world.emplace<RigidBodyComponent>(leftWall, 0, RectangleShape(100,700, Color::white(), false));

    auto rightWall = engine.world.create();
    engine.world.emplace<TransformComponent>(rightWall, Vec2D(700,0));
    engine.world.emplace<KinematicsComponent>(rightWall);
    engine.world.emplace<ColliderComponent>(rightWall, RectangleShape(100,700, Color::white(), false), true, false);
    engine.world.emplace<RigidBodyComponent>(rightWall, 0, RectangleShape(100,700, Color::white(), false));

    auto middleWall = engine.world.create();
    engine.world.emplace<TransformComponent>(middleWall, Vec2D(300,300));
    engine.world.emplace<KinematicsComponent>(middleWall);
    engine.world.emplace<ColliderComponent>(middleWall, RectangleShape(100,100, Color::white(), false), true, false);
    engine.world.emplace<RigidBodyComponent>(middleWall, 0, RectangleShape(100,100, Color::white(), false));
    /*
    auto rect = engine.world.create();
    engine.world.emplace<TransformComponent>(rect, Vec2D(520,0));
    engine.world.emplace<KinematicsComponent>(rect, Vec2D(25,50));
    engine.world.emplace<ColliderComponent>(rect, RectangleShape(100,100, Color::white(), false), true, false);
    engine.world.emplace<RigidBodyComponent>(rect, 0, RectangleShape(100,100, Color::white(), false));
    */

    while (engine.nextFrame())
    {
        engine.update();
        //engine.world.get<RigidBodyComponent>(middleWall).AddForce(weight);
        
  
        for (auto entity: bodies)
        {
            engine.world.get<RigidBodyComponent>(entity).AddForce(weight);
        }
        
        

       
        if (engine.mouse->leftButtonPressed)
        {
            engine.mouse->leftButtonPressed = false;
            entt::entity new_rect = engine.world.create();
            engine.world.emplace<TransformComponent>(new_rect, engine.mouse->position);
            engine.world.emplace<KinematicsComponent>(new_rect);
            engine.world.emplace<ColliderComponent>(new_rect, RectangleShape(60,60, Color::blue(), false), true, false);
            engine.world.emplace<RigidBodyComponent>(new_rect,1, RectangleShape(60,60, Color::blue(), false));
            bodies.push_back(new_rect);
        }
        /*
        if (engine.mouse->rightButtonPressed)
        {
            engine.mouse->rightButtonPressed = false;
            
            std::vector<Vec2D> vertices = {
                Vec2D(20,60),
                Vec2D(-40,20),
                Vec2D(-20,-60),
                Vec2D(20,60),
                Vec2D(40,20),
            };
            
            entt::entity new_rect = engine.world.create();
            engine.world.emplace<TransformComponent>(new_rect, engine.mouse->position);
            engine.world.emplace<KinematicsComponent>(new_rect);
            engine.world.emplace<ColliderComponent>(new_rect, RectangleShape(100,100, Color::red(), true), true, false);
            engine.world.emplace<RigidBodyComponent>(new_rect,0, RectangleShape(100,100, Color::red(), true));
            bodies.push_back(new_rect);
        }*/
        
        
        engine.render();
    }
    return 0;
}