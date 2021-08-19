#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Movement.hpp"

class Walking:public Movement
{

public:
    Walking();

    Walking(int,int);

    virtual ~Walking();

    virtual void move(SDL_Renderer*)=0;

}
