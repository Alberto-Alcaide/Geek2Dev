#include "Engine2D.h"
#include <cmath>
using namespace std;

int width=600;
int height=800;
int playerW=120;
int playerH=35;

Engine2D engine(width, height);

struct Brick {
    // Propiedades de un brick
    int x;
    int y;
};

void GameOver() // When the ball falls under the screen
{
    Log::Error("GAME OVER");
    engine.~Engine2D();
}

void createBricks(const sol::table& bricksTable) {
    std::vector<Brick> bricks;
    std::size_t size = bricksTable.size();
    for (std::size_t i = 1; i <= size; ++i) {
        const sol::table brickTable = bricksTable[i];
        Brick brick;
        brick.x = brickTable["x"];
        brick.y = brickTable["y"];
        bricks.push_back(brick);
    }

    // Utilizar el vector de bricks para crear los bricks según sea necesario
    for (const auto& p_brick : bricks) {
        // Código para crear cada brick
        std::cout << "Creating brick: width=" << p_brick.x << ", height=" << p_brick.y << std::endl;
        const auto brick = engine.world.create();
        engine.world.emplace<TransformComponent>(brick, Vec2D(p_brick.x,p_brick.y));
        engine.world.emplace<NameGroupComponent>(brick, "brick_1", "brick");
        engine.world.emplace<ColliderComponent>(brick, RectangleShape(100,25,Color::green(),true), true, true);
        engine.world.emplace<RigidBodyComponent>(brick, 0, RectangleShape(100, 25, Color::white(), false, false));
        engine.world.emplace<KinematicsComponent>(brick);
    }
}


int main(int argc, char *args[])
{



    //Vec2D weight = Vec2D(0.0,25.0);

    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.new_usertype<Brick>("Brick",
        "x", &Brick::x,
        "y", &Brick::y
    );
    lua.set_function("createBricks", &createBricks);

    // Initialize Sprites
<<<<<<< Updated upstream
    SDL_Texture* BlueBrick = Graphics::CreateSprite("assets/Blue-Brick.png");
    SDL_Texture* GreenBrick = Graphics::CreateSprite("assets/Green-Brick.png");
    SDL_Texture* RedBrick = Graphics::CreateSprite("assets/Red-Brick.png");
    SDL_Texture* player = Graphics::CreateSprite("assets/player01.png");
=======
    SDL_Texture* BlueBrick = Graphics::CreateSprite("assets/sprites/Blue-Brick.png");
    SDL_Texture* GreenBrick = Graphics::CreateSprite("assets/sprites/Green-Brick.png");
    SDL_Texture* RedBrick = Graphics::CreateSprite("assets/sprites/Red-Brick.png");
    SDL_Texture* player = Graphics::CreateSprite("Assets/Sprites/player01.png");
>>>>>>> Stashed changes

    // Try background image
    /*
    SDL_Texture* Background = Graphics::CreateSprite("../Background/Background1.png");
    SDL_Rect _srcRect = {0, 0, width, height};
    Graphics::DrawSprite(Background, Vec2D(0,0), Vec2D(1,1), width, height, 0, _srcRect);
    */

    // players
    const auto player1 = engine.world.create();
    engine.world.emplace<TransformComponent>(player1, Vec2D(width/2,height-height/10));
    engine.world.emplace<KinematicsComponent>(player1);
    engine.world.emplace<InputMovementComponent>(player1, 300, 100);
    engine.world.emplace<NameGroupComponent>(player1, "player1", "players");
    engine.world.emplace<ColliderComponent>(player1, RectangleShape(playerW,playerH,Color::black(),false, false), false, false);
    engine.world.emplace<RigidBodyComponent>(player1, 0, RectangleShape(playerW,playerH, Color::black(), false, false));
    engine.world.emplace<SpriteComponent>(player1, playerW+5, playerH-5, player);



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
    /*const auto brick_1 = engine.world.create();
    engine.world.emplace<TransformComponent>(brick_1, Vec2D(width/2,200));
    engine.world.emplace<NameGroupComponent>(brick_1, "brick_1", "brick");
    engine.world.emplace<ColliderComponent>(brick_1, RectangleShape(100,25,Color::green(),false), false, true);
    engine.world.emplace<RigidBodyComponent>(brick_1, 0, RectangleShape(100, 25, Color::white(), false, false));
    engine.world.emplace<KinematicsComponent>(brick_1);
    engine.world.emplace<SpriteComponent>(brick_1, 100, 25, GreenBrick);

    const auto brick_2 = engine.world.create();
    engine.world.emplace<TransformComponent>(brick_2, Vec2D(width/2,300));
    engine.world.emplace<NameGroupComponent>(brick_2, "brick_2", "brick");
    engine.world.emplace<ColliderComponent>(brick_2, RectangleShape(100,25,Color::blue(),false, false), false, true);
    engine.world.emplace<RigidBodyComponent>(brick_2, 0, RectangleShape(100, 25, Color::white(), false, false));
    engine.world.emplace<KinematicsComponent>(brick_2);
    engine.world.emplace<SpriteComponent>(brick_2, 100, 25, BlueBrick);

    const auto brick_3 = engine.world.create();
    engine.world.emplace<TransformComponent>(brick_3, Vec2D(width/2,400));
    engine.world.emplace<NameGroupComponent>(brick_3, "brick_3", "brick");
    engine.world.emplace<ColliderComponent>(brick_3, RectangleShape(100,25,Color::red(),false, false), false, true);
    engine.world.emplace<RigidBodyComponent>(brick_3, 0, RectangleShape(100, 25, Color::white(), false, false));
    engine.world.emplace<KinematicsComponent>(brick_3);
    engine.world.emplace<SpriteComponent>(brick_3, 100, 25, RedBrick);*/

    lua.script_file("bricks.lua");


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

        // Set a GAME OVER
        if (engine.world.get<TransformComponent>(ball).position.y >=height)
        {
            GameOver();
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
            if(engine.world.get<TransformComponent>(ball).position.y > height-300)
            {
                level++;
                Log::Error(to_string(level));
                switch (level){
                    case 2:{
                            lua.script_file("level_2.lua");
                        break;
                    }
                    case 3:{
                            lua.script_file("level_3.lua");
                        break;
                    }
                    default:{
                        Log::Warning("terminé");
                        break;
                    }
                }
            }
        }


        //fix the enviorement
        Graphics::drawFillRect(0, 25, 25, 2, Color::white());
        Graphics::drawFillRect(0, width-25, 25, 2, Color::white());

        engine.render();
    }

    SDL_DestroyTexture(BlueBrick);
    SDL_DestroyTexture(GreenBrick);
    SDL_DestroyTexture(RedBrick);

    SDL_DestroyTexture(player);

    //SDL_DestroyTexture(Background);
    

    return 0;
}

