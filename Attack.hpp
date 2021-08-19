#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Movement.hpp"

class Attack : public Movement
{

public:
    Attack();

    Attack(int, int);

    ~Attack();

    void move(SDL_Renderer *);
};
