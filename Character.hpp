
#pragma once
#include "Game.hpp"
class Character
{
public:
    Character();
    Character(const char *texturesheet, int x, int y);
    ~Character();
    void virtual Update();
    void Render();
    SDL_Rect srcRect, destRect;

private:
    bool isalive;

protected:
    int xpos;
    int ypos;
    SDL_Texture *charTexture;
    SDL_Renderer *renderer;
    SDL_RendererFlip Flip;
};