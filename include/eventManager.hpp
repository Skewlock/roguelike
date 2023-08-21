#pragma once
#include <SDL2/SDL.h>

class EventManager
{
    private:
        SDL_Event event;
    public:
        EventManager();
        ~EventManager();
        void pollEvent();
        void windowEventHandler();
        void keyboardEventHandler();
};