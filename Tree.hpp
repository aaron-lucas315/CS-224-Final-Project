#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Moving.hpp"

class Tree: public Moving
{
private:

public:
    Tree();
    ~Tree();

};

