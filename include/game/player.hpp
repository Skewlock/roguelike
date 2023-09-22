#pragma once
#include "engine.hpp"
#include "controller.hpp"
#include "playerPet.hpp"
#include "entity.hpp"
#include "timer.hpp"

class Player: public Entity
{
    private:
        int summonCd;
        Timer *summonTimer;

    public:
        Player(const char *filename, int s, int x, int y, int w, int h);
        ~Player();
        void update(void);
        void move(void);
        void summon(void);
        int getX(void);
        int getY(void);
};