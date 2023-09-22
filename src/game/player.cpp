#include "player.hpp"
#include <iostream>

/**
 * @brief Construct a new Player:: Player object
 * 
 * @param filename path to texture
 * @param s default speed
 * @param x 
 * @param y 
 * @param w final width
 * @param h final height
 */
Player::Player(const char *filename, int s, int x = 0, int y = 0, int w = 32, int h = 32):
Entity(filename, s, x, y, w, h)
{
    this->speed = s;
    this->summonCd = 5000;
    this->summonTimer = new Timer();
    this->summonTimer->start();
}

/**
 * @brief Destroy the Player:: Player object
 * 
 */
Player::~Player()
{
    delete this->summonTimer;
}

/**
 * @brief update the logic
 * 
 */
void Player::update(void)
{
    if (Controller::summon)
    {
        if (this->summonTimer->get_ticks() >= this->summonCd)
        {
            this->summon();
            this->summonTimer->start();
        }
    }
    this->move();
}

void Player::summon(void)
{
    std::cout << "summoned" << std::endl;
    Engine::objectManager->addObject(new PlayerPet("assets/img/cube.png", 4, this, this->x, this->y, 48, 48));
}

/**
 * @brief move the player based on inputs
 * 
 */
void Player::move(void)
{
    this->x += (-Controller::left * this->speed + Controller::right * this->speed);
    this->y += (-Controller::up * this->speed + Controller::down * this->speed);
}

int Player::getX(void)
{
    return this->x;
}

int Player::getY(void)
{
    return this->y;
}