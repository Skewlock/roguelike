#pragma once
#include <SDL2/SDL.h>
#include "textureManager.hpp"

class GameObject
{
    protected:

        SDL_Texture *texture;
        int x;
        int y;
        int w;
        int h;
    
    public:

        GameObject(const char *filename, int x, int y, int w, int h);
        ~GameObject();
        void draw(void);
        virtual void update(void);
};