#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "eventManager.hpp"
#include "gameObject.hpp"

class Engine
{
    private:

        //SDL_Surface *screen;
        SDL_Window *window;

        EventManager *eventManager;

        const char *appName;
        int width;
        int height;

    public:
        Engine(int w, int h);
        ~Engine();

        static SDL_Renderer *renderer;
        static bool closeWindow;

        void inputHandler(void);
        void loop(void);
        void draw(void);
        void keyboardEventHandler(SDL_Event *event);
        void windowEventHandler(SDL_Event *event);
};