#include "Engine2D.h"
#include <cmath>

int main(int argc, char *args[])
{
    int width=800;
    int height=800;
    Engine2D engine(width, height);
    int gridSize = 50;
    int radius = gridSize * 0.5;


    // players
    const auto player1 = engine.world.create();
    engine.world.emplace<TransformComponent>(player1, Vec2D(425,775));
    engine.world.emplace<GridMovementComponent>(player1, gridSize);
    engine.world.emplace<NameGroupComponent>(player1, "player1", "players");

    const auto player2 = engine.world.create();
    engine.world.emplace<TransformComponent>(player2, Vec2D(225,775));
    engine.world.emplace<GridMovementComponent>(player2, gridSize);
    engine.world.emplace<NameGroupComponent>(player2, "player2", "players");


    // obstacles
    for(int i = 0; i<=5; ++i)
    {
        const auto fireObstacle3 = engine.world.create();
        engine.world.emplace<TransformComponent>(fireObstacle3, Vec2D(i*200, 100));
        engine.world.emplace<NameGroupComponent>(fireObstacle3, "fireObstacle" + std::to_string(i), "fireObstacle3");

        const auto fireObstacle2 = engine.world.create();
        engine.world.emplace<TransformComponent>(fireObstacle2, Vec2D(i*200 + 100, 300));
        engine.world.emplace<NameGroupComponent>(fireObstacle2, "fireObstacle" + std::to_string(i+5), "fireObstacle2");

        const auto fireObstacle1 = engine.world.create();
        engine.world.emplace<TransformComponent>(fireObstacle1, Vec2D(i*200 +100, 500));
        engine.world.emplace<NameGroupComponent>(fireObstacle1, "fireObstacle" + std::to_string(i+10), "fireObstacle1");

        const auto waterObstacle = engine.world.create();
        engine.world.emplace<TransformComponent>(waterObstacle, Vec2D(i*200, 200));
        engine.world.emplace<NameGroupComponent>(waterObstacle, "waterObstacle" + std::to_string(i), "waterObstacle1");

    }
  

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

            if(nameGroup.group == "players")
            {
                for(auto entity2 : view)
                {
                    const auto& nameGroup2 = view.get<NameGroupComponent>(entity2);
                    if(nameGroup2.group != "players")
                    {
                        auto& transform2 = view.get<TransformComponent>(entity2);
                        if(abs(transform.position.x - (transform2.position.x+25)) < 50 && abs(transform.position.y - (transform2.position.y+25)) < 50)
                            transform.position = {425, 775};
                    }
                }
            }

            if(nameGroup.group == "fireObstacle3")
            {
                transform.position += Vec2D(150, 0) * engine.getDeltaTime();
                if(transform.position.x >= 900)
                    transform.position.x = -100;
                Graphics::drawFillRect(transform.position.x, transform.position.y, 50, 50, Color::red());
            }

            if(nameGroup.group == "fireObstacle2")
            {
                transform.position += Vec2D(100, 0) * engine.getDeltaTime();
                if(transform.position.x >= 900)
                    transform.position.x = -100;
                Graphics::drawFillRect(transform.position.x, transform.position.y, 50, 50, Color::red());
            }

            if(nameGroup.group == "fireObstacle1")
            {
                transform.position += Vec2D(50, 0) * engine.getDeltaTime();
                if(transform.position.x >= 900)
                    transform.position.x = -100;
                Graphics::drawFillRect(transform.position.x, transform.position.y, 50, 50, Color::red());
            }

            if(nameGroup.group == "waterObstacle1")
            {
                Graphics::drawFillRect(transform.position.x, transform.position.y, 100, 50, Color::blue());
            }
          
        }


        const auto player1TransformComp =  engine.world.get<TransformComponent>(player1);
        const auto player2TransformComp =  engine.world.get<TransformComponent>(player2);


        // draw players
        Graphics::drawFillCircle(
            player1TransformComp.position.x, 
            player1TransformComp.position.y, 
            radius, 
            Color::blue()
        );

        Graphics::drawFillCircle(
            player2TransformComp.position.x, 
            player2TransformComp.position.y, 
            radius, 
            Color::green()
        );

        engine.render();
    }

    return 0;
}