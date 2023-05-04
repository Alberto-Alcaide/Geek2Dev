#include "Engine2D.h"
#include <cmath>
int width=725;
int height=1000;
int playerW=100;
int playerH=25;
Engine2D engine(width, height);
ç+
void OnColider(const ColiderEvent& collision) noexcept{
    std::cout<<"GAME OVER"<<std::endl;
    engine.~Engine2D();
}


int main(int argc, char *args[])
{




    // players
    const auto player1 = engine.world.create();
    engine.world.emplace<TransformComponent>(player1, Vec2D(width/2,height/2));
    engine.world.emplace<GridMovementComponent>(player1, 50);
    engine.world.emplace<NameGroupComponent>(player1, "player1", "players");
    engine.world.emplace<ColliderComponent>(player1, RectangleShape(100,50,Color::yellow(),true), true, true);

    //bricks




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


        const auto player1TransformComp =  engine.world.get<TransformComponent>(player1);


        // draw players
        Graphics::drawFillRect(
            player1TransformComp.position.x, 
            player1TransformComp.position.y, 
            playerW,
            playerH, 
            Color::white()
        );



        engine.render();
    }

    return 0;
}