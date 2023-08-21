#include "engine.hpp"

SDL_Renderer *Engine::renderer = nullptr;
bool Engine::closeWindow = false;

GameObject *player = new GameObject("assets/img/cube.png", 0, 0, 64, 64);

/**
 * @brief Construct a new Engine:: Engine object
 * 
 * @param w width of the window
 * @param h height of the window
 */
Engine::Engine(int w, int h)
{
    this->appName = "Roguelike";
    this->width = w;
    this->height = h;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
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
 /*   this->screen = SDL_GetWindowSurface(this->window);
    if (!this->screen)
    {
        std::cout << "SDL2 error:" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return;
    }*/
    Engine::renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(Engine::renderer, 255, 255, 255, 255);
    this->eventManager = new EventManager();
    SDL_Surface *temp = IMG_Load("assets/img/icon.png");
    SDL_SetWindowIcon(this->window, temp);
    SDL_FreeSurface(temp);
}

/**
 * @brief Destroy the Engine:: Engine object
 * 
 */
Engine::~Engine()
{   
    SDL_DestroyRenderer(Engine::renderer);
    //SDL_FreeSurface(this->screen);
    SDL_DestroyWindow(this->window);
    delete this->eventManager;
    SDL_Quit();
}

/**
 * @brief the game loop (executed every tick)
 * 
 */
void Engine::loop(void)
{
    while (!Engine::closeWindow)
    {
        this->eventManager->pollEvent();
        player->update();
        this->draw();
    }
    delete player;
}


/**
 * @brief draw the new frame to the screen
 * 
 */
void Engine::draw(void)
{
    SDL_RenderClear(Engine::renderer);
    player->draw();
    SDL_RenderPresent(Engine::renderer);
}