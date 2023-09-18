#pragma once
#include "controller.hpp"
#include "gameObject.hpp"

class Player: public GameObject
{
    private:
        int speed;

    public:
        Player(const char *filename, int s, int x, int y, int w, int h);
        ~Player();
        void update(void);
        void moveUp(void);
        void moveDown(void);
        void moveRight(void);
        void moveLeft(void);
};