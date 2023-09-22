#include "entity.hpp"
#include <iostream>

/**
 * @brief Construct a new Entity:: Entity object
 * 
 * @param filename path to texture
 * @param s default entity speed
 * @param x 
 * @param y 
 * @param w 
 * @param h 
 */
Entity::Entity(const char *filename, int s, int x = 0, int y = 0, int w = 32, int h = 32):
GameObject(filename, x, y, w, h)
{
    this->speed = s;
}

/**
 * @brief Destroy the Entity:: Entity object
 * 
 */
Entity::~Entity()
{

}

void Entity::update(void)
{

}

void Entity::move(void)
{
    
}

int Entity::getX(void)
{
    return this->x;
}

int Entity::getY(void)
{
    return this->y;
}