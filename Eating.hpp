#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Movement.hpp"

class Eating : public Movement
{

public:
    Eating();

    Eating(int, int);

    virtual ~Eating();

    virtual void move(SDL_Renderer *) = 0;
};