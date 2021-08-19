#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Movement.hpp"

class Ducking : public Movement
{

public:
    Ducking();

    Ducking(int, int);

    virtual ~Ducking();

    virtual void move(SDL_Renderer *) = 0;
};
