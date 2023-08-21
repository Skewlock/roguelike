#include "gameObject.hpp"

GameObject::GameObject(const char *filename, int x = 0, int y = 0, int w = 32, int h = 32)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->texture = TextureManager::loadTexture(filename);
}

GameObject::~GameObject()
{
    SDL_DestroyTexture(this->texture);
}

void GameObject::draw(void)
{
    SDL_Rect dest;
    dest.x = this->x;
    dest.y = this->y;
    dest.w = this->w;
    dest.h = this->h;

    SDL_RenderCopy(Engine::renderer, this->texture, NULL, NULL);
}

void GameObject::update(void)
{
    this->x += 3;
    this->y += 3;
}