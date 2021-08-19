#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Moving.hpp"

class Danda: public Moving
{
private:

public:
    Danda();
    ~Danda();

};

