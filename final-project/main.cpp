#include "Engine2D.h"
#include <cmath>
using namespace std;
int width=725;
int height=1000;
int playerW=100;
int playerH=25;
Engine2D engine(width, height);

void OnColider(const ColiderEvent& collision) noexcept{
    std::cout<<"GAME OVER"<<std::endl;
    engine.~Engine2D();
}


int main(int argc, char *args[])
{
    // players
    const auto player1 = engine.world.create();
    engine.world.emplace<TransformComponent>(player1, Vec2D(width/2,height-height/10));
    engine.world.emplace<GridMovementComponent>(player1, 50);
    engine.world.emplace<NameGroupComponent>(player1, "player1", "players");
    engine.world.emplace<ColliderComponent>(player1, RectangleShape(100,50,Color::yellow(),true), true, true);

    //Walls
        //celing
    const auto celing = engine.world.create();
    engine.world.emplace<TransformComponent>(celing, Vec2D(0,0));
    engine.world.emplace<NameGroupComponent>(celing, "celing", "map");
    engine.world.emplace<ColliderComponent>(celing, RectangleShape(width,25,Color::yellow(),true), true, true);
        //left wall
    const auto l_wall = engine.world.create();
    engine.world.emplace<TransformComponent>(l_wall, Vec2D(0,25));
    engine.world.emplace<NameGroupComponent>(l_wall, "l_wall", "map");
    engine.world.emplace<ColliderComponent>(l_wall, RectangleShape(25,974,Color::yellow(),true), true, true);
        //right wall
    const auto r_wall = engine.world.create();
    engine.world.emplace<TransformComponent>(r_wall, Vec2D(700,25));
    engine.world.emplace<NameGroupComponent>(r_wall, "r_wall", "map");
    engine.world.emplace<ColliderComponent>(r_wall, RectangleShape(25,974,Color::yellow(),true), true, true);



    //bricks
    const auto brick_1 = engine.world.create();
    engine.world.emplace<TransformComponent>(r_wall, Vec2D(width/2,200));
    engine.world.emplace<NameGroupComponent>(r_wall, "brick_1", "brick");
    engine.world.emplace<ColliderComponent>(r_wall, RectangleShape(100,50,Color::yellow(),true), true, true);

    const auto brick_2 = engine.world.create();
    engine.world.emplace<TransformComponent>(r_wall, Vec2D(width/2,300));
    engine.world.emplace<NameGroupComponent>(r_wall, "brick_2", "brick");
    engine.world.emplace<ColliderComponent>(r_wall, RectangleShape(100,50,Color::yellow(),true), true, true);

    const auto brick_3 = engine.world.create();
    engine.world.emplace<TransformComponent>(r_wall, Vec2D(width/2,400));
    engine.world.emplace<NameGroupComponent>(r_wall, "brick_3", "brick");
    engine.world.emplace<ColliderComponent>(r_wall, RectangleShape(100,50,Color::yellow(),true), true, true);


    //ball



    // visible bricks
    auto bricks = {brick_1, brick_2, brick_3};


    //game loop
    while (engine.nextFrame())
    {
        engine.update();



        //Graphics::drawGrid(gridSize);

        // draw obstacles
        auto view = engine.world.view<NameGroupComponent, TransformComponent>();
        for(auto entity : view)
        {  
            const auto& nameGroup = view.get<NameGroupComponent>(entity);
            auto& transform = view.get<TransformComponent>(entity);

            /*if(nameGroup.group == "players")
            {
                for(auto entity2 : view)
                {
                    const auto& nameGroup2 = view.get<NameGroupComponent>(entity2);
                    Contact contact;
                    
                    if (nameGroup2.group!="players")
                    {
                        
                        if(Collision::IsColliding(entity,entity2,contact,engine.world))//abs(transform.position.x - (transform2.position.x+25)) < 50 && abs(transform.position.y - (transform2.position.y+25)) < 50)
                        {    //transform.position = {425, 775};
                            OnColider(ColiderEvent(entity,entity2));
                        }

                    }

                
                }
            }*/

        }


        // draw players
        const auto player1TransformComp =  engine.world.get<TransformComponent>(player1);
        Graphics::drawFillRect(
            player1TransformComp.position.x, 
            player1TransformComp.position.y, 
            playerW,
            playerH, 
            Color::white()
        );

        // draw Walls
        const auto celingTC = engine.world.get<TransformComponent>(celing);
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
                50, 
                Color::white()
            );
        }
        engine.render();
    }

    return 0;
}

