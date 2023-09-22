#include "playerPet.hpp"

PlayerPet::PlayerPet(const char *filename, int s, Player *o, int x = 0, int y = 0, int w = 32, int h = 32):
Entity(filename,s, x, y, w, h)
{
    this->owner= o;
    this->speed = s;
}

/**
 * @brief Destroy the Entity:: Entity object
 * 
 */
PlayerPet::~PlayerPet()
{

}

void PlayerPet::update(void)
{
    this->move();
}

void PlayerPet::move(void)
{
    int diffX = this->owner->getX() - this->x;
    int diffY = this->owner->getY() - this->y;
    if (abs(diffX) > 45)
    {
        this->x += ((diffX < 0) ? -this->speed : this->speed);
    }
    if (abs(diffY) > 45)
    {
        this->y += ((diffY < 0) ? -this->speed : this->speed);
    }
}