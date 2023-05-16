#include "Sounds.h"

Mix_Chunk *Sounds::LoadSound(const char* path)
{

    Mix_Chunk *sound = Mix_LoadWAV(path);

    if( sound == NULL )
    {
        std::string error = "Couldn't load " + std::string(path) + ": " + Mix_GetError();
		Log::Error(error);   
    }

    return sound;
}

void Sounds::PlaySound(Mix_Chunk *sound)
{
    if( Mix_PlayChannel(-1, sound, 0 ) == -1 )
    {
        std::string error = "Couldn't play sound: " + std::string(Mix_GetError());
        Log::Error(error);    
    }
}

void Sounds::SoundVolume(Mix_Chunk *sound, int volume)
{
    Mix_VolumeChunk(sound, volume);
}

Mix_Music *Sounds::LoadMusic(const char* path)
{

    Mix_Music *music = Mix_LoadMUS(path);

    if( music == NULL )
    {
        std::string error = "Couldn't load " + std::string(path) + ": " + Mix_GetError();
	    Log::Error(error);   
    }

    return music;
}

void Sounds::PlayMusic(Mix_Music *music)
{
    if( Mix_PlayMusic( music, -1 ) == -1 )
    {
        std::string error = "Couldn't play music: " + std::string(Mix_GetError());
	    Log::Error(error); 
    }
}

void Sounds::MusicVolume(Mix_Music *music, int volume)
{
    Mix_VolumeMusic(volume);
}
