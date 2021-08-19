#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Movement.hpp"

class Jumping : public Movement
{

public:
    Jumping();

    Jumping(int, int);

    virtual ~Jumping();

    virtual void move(SDL_Renderer *) = 0;
};
