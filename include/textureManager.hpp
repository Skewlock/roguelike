#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
    public:
        static SDL_Texture *loadTexture(const char* filename);
        static void drawTexture(SDL_Texture *texture, int x, int y, int w, int h);
};