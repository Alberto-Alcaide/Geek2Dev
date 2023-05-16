#ifndef SOUNDS_H
#define SOUNDS_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "Log.h"


class Sounds
{
public:
    static Mix_Chunk* LoadSound(const char* sound); 
    static void PlaySound(Mix_Chunk* sound); 
    // volume ranges from 0 to 128
    static void SoundVolume(Mix_Chunk* sound, int volume); 

    static Mix_Music* LoadMusic(const char* music);
    static void PlayMusic(Mix_Music* music);
    // volume ranges from 0 to 128
    static void MusicVolume(Mix_Music* music, int volume); 
};


#endif