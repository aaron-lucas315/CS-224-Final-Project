#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Movement.hpp"

class Pooping : public Movement
{

public:
    Pooping();

    Pooping(int, int);

    virtual ~Pooping();

    virtual void move(SDL_Renderer *) = 0;
};
