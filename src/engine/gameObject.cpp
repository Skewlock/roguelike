#include "gameObject.hpp"
#include <iostream>

/**
 * @brief Construct a new Game Object:: Game Object object
 * 
 * @param filename file path to texture
 * @param x x pos
 * @param y y pos
 * @param w width of final sprite
 * @param h height of final sprite
 */
GameObject::GameObject(const char *filename, int x = 0, int y = 0, int w = 32, int h = 32)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->texture = TextureManager::loadTexture(filename);
}

/**
 * @brief Destroy the Game Object:: Game Object object
 * 
 */
GameObject::~GameObject()
{
    SDL_DestroyTexture(this->texture);
}

/**
 * @brief update the renderer to add the object texture at x and y pos
 * 
 */
void GameObject::draw(void)
{
    uint32_t format;
    int access, width, height;
    SDL_Rect dest;
    SDL_Rect src;
    
    SDL_QueryTexture(this->texture, &format, &access, &width, &height);
    dest.x = this->x - this->w/2;
    dest.y = this->y - this->h/2;
    dest.w = this->w;
    dest.h = this->h;
    src.x = src.y = 0;
    src.w = width;
    src.h = height;
    TextureManager::drawTexture(this->texture, &src, &dest);
}

/**
 * @brief update the logic of the componant
 * 
 */
void GameObject::update(void)
{
    
}