#include "Pigeon.hpp"
#include "TextureManager.hpp"
#include <cstdio>  /* printf, scanf, puts, NULL */
#include <cstdlib> /* srand, rand */
#include <ctime>   /* time */

Pigeon::Pigeon(const char *texturesheet, int x, int y)
{
    // srand(time(NULL));
    // srcR.h = 32;
    // srcR.w = 32;
    // destR.x = rand() % 800 + 1;
    // destR.y = rand() % 450 + 1;
    // destR.h = 32;
    // destR.w = 32;

    charTexture = TextureManager::LoadTexture(texturesheet);

    xpos = x;
    ypos = y;
}
void Pigeon::Update()
{
    xpos++;
    ypos++;
    srcRect.h = 32;
    srcRect.w = 60;
    srcRect.x = 65;
    srcRect.y = 202;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

Pigeon::~Pigeon() {}
