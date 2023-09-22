#pragma once
#include <SDL2/SDL.h>

class Timer
{
    private:
        Uint64 startTicks;
        Uint64 pausedTicks;
        bool paused;
        bool started;
 
    public:
        Timer();
        void start(void);
        void stop(void);
        void pause(void);
        void unpause(void);
        int get_ticks(void);
        bool is_started(void);
        bool is_paused(void);
};