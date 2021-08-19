#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

class Movement
{
protected:
    int x, y;

public:
    Movement();

    Movement(int, int);

    virtual ~Movement();

    virtual void move(SDL_Renderer *) = 0;
};
