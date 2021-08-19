#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Movement.hpp"

class Flying : public Movement
{

public:
    Flying();

    Flying(int, int);

    virtual ~Flying();

    virtual void move(SDL_Renderer *) = 0;
};
