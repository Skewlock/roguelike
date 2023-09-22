#pragma once
#include "player.hpp"
#include "entity.hpp"

class Player;

class PlayerPet:public Entity
{
    protected:
        Entity *owner;

    public:
        PlayerPet(const char *filename, int s, Player *o, int x, int y, int w, int h);
        ~PlayerPet();
        void update(void);
        void move(void);
};