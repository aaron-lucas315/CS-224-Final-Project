#include "Character.hpp"
#include "TextureManager.hpp"
Character::Character()
{
    xpos = 0;
    ypos = 0;
    Flip = SDL_FLIP_NONE;
}
Character::Character(const char *texturesheet, int x, int y)
{
    charTexture = TextureManager::LoadTexture(texturesheet);

    xpos = x;
    ypos = y;
    srcRect.h = 1955;
    srcRect.w = 1278;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 0.75;
    destRect.h = srcRect.h * 0.35;
}
void Character::Update()
{
    xpos++;
    ypos++;
    srcRect.h = 500;
    srcRect.w = 500;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}
void Character::Render()
{
    SDL_RenderCopyEx(Game::renderer, charTexture, &srcRect, &destRect, 0, NULL, Flip);
}
Character::~Character() {}