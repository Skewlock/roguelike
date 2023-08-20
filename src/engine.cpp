#include "engine.hpp"


Engine::Engine(int w, int h)
{
    this->appName = "Roguelike";
    this->width = w;
    this->height = h;
    this->closeWindow = false;

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
    {
        std::cout << "Failed to initiate SDL Lib:" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return;
    }
    this->window = SDL_CreateWindow(this->appName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, 0);
    if (!this->window)
    {
        std::cout << "Failed to create SDL window" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return;
    }
    this->screen = SDL_GetWindowSurface(this->window);
    if (!this->screen)
    {
        std::cout << "SDL2 error:" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return;
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

Engine::~Engine()
{   
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(this->screen);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

/**
 * @brief update the app (executed every tick)
 * 
 */
void Engine::loop(void)
{
    SDL_Event event;
    while (!this->closeWindow)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                this->keyboardEventHandler(&event);
                break;
            case SDL_QUIT:
                this->closeWindow = true;
                break;
            
            case SDL_WINDOWEVENT:
                this->windowEventHandler(&event);
                break;

            default:
                break;
            }
        }
    }
}


/**
 * @brief draw the new frame (executed every tick)
 * 
 */
void Engine::draw(SDL_Texture *char_tex)
{
    //SDL_FillRect(this->screen, NULL, SDL_MapRGB(this->screen->format, 255, 255, 255));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, char_tex, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(this->window);
}

/**
 * @brief handle keyboard events
 * 
 * @param event 
 */
void Engine::keyboardEventHandler(SDL_Event *event)
{

}

/**
 * @brief manage the events related to the window
 * 
 */
void Engine::windowEventHandler(SDL_Event *event)
{
    switch (event->window.event)
    {
        // SDL_QUIT might not always work so to be sure this one does !
        case SDL_WINDOWEVENT_CLOSE:
            this->closeWindow = true;
            break;
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            this->screen = SDL_GetWindowSurface(this->window);
    }
}