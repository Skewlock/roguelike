#pragma once
#include <cstdint>
#include <SDL2/SDL.h>

class EngineConfig
{
    private:
        int fpsLimit;
        int frameDelay;
        uint64_t frameStart;
    
    public:

        EngineConfig(int fps);
        EngineConfig();
        ~EngineConfig();

        int getFpsLimit(void);
        void setFpsLimit(int);
        void limitFps1(void);
        void limitFps2();
};