#include "timer.hpp"

Timer::Timer()
{
    this->startTicks = 0;
    this->pausedTicks = 0;
    this->paused = false;
    this->started= false;
}

void Timer::start(void)
{
    this->started = true;
    this->paused = false;
    this->startTicks = SDL_GetTicks64();
}

void Timer::stop(void)
{
    this->started = false;
    this->paused = false;
}

int Timer::get_ticks(void)
{
    if (this->started)
    {
        if (this->paused)
        {
            return this->pausedTicks;
        }
        else
        {
            return (SDL_GetTicks64() - this->startTicks);
        }
    }
    return 0;
}

void Timer::pause(void)
{
    if (this->started && !this->paused)
    {
        this->paused = true;
        this->pausedTicks = SDL_GetTicks64() - this->startTicks;
    }
}

void Timer::unpause(void)
{
    if (this->paused)
    {
        this->paused = false;
        this->startTicks = SDL_GetTicks64() - this->pausedTicks;
        this->pausedTicks = 0;
    }
}

bool Timer::is_paused(void)
{
    return this->paused;
}

bool Timer::is_started(void)
{
    return this->started;
}