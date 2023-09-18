#include "eventManager.hpp"
#include "controller.hpp"
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
                    this->keyboardEventPressedHandler();
                    break;
                case SDL_KEYUP:
                    this->keyboardEventReleasedHandler();
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
void EventManager::keyboardEventPressedHandler()
{
    switch (this->event.key.keysym.sym)
    {
        case SDLK_z:
        case SDLK_UP:
            Controller::up = true;
            break;
        case SDLK_s:
        case SDLK_DOWN:
            Controller::down = true;
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            Controller::right = true;
            break;
        case SDLK_q:
        case SDLK_LEFT:
            Controller::left = true;
            break;
        default:
            break;
    }
}

void EventManager::keyboardEventReleasedHandler()
{
    switch (this->event.key.keysym.sym)
    {
        case SDLK_z:
        case SDLK_UP:
            Controller::up = false;
            break;
        case SDLK_s:
        case SDLK_DOWN:
            Controller::down = false;
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            Controller::right = false;
            break;
        case SDLK_q:
        case SDLK_LEFT:
            Controller::left = false;
            break;
        default:
            break;
    }
}