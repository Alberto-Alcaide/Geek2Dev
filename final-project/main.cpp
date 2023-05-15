#include "Engine2D.h"
#include <cmath>
using namespace std;


void OnCollider(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world) noexcept{
    Log::Warning("HIT");
    if (world.get<NameGroupComponent>(a).group == "brick")
    {
        world.destroy(a);
    }
    if (world.get<NameGroupComponent>(b).group == "brick")
    {
        world.destroy(b);
    }

}


int main(int argc, char *args[])
{

    //Vec2D weight = Vec2D(0.0,25.0);
    int width=600;
    int height=800;
    int playerW=100;
    int playerH=25;

    Engine2D engine(width, height);


    // players
    const auto player1 = engine.world.create();
    engine.world.emplace<TransformComponent>(player1, Vec2D(width/2,height-height/10));
    engine.world.emplace<KinematicsComponent>(player1);
    engine.world.emplace<InputMovementComponent>(player1, 300, 100);
    engine.world.emplace<NameGroupComponent>(player1, "player1", "players");
    engine.world.emplace<ColliderComponent>(player1, RectangleShape(playerW,playerH,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(player1, 0, RectangleShape(playerW,playerH, Color::white(), true));



    //Walls
        //celling
    const auto ceiling = engine.world.create();
    engine.world.emplace<TransformComponent>(ceiling, Vec2D(0,0));
    engine.world.emplace<KinematicsComponent>(ceiling);
    engine.world.emplace<NameGroupComponent>(ceiling, "celling", "map");
    engine.world.emplace<ColliderComponent>(ceiling, RectangleShape(width,25,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(ceiling, 0, RectangleShape(width, 25, Color::white(), true));
        //left wall 
    const auto l_wall = engine.world.create();
    engine.world.emplace<TransformComponent>(l_wall, Vec2D(0,26));
    engine.world.emplace<KinematicsComponent>(l_wall);
    engine.world.emplace<NameGroupComponent>(l_wall, "l_wall", "map");
    engine.world.emplace<ColliderComponent>(l_wall, RectangleShape(25,height-125,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(l_wall, 0, RectangleShape(25, height-150, Color::white(), true));
        //right wall
    const auto r_wall = engine.world.create();
    engine.world.emplace<TransformComponent>(r_wall, Vec2D(575,26));
    engine.world.emplace<KinematicsComponent>(r_wall);
    engine.world.emplace<NameGroupComponent>(r_wall, "r_wall", "map");
    engine.world.emplace<ColliderComponent>(r_wall, RectangleShape(50,height-125,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(r_wall, 0, RectangleShape(50, height-125, Color::white(), true));





    //bricks
    const auto brick_1 = engine.world.create();
    engine.world.emplace<TransformComponent>(brick_1, Vec2D(width/2,200));
    engine.world.emplace<NameGroupComponent>(brick_1, "brick_1", "brick");
    engine.world.emplace<ColliderComponent>(brick_1, RectangleShape(100,25,Color::green(),true), true, true);
    engine.world.emplace<RigidBodyComponent>(brick_1, 0, RectangleShape(100, 25, Color::white(), true));
    engine.world.emplace<KinematicsComponent>(brick_1);

    const auto brick_2 = engine.world.create();
    engine.world.emplace<TransformComponent>(brick_2, Vec2D(width/2,300));
    engine.world.emplace<NameGroupComponent>(brick_2, "brick_2", "brick");
    engine.world.emplace<ColliderComponent>(brick_2, RectangleShape(100,25,Color::yellow(),true), true, true);
    engine.world.emplace<RigidBodyComponent>(brick_2, 0, RectangleShape(100, 25, Color::white(), true));
    engine.world.emplace<KinematicsComponent>(brick_2);

    const auto brick_3 = engine.world.create();
    engine.world.emplace<TransformComponent>(brick_3, Vec2D(width/2,400));
    engine.world.emplace<NameGroupComponent>(brick_3, "brick_3", "brick");
    engine.world.emplace<ColliderComponent>(brick_3, RectangleShape(100,25,Color::red(),true), true, true);
    engine.world.emplace<RigidBodyComponent>(brick_3, 0, RectangleShape(100, 25, Color::white(), true));
    engine.world.emplace<KinematicsComponent>(brick_3);



    // visible bricks
    //auto bricks = {brick_1, brick_2, brick_3};




    //ball
    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2D(width/2,height-height/4));
    engine.world.emplace<KinematicsComponent>(ball);
    engine.world.emplace<NameGroupComponent>(ball, "ball", "ball");
    engine.world.emplace<ColliderComponent>(ball, RectangleShape(25,25,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(ball, 1, RectangleShape(25,25, Color::white(), true));

    //ball velocity
    engine.world.get<KinematicsComponent>(ball).velocity=Vec2D(200,-200);


    int level = 1;


    //game loop
    while (engine.nextFrame())
    {
        engine.update();

        // Limit movement of player (Can't get out of the screen)
        if (engine.world.get<TransformComponent>(player1).position.x <= 0) 
        {
            engine.world.get<TransformComponent>(player1).position.x = 0;
        }
        else if (engine.world.get<TransformComponent>(player1).position.x >= (width-playerW))
        {
            engine.world.get<TransformComponent>(player1).position.x = (width-playerW);
        }
        



        // Check if all bricks are destroyed 
        auto view = engine.world.view<NameGroupComponent>();
        int i=0;
        for(auto entity : view){
            const auto& nameGroup = view.get<NameGroupComponent>(entity);
            if(nameGroup.group == "brick"){
                i++;
            }
        }
        
        //check the level
        if(i==0){
            level++;
            Log::Error(to_string(level));
            switch (level){
                case 2:{
                        const auto brick_1_2 = engine.world.create();
                        engine.world.emplace<TransformComponent>(brick_1_2, Vec2D(width/2,200));
                        engine.world.emplace<NameGroupComponent>(brick_1_2, "brick_1", "brick");
                        engine.world.emplace<ColliderComponent>(brick_1_2, RectangleShape(100,25,Color::green(),true), true, true);
                        engine.world.emplace<RigidBodyComponent>(brick_1_2, 0, RectangleShape(100, 25, Color::white(), true));
                        engine.world.emplace<KinematicsComponent>(brick_1_2);

                        const auto brick_2_2 = engine.world.create();
                        engine.world.emplace<TransformComponent>(brick_2_2, Vec2D(width/2,300));
                        engine.world.emplace<NameGroupComponent>(brick_2_2, "brick_2", "brick");
                        engine.world.emplace<ColliderComponent>(brick_2_2, RectangleShape(100,25,Color::yellow(),true), true, true);
                        engine.world.emplace<RigidBodyComponent>(brick_2_2, 0, RectangleShape(100, 25, Color::white(), true));
                        engine.world.emplace<KinematicsComponent>(brick_2_2);

                        const auto brick_3_2 = engine.world.create();
                        engine.world.emplace<TransformComponent>(brick_3_2, Vec2D(width/2,400));
                        engine.world.emplace<NameGroupComponent>(brick_3_2, "brick_3", "brick");
                        engine.world.emplace<ColliderComponent>(brick_3_2, RectangleShape(100,25,Color::red(),true), true, true);
                        engine.world.emplace<RigidBodyComponent>(brick_3_2, 0, RectangleShape(100, 25, Color::white(), true));
                        engine.world.emplace<KinematicsComponent>(brick_3_2);

                    break;
                }
                case 3:{
                        const auto brick_1_3 = engine.world.create();
                        engine.world.emplace<TransformComponent>(brick_1_3, Vec2D(width,200));
                        engine.world.emplace<NameGroupComponent>(brick_1_3, "brick_1", "brick");
                        engine.world.emplace<ColliderComponent>(brick_1_3, RectangleShape(100,25,Color::green(),true), true, true);
                        engine.world.emplace<RigidBodyComponent>(brick_1_3, 0, RectangleShape(100, 25, Color::white(), true));
                        engine.world.emplace<KinematicsComponent>(brick_1_3);

                        const auto brick_2_3 = engine.world.create();
                        engine.world.emplace<TransformComponent>(brick_2_3, Vec2D(width,300));
                        engine.world.emplace<NameGroupComponent>(brick_2_3, "brick_2", "brick");
                        engine.world.emplace<ColliderComponent>(brick_2_3, RectangleShape(100,25,Color::yellow(),true), true, true);
                        engine.world.emplace<RigidBodyComponent>(brick_2_3, 0, RectangleShape(100, 25, Color::white(), true));
                        engine.world.emplace<KinematicsComponent>(brick_2_3);
                        break;
                }
                default:{
                    //Log::Warning("terminé");
                    break;
                }

                //fix the enviorement



            }

        }

        engine.render();
    }

    return 0;
}

