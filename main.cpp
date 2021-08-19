#include "Game.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

#include <SDL_ttf.h>
#include <sstream>
Game *game = NULL;
int main(int argc, char *argv[])
{
    const int FPS = 60;                //for frame delay this is frame refresh rate i think
    const int frameDelay = 1000 / FPS; //max time between frames
    Uint32 frameStart;
    int frameTime;
    game = new Game();
    game->init("Pigeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while (game->running())
    {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update(frameDelay);
        game->render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();
    return 0;
}
