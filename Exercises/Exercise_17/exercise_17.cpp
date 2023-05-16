#include "Engine2D.h"


int main(int argc, char *args[])
{
    int width = 800;
    int height = 800;

    Engine2D engine (width,height);

    // Init sprites
    SDL_Texture* tankLeft = Graphics::CreateSprite("../../assets/LeftAnim.png");
    SDL_Texture* tankRight = Graphics::CreateSprite("../../assets/RightAnim.png");

    // Load music and sounds
    Mix_Music *music = Mix_LoadMUS( "arcade_music.wav" );
    
    //If there was a problem loading the music
    if( music == NULL )
    {
       Log::Error("Couln't load music");    
    }

    //Play the music
    if( Mix_PlayMusic( music, -1 ) == -1 )
    {
        Log::Error("Couln't play music");
    }

    Mix_Chunk *ball_hit = Mix_LoadWAV( "ball_hit.wav" );
    if( ball_hit == NULL )
    {
       Log::Error("Couln't load ball_hit sound effect");    
    }


    const auto tank = engine.world.create();
    engine.world.emplace<NameGroupComponent>(tank, "player1", "player1");
    engine.world.emplace<GridMovementComponent>(tank, 100);
    engine.world.emplace<TransformComponent>(tank, Vec2D(400, 400));
    engine.world.emplace<SpriteComponent>(tank, 138, 130, tankRight);
    engine.world.emplace<AnimationComponent>(tank, 3, 8, true);

      


    while(engine.nextFrame())
    {
        

        engine.update();

        if(engine.keyboard.isLeftPressed)
        {
            auto& spriteComp = engine.world.get<SpriteComponent>(tank);
            spriteComp.texture = tankLeft;

            //Play the scratch effect
            if( Mix_PlayChannel( -1, ball_hit, 0 ) == -1 )
            {
                Log::Error("Couln't PLAY ball_hit sound effect");    
            }
        }

        if(engine.keyboard.isRightPressed)
        {
            auto& spriteComp = engine.world.get<SpriteComponent>(tank);
            spriteComp.texture = tankRight;
        }
        
        engine.render();
        
    }

    SDL_DestroyTexture(tankLeft);
    SDL_DestroyTexture(tankRight);

    //Free the music
    Mix_FreeMusic(music);
    Mix_FreeChunk( ball_hit );

    return 0;
}