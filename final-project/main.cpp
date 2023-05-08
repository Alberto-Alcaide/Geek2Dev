#include "Engine2D.h"
#include <cmath>
using namespace std;
int width=725;
int height=1000;
int playerW=100;
int playerH=25;
Engine2D engine(width, height);

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



    // players
    const auto player1 = engine.world.create();
    engine.world.emplace<TransformComponent>(player1, Vec2D(width/2,height-height/10));
    engine.world.emplace<KinematicsComponent>(player1);
    engine.world.emplace<GridMovementComponent>(player1, 50);
    engine.world.emplace<NameGroupComponent>(player1, "player1", "players");
    engine.world.emplace<ColliderComponent>(player1, RectangleShape(playerW,playerH,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(player1, 0, RectangleShape(playerW,playerH, Color::white(), true));



    //Walls
        //celling
    const auto ceiling = engine.world.create();
    engine.world.emplace<TransformComponent>(ceiling, Vec2D(0,100));
    engine.world.emplace<KinematicsComponent>(ceiling);
    engine.world.emplace<NameGroupComponent>(ceiling, "celling", "map");
    engine.world.emplace<ColliderComponent>(ceiling, RectangleShape(width,25,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(ceiling, 0, RectangleShape(width, 25, Color::white(), true));
        //left wall 
    const auto l_wall = engine.world.create();
    engine.world.emplace<TransformComponent>(l_wall, Vec2D(0,130));
    engine.world.emplace<KinematicsComponent>(l_wall);
    engine.world.emplace<NameGroupComponent>(l_wall, "l_wall", "map");
    engine.world.emplace<ColliderComponent>(l_wall, RectangleShape(25,height-250,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(l_wall, 0, RectangleShape(25, height-250, Color::white(), true));
        //right wall
    const auto r_wall = engine.world.create();
    engine.world.emplace<TransformComponent>(r_wall, Vec2D(700,130));
    engine.world.emplace<KinematicsComponent>(r_wall);
    engine.world.emplace<NameGroupComponent>(r_wall, "r_wall", "map");
    engine.world.emplace<ColliderComponent>(r_wall, RectangleShape(50,height-250,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(r_wall, 0, RectangleShape(50, height-250, Color::white(), true));





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
    auto bricks = {brick_1, brick_2, brick_3};




    //ball
    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2D(width/2,height-height/4));
    engine.world.emplace<KinematicsComponent>(ball);
    engine.world.emplace<NameGroupComponent>(ball, "ball", "ball");
    engine.world.emplace<ColliderComponent>(ball, RectangleShape(25,25,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(ball, 1, RectangleShape(25,25, Color::white(), true));

    //ball velocity
    engine.world.get<KinematicsComponent>(ball).velocity=Vec2D(100,-100);

    //game loop
    while (engine.nextFrame())
    {
        engine.update();

        /*engine.world.get<RigidBodyComponent>(ball).AddForce(weight);
        auto forces = engine.world.get<RigidBodyComponent>(ball).GetForces();
        std::cout << "Fuerzas: " << forces << std::endl;*/

        //Graphics::drawGrid(gridSize);


        /*
        auto viewTag = engine.world.view<NameGroupComponent>();

        for (auto entity : viewTag)
        {
            if (engine.world.get<NameGroupComponent>(entity).group=="map")
            std::cout << "Position Walls" << engine.world.get<TransformComponent>(entity).position << std::endl;
        }
        */


        auto view = engine.world.view<NameGroupComponent, TransformComponent>();
        for(auto entity : view)
        {  
            const auto& nameGroup = view.get<NameGroupComponent>(entity);
            auto& transform = view.get<TransformComponent>(entity);



            if(nameGroup.group == "ball")
            {
                for(auto entity2 : view)
                {
                    const auto& nameGroup2 = view.get<NameGroupComponent>(entity2);
                    Contact contact;

                    
                    if (nameGroup2.group=="brick")
                    {

                        
                        if(Collision::IsColliding(entity,entity2,contact,engine.world))//abs(transform.position.x - (transform2.position.x+25)) < 50 && abs(transform.position.y - (transform2.position.y+25)) < 50)
                        {    
                            Log::Warning("Colisiono");
                            OnCollider(entity,entity,contact,engine.world);
                        }

                    }

                
                }
            }

        }


        // draw players
        const auto player1TransformComp =  engine.world.get<TransformComponent>(player1);
        /*Graphics::drawFillRect(
            player1TransformComp.position.x, 
            player1TransformComp.position.y, 
            playerW,
            playerH, 
            Color::white()
        );

        // draw Walls
        const auto ceilingTC = engine.world.get<TransformComponent>(celling);
        const auto l_wallTC = engine.world.get<TransformComponent>(l_wall);
        const auto r_wallTC = engine.world.get<TransformComponent>(r_wall);
        Graphics::drawFillRect(
            celingTC.position.x, 
            celingTC.position.y, 
            width,
            25, 
            Color::white()
        );
        Graphics::drawFillRect(
            l_wallTC.position.x, 
            l_wallTC.position.y, 
            25,
            974, 
            Color::white()
        );
        Graphics::drawFillRect(
            r_wallTC.position.x, 
            r_wallTC.position.y, 
            25,
            974, 
            Color::white()
        );

        //draw briks
        for(auto brick : bricks){
            const auto transformComp = engine.world.get<TransformComponent>(brick);
            //const auto colliderComp = engine.world.get<ColliderComponent>(brick);
            //const auto& shape = colliderComp.shape;

            Graphics::drawFillRect(
                transformComp.position.x, 
                transformComp.position.y, 
                100,
                25, 
                Color::white()
            );
        }

        //draw ball
        auto ballTransform = engine.world.get<TransformComponent>(ball);
        Graphics::drawFillRect(
            ballTransform.position.x,
            ballTransform.position.y,
            25,
            25,
            Color::white()
        );*/

        engine.render();
    }

    return 0;
}

