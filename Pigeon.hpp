#pragma once
#include "Character.hpp"
#include "TextureManager.hpp"
#include "Game.hpp"
class Pigeon : public Character
{
public:
    Pigeon(const char *texturesheet, int x, int y);
    ~Pigeon();
    void virtual Update();

private:
    bool isflying;
    bool ispooping;
};