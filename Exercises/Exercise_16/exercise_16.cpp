#include "Engine2D.h"
#include "sol/sol.hpp"
#include <cmath>
int width=650;
int height=650;
Engine2D engine(width, height);

void OnColider(const ColiderEvent& collision) noexcept{
    std::cout<<"GAME OVER"<<std::endl;
    engine.~Engine2D();
}


int main(int argc, char *args[])
{
    sol::state lua;
    
    engine.scriptSystem.CreateLuaBindings(lua);

    lua.script_file("../../scripts/script-component-03.lua");
    sol::function func = lua["on_update_script"][1];

    int gridSize = 50;
    int radius = gridSize * 0.5;


    // players
    const auto player1 = engine.world.create();
    engine.world.emplace<TransformComponent>(player1, Vec2D(width/2,height/2));
    engine.world.emplace<GridMovementComponent>(player1, gridSize);
    engine.world.emplace<NameGroupComponent>(player1, "player1", "players");
    engine.world.emplace<ColliderComponent>(player1, CircleShape(24, Color::white(), true), true, true);




    // obstacles

    const auto meteor = engine.world.create();
    engine.world.emplace<TransformComponent>(meteor, Vec2D(1,1));
    engine.world.emplace<KinematicsComponent>(meteor, Vec2D(0, 0));
    engine.world.emplace<NameGroupComponent>(meteor, "meteor", "meteor");
    engine.world.emplace<ColliderComponent>(meteor, CircleShape(24, Color::red(), true), true, true);
    engine.world.emplace<ScriptComponent>(meteor,func);

    


    while (engine.nextFrame())
    {
        engine.update();

        auto view = engine.world.view<NameGroupComponent, TransformComponent>();

        for(auto entity : view)
        {  
            const auto& nameGroup = view.get<NameGroupComponent>(entity);
            auto& transform = view.get<TransformComponent>(entity);
            if (nameGroup.group == "meteor")
            {
                std::cout << "Pos Meteor: " << transform.position << std::endl;
            }

            if(nameGroup.group == "players")
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
            }

            if(nameGroup.group == "meteor")
            {
                //transform.position += Vec2D(150, 0) * engine.getDeltaTime();

                if(transform.position.x >= 900)
                    transform.position.x = -100;
                
                //Graphics::drawFillRect(transform.position.x, transform.position.y, 50, 50, Color::red());
                Graphics::drawFillCircle(transform.position.x, transform.position.y, 25, Color::red());
            }

        }

        const auto player1TransformComp =  engine.world.get<TransformComponent>(player1);

        // draw players
        Graphics::drawFillCircle(
            player1TransformComp.position.x, 
            player1TransformComp.position.y, 
            radius, 
            Color::white()
        );

        engine.render();
    }

    return 0;
}