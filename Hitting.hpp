#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Movement.hpp"

class Hitting : public Movement
{

public:
    Hitting();

    Hitting(int, int);

    virtual ~Hitting();

    virtual void move(SDL_Renderer *) = 0;
};
