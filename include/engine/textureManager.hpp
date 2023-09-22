#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
    public:
        static SDL_Texture *loadTexture(const char* filename);
        static void drawTexture(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest);
};