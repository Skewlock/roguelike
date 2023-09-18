#include "player.hpp"
#include <iostream>

Player::Player(const char *filename, int s, int x = 0, int y = 0, int w = 32, int h = 32):
GameObject(filename, x, y, w, h)
{
    this->speed = s;
}

Player::~Player()
{

}

void Player::update(void)
{
    if (Controller::up)
        this->moveUp();
    else if (Controller::down)
        this->moveDown();
    if (Controller::right)
        this->moveRight();
    else if (Controller::left)
        this->moveLeft();
}

void Player::moveUp(void)
{
    this->y -= this->speed;
}
void Player::moveDown(void)
{
    this->y += this->speed;
}

void Player::moveRight(void)
{
    this->x += this->speed;
}

void Player::moveLeft(void)
{
    this->x -= this->speed;
}