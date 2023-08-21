#include "eventManager.hpp"
#include "engine.hpp"
#include <iostream>

EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

/**
 * @brief poll events to process them
 * 
 */
void EventManager::pollEvent()
{
    while (SDL_PollEvent(&this->event) != 0)
        {
            switch (this->event.type)
            {
                case SDL_KEYDOWN:
                    this->keyboardEventHandler();
                    break;
                case SDL_QUIT:
                    Engine::closeWindow = true;
                    break;

                case SDL_WINDOWEVENT:
                    this->windowEventHandler();
                    break;

                default:
                    break;
            }
        }
}

/**
 * @brief manage the events related to the window
 * 
 */
void EventManager::windowEventHandler()
{
    switch (this->event.window.type)
    {
        // SDL_QUIT might not always work so to be sure this one does !
        case SDL_WINDOWEVENT_CLOSE:
            Engine::closeWindow = true;
            break;
    }
}

/**
 * @brief handle keyboard events
 * 
 */
void EventManager::keyboardEventHandler()
{
    std::cout << "Key pressed" << std::endl;
    switch (this->event.key.keysym.sym)
    {
        default:
            break;
    }
}