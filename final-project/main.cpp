#include "Engine2D.h"
#include <cmath>
#include <map>
using namespace std;

int width=600;
int height=800;
int playerW=120;
int playerH=30;
int level = 0;
int score=0;
int for_brick_count=0;
int score_global = 0;
std::map<int, SDL_Texture*> scoreMap;
bool Flag=true;

Engine2D engine(width, height);

struct Brick 
{
    // Propiedades de un brick
    int x;
    int y;
    string color;
};

void GameOver() // When the ball falls under the screen
{
    Log::Error("GAME OVER");
    engine.~Engine2D();
}

void createBricks(const sol::table& bricksTable) 
{
    SDL_Texture* GreenBrick = Graphics::CreateSprite("assets/sprites/Green-Brick.png");
    SDL_Texture* BlueBrick = Graphics::CreateSprite("assets/sprites/Blue-Brick.png");
    SDL_Texture* RedBrick = Graphics::CreateSprite("assets/sprites/Red-Brick.png");
    std::vector<Brick> bricks;
    std::size_t size = bricksTable.size();
    for (std::size_t i = 1; i <= size; ++i) 
    {
        const sol::table brickTable = bricksTable[i];
        Brick brick;
        brick.x = brickTable["x"];
        brick.y = brickTable["y"];
        brick.color = brickTable["color"];
        bricks.push_back(brick);
    }
    for_brick_count=0;
    // Utilizar el vector de bricks para crear los bricks según sea necesario
    for (const auto& p_brick : bricks) 
    {
        // Código para crear cada brick
        //std::cout << "Creating brick: width=" << p_brick.x << ", height=" << p_brick.y << std::endl;
        const auto brick = engine.world.create();
        engine.world.emplace<TransformComponent>(brick, Vec2D(p_brick.x,p_brick.y));
        engine.world.emplace<NameGroupComponent>(brick, "brick_1", "brick");
        engine.world.emplace<ColliderComponent>(brick, RectangleShape(100,25,Color::green(),false), false, true);
        engine.world.emplace<RigidBodyComponent>(brick, 0, RectangleShape(100, 25, Color::white(), false, false));
        engine.world.emplace<KinematicsComponent>(brick);
        if(p_brick.color=="green")
            engine.world.emplace<SpriteComponent>(brick, 100, 25, GreenBrick);
        else if(p_brick.color=="blue")
            engine.world.emplace<SpriteComponent>(brick, 100, 25, BlueBrick);        
        else if(p_brick.color=="red")
            engine.world.emplace<SpriteComponent>(brick, 100, 25, RedBrick);

        for_brick_count++;
    }

    
}


int main(int argc, char *args[])
{
 
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.new_usertype<Brick>("Brick",
        "x", &Brick::x,
        "y", &Brick::y,
        "color", &Brick::color
    );
    lua.set_function("createBricks", &createBricks);

    // Initialize Sprites

    SDL_Texture* zeroSprite = Graphics::CreateSprite("assets/sprites/0.png");
    SDL_Texture* oneSprite = Graphics::CreateSprite("assets/sprites/1.png");
    SDL_Texture* twoSprite = Graphics::CreateSprite("assets/sprites/2.png");
    SDL_Texture* threeSprite = Graphics::CreateSprite("assets/sprites/3.png");
    SDL_Texture* fourSprite = Graphics::CreateSprite("assets/sprites/4.png");
    SDL_Texture* fiveSprite = Graphics::CreateSprite("assets/sprites/5.png");
    SDL_Texture* sixSprite = Graphics::CreateSprite("assets/sprites/6.png");
    SDL_Texture* sevenSprite = Graphics::CreateSprite("assets/sprites/7.png");
    SDL_Texture* eightSprite = Graphics::CreateSprite("assets/sprites/8.png");
    SDL_Texture* nineSprite = Graphics::CreateSprite("assets/sprites/9.png");

    // Map score values with sprites
    scoreMap[0] = zeroSprite;
    scoreMap[1] = oneSprite;
    scoreMap[2] = twoSprite;
    scoreMap[3] = threeSprite;
    scoreMap[4] = fourSprite;
    scoreMap[5] = fiveSprite;
    scoreMap[6] = sixSprite;
    scoreMap[7] = sevenSprite;
    scoreMap[8] = eightSprite;
    scoreMap[9] = nineSprite;

    // Player Sprites
    SDL_Texture* player = Graphics::CreateSprite("assets/sprites/player01.png");
    SDL_Texture* player2 = Graphics::CreateSprite("assets/sprites/player02.png");
    SDL_Texture* player3 = Graphics::CreateSprite("assets/sprites/player03.png");
    SDL_Texture* ballSprite = Graphics::CreateSprite("assets/sprites/ball.png");

    // Walls Sprites
    SDL_Texture* Wall = Graphics::CreateSprite("Assets/Sprites/Background/Wall.png");
    SDL_Texture* Ceiling = Graphics::CreateSprite("Assets/Sprites/Background/Ceiling.png");

    // Background Sprites
    SDL_Texture* Background = Graphics::CreateSprite("Assets/Sprites/Background/Background1.png");
    SDL_Texture* Background2 = Graphics::CreateSprite("Assets/Sprites/Background/Background2.png");
    SDL_Texture* Background3 = Graphics::CreateSprite("Assets/Sprites/Background/Background3.png");
    




    // players
    const auto player1 = engine.world.create();
    engine.world.emplace<TransformComponent>(player1, Vec2D(width/2,height-height/10));
    engine.world.emplace<KinematicsComponent>(player1);
    engine.world.emplace<InputMovementComponent>(player1, 350, 100);
    engine.world.emplace<NameGroupComponent>(player1, "player1", "players");
    engine.world.emplace<ColliderComponent>(player1, RectangleShape(playerW,playerH,Color::black(),false, false), false, false);
    engine.world.emplace<RigidBodyComponent>(player1, 0, RectangleShape(playerW,playerH, Color::black(), false, false));
    //engine.world.emplace<SpriteComponent>(player1, playerW, playerH, player);

    //Walls
        //celling
    const auto ceiling = engine.world.create();
    engine.world.emplace<TransformComponent>(ceiling, Vec2D(0,0));
    engine.world.emplace<KinematicsComponent>(ceiling);
    engine.world.emplace<NameGroupComponent>(ceiling, "ceiling", "map");
    engine.world.emplace<ColliderComponent>(ceiling, RectangleShape(width,25,Color::white(),true), false, false);
    engine.world.emplace<RigidBodyComponent>(ceiling, 0, RectangleShape(width, 25, Color::white(), true, false));
    engine.world.emplace<SpriteComponent>(ceiling, width, 25, Ceiling);
        //left wall 
    const auto l_wall = engine.world.create();
    engine.world.emplace<TransformComponent>(l_wall, Vec2D(0,26));
    engine.world.emplace<KinematicsComponent>(l_wall);
    engine.world.emplace<NameGroupComponent>(l_wall, "l_wall", "map");
    engine.world.emplace<ColliderComponent>(l_wall, RectangleShape(25,height-110,Color::white(),false), false, false);
    engine.world.emplace<RigidBodyComponent>(l_wall, 0, RectangleShape(25, height-110, Color::white(), true, false));
    engine.world.emplace<SpriteComponent>(l_wall, 25, height-110, Wall);
        //right wall
    const auto r_wall = engine.world.create();
    engine.world.emplace<TransformComponent>(r_wall, Vec2D(575,26));
    engine.world.emplace<KinematicsComponent>(r_wall);
    engine.world.emplace<NameGroupComponent>(r_wall, "r_wall", "map");
    engine.world.emplace<ColliderComponent>(r_wall, RectangleShape(50,height-110,Color::white(),false), false, false);
    engine.world.emplace<RigidBodyComponent>(r_wall, 0, RectangleShape(50, height-110, Color::white(), true, false));
    engine.world.emplace<SpriteComponent>(r_wall, 25, height-110, Wall);

    // ball
    const auto ball = engine.world.create();
    engine.world.emplace<TransformComponent>(ball, Vec2D((width+35)/2,height-300));
    engine.world.emplace<KinematicsComponent>(ball);
    engine.world.emplace<NameGroupComponent>(ball, "ball", "ball");
    engine.world.emplace<ColliderComponent>(ball, RectangleShape(12,12,Color::white(),true), true, false);
    engine.world.emplace<RigidBodyComponent>(ball, 1, RectangleShape(12,12, Color::white(), true, false));
    //engine.world.emplace<SpriteComponent>(ball, 15, 15, ballSprite);
    

    // ball velocity
    engine.world.get<KinematicsComponent>(ball).velocity=Vec2D(0,0);

    // Init Sounds and start playing music
    Mix_Chunk* ballHitSound = Sounds::LoadSound("Assets/Sounds/arkanoid1.wav");
    Mix_Music* music = Sounds::LoadMusic("Assets/Sounds/arcade_music.wav");
    Sounds::PlayMusic(music);

    
    
    const auto background = engine.world.create();
    engine.world.emplace<TransformComponent>(background, Vec2D(0,0));
    //engine.world.emplace<SpriteComponent>(background, width, height, Background);

    //game loop
    while (engine.nextFrame())
    {
        engine.update();

        // Check for GameOver
        if (engine.world.get<TransformComponent>(ball).position.y >=height)
        {
            GameOver();
        }

        // Limit movement of player (Can't get out of the screen)
        if (engine.world.get<TransformComponent>(player1).position.x <= 0) 
        {
            engine.world.get<TransformComponent>(player1).position.x = 0;
        }
        else if (engine.world.get<TransformComponent>(player1).position.x >= (width-playerW))
        {
            engine.world.get<TransformComponent>(player1).position.x = (width-playerW);
        }

        // Play sound effect on ball collision
        if (engine.world.get<ColliderComponent>(ball).isColliding)
        {
            Sounds::PlaySound(ballHitSound);
            
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
        //score update
        score=score_global + ((for_brick_count-i) * 100);
        std::cout << score << std::endl;
        // Update Graphics depending on level
        if(i==0){
            if(engine.world.get<TransformComponent>(ball).position.y > height-300 || level==0)
            {
                score_global=score_global + score;
                level++;
                Log::Error(to_string(level));
                switch (level){
                    case 1:{

                            lua.script_file("Scripts/level_1.lua");
                           
                        break;
                    }
                    case 2:{
                
                            lua.script_file("Scripts/level_2.lua");
                            

                        break;
                    }
                    case 3:{
                            
                            lua.script_file("Scripts/level_3.lua");
                            
                        break;
                    }
                    case 4:{
                        Log::Info("WINNER");
                        engine.~Engine2D();

                        break;
                    }
                    default:{
                        Log::Warning("terminé");
                        break;
                    }
                }
            }
        }
    
        if (level==1 && Flag)
        {
            if (engine.world.get<KinematicsComponent>(ball).velocity==Vec2D(0,0))
            {
                
                engine.world.get<KinematicsComponent>(ball).velocity=Vec2D(0,400);
            }

            Flag=false;
            engine.world.emplace<SpriteComponent>(player1, playerW, playerH, player);
            engine.world.emplace<SpriteComponent>(background, width, height, Background);

        }
        else if (level==1)
        {
            
            engine.world.remove<SpriteComponent>(player1);
            engine.world.emplace<SpriteComponent>(player1, playerW, playerH, player);

            engine.world.remove<SpriteComponent>(background);
            engine.world.emplace<SpriteComponent>(background, width, height, Background);


        }
        else if (level==2)
        {
            engine.world.remove<SpriteComponent>(player1);
            engine.world.emplace<SpriteComponent>(player1, playerW, playerH, player2);

            engine.world.remove<SpriteComponent>(background);
            engine.world.emplace<SpriteComponent>(background, width, height, Background2);

        }
        else if (level==3)
        {
            engine.world.remove<SpriteComponent>(player1);
            engine.world.emplace<SpriteComponent>(player1, playerW, playerH, player3);

            engine.world.remove<SpriteComponent>(background);
            engine.world.emplace<SpriteComponent>(background, width, height, Background3);
        }

        
    /*
        // Draw Score
        int score;  // TODO score
        int auxiliary = score;
        int digit;
        Vec2D scorePosition(width*0.8, 700);
        Vec2D scoreScale(1,1);
        SDL_Rect scoreSpriteRect = {0, 0, 52, 65};

        if (score == 0)
            Graphics::DrawSprite(zeroSprite, scorePosition,scoreScale, 52, 65, 0, scoreSpriteRect);
        while (auxiliary > 0) 
        {
            digit = auxiliary % 10;
            auxiliary = auxiliary / 10;
            Graphics::DrawSprite(scoreMap[digit], scorePosition,scoreScale, 52, 65, 0, scoreSpriteRect);
            scorePosition.x -= 20;
        }
    */

        engine.render();
    }

    // deallocate memory
    SDL_DestroyTexture(player);
    SDL_DestroyTexture(player2);
    SDL_DestroyTexture(player3);
    SDL_DestroyTexture(ballSprite);
    SDL_DestroyTexture(Background);
    SDL_DestroyTexture(Background2);
    SDL_DestroyTexture(Background3);
    SDL_DestroyTexture(Wall);
    SDL_DestroyTexture(Ceiling);


    SDL_DestroyTexture(zeroSprite);
    SDL_DestroyTexture(twoSprite);
    SDL_DestroyTexture(threeSprite);
    SDL_DestroyTexture(fourSprite);
    SDL_DestroyTexture(fiveSprite);
    SDL_DestroyTexture(sixSprite);
    SDL_DestroyTexture(sevenSprite);
    SDL_DestroyTexture(eightSprite);
    SDL_DestroyTexture(nineSprite);

    Mix_FreeMusic(music);
    Mix_FreeChunk(ballHitSound);

    return 0;
}

