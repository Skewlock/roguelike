#include "textureManager.hpp"
#include "engine.hpp"

/**
 * @brief load a texture from a file
 * 
 * @param filename the file name
 * @return SDL_Texture* the texture created
 */
SDL_Texture *TextureManager::loadTexture(const char *filename)
{
    SDL_Surface *surface = IMG_Load(filename);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Engine::renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

/**
 * @brief Draw the supplied texture on the screen
 * 
 * @param texture the texture to draw
 * @param x x coord to draw the texture at
 * @param y y coord to draw the texture at
 * @param w width of the texture
 * @param h height of the texture
 */
void TextureManager::drawTexture(SDL_Texture *texture, int x, int y, int w, int h)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.h = h;
    dest.w = w;
    SDL_RenderCopy(Engine::renderer, texture, NULL, &dest);
}