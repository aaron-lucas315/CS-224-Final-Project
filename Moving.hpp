#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "BackgroundObjects.hpp"

class Moving: public BackgroundObjects
{
private:

public:
    Moving();
    ~Moving();

};
