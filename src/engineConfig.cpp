#include "engineConfig.hpp"

/**
 * @brief Construct a new Engine Config:: Engine Config object
 * 
 * @param fps fps limit
 */
EngineConfig::EngineConfig(int fps)
{
    this->fpsLimit = fps;
    this->frameDelay = 1000/this->fpsLimit;
}

EngineConfig::EngineConfig()
{
    this->fpsLimit = 60;
    this->frameDelay = 1000/this->fpsLimit;

}

/**
 * @brief Destroy the Engine Config:: Engine Config object
 * 
 */
EngineConfig::~EngineConfig()
{

}

/**
 * @brief return the fps limit
 * 
 * @return int
 */
int EngineConfig::getFpsLimit(void)
{
    return this->fpsLimit;
}

/**
 * @brief set the fps limit
 * 
 * @param fps new limit
 */
void EngineConfig::setFpsLimit(int fps)
{
    this->fpsLimit = fps;
}

/**
 * @brief used to calculate the frame time eventually delay it
 * 
 */
void EngineConfig::limitFps1(void)
{
    this->frameStart = SDL_GetTicks64();
}

/**
 * @brief need to be called at the end of a frame execution (end of loop function)
 * 
 */
void EngineConfig::limitFps2()
{
    int frameTime = SDL_GetTicks64() - this->frameStart;
    if (this->frameDelay > frameTime)
        SDL_Delay(this->frameDelay - frameTime);
}