#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <SDL2/SDL.h>
#include <vector>

struct AnimationComponent
{
    int numFrames;
    int currentFrame;
    int frameSpeedRate;
    bool isLoop;
    int startTime;

    AnimationComponent(int numFrames = 1, int frameSpeedRate = 5, bool isLoop = true)
    {
        this->numFrames = numFrames;
        this->frameSpeedRate = frameSpeedRate;
        this->isLoop = isLoop;

        currentFrame = 0;
        startTime = SDL_GetTicks();
    };

    /*
    SDL_Texture* cropTexture(SDL_Renderer* renderer, SDL_Texture* originalTexture, SDL_Rect cropRect)
    {
        // Get the dimensions of the original texture
        int originalWidth, originalHeight;
        SDL_QueryTexture(originalTexture, NULL, NULL, &originalWidth, &originalHeight);

        // Create a new surface with the same dimensions as the cropped portion of the original texture
        SDL_Surface* croppedSurface = SDL_CreateRGBSurface(0, cropRect.w, cropRect.h, 32, 0, 0, 0, 0);

        // Copy the pixels from the original texture to the new surface
        SDL_Rect sourceRect = {cropRect.x, cropRect.y, cropRect.w, cropRect.h};
        SDL_BlitSurface(SDL_CreateRGBSurface(0, originalWidth, originalHeight, 32, 0, 0, 0, 0), &sourceRect, SDL_GetWindowSurface(renderer), NULL);

        // Create a new texture from the surface
        SDL_Texture* croppedTexture = SDL_CreateTextureFromSurface(renderer, croppedSurface);

        // Free the surface
        SDL_FreeSurface(croppedSurface);

        // Return the new cropped texture
        return croppedTexture;
    }
    */


};

#endif