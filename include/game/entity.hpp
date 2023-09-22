#pragma once
#include "gameObject.hpp"

class Entity: public GameObject
{
    protected:
        int speed;

    public:
        Entity(const char *filename, int s, int x, int y, int w, int h);
        ~Entity();
        virtual void update(void);
        virtual void move(void);
        int getX(void);
        int getY(void);
};