#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

class Engine
{
    private:
        SDL_Surface *screen;
        SDL_Window *window;
        SDL_Renderer *renderer;

        const char *appName;
        int width;
        int height;
        bool closeWindow;

    public:
        Engine(int w, int h);
        ~Engine();

        void inputHandler(void);
        void loop(void);
        void draw(SDL_Texture *char_tex);
        void keyboardEventHandler(SDL_Event *event);
        void windowEventHandler(SDL_Event *event);
};