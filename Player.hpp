#pragma once
#include "Character.hpp"
#include "TextureManager.hpp"
#include "Game.hpp"

class Player : public Character
{
public:
    int jump;
    int hit;
    int duck;
    int forw;
    bool in_hit;
    bool in_duck;
    bool in_jump;
    bool in_forw;
    Player(const char *texturesheet, int x, int y);
    ~Player();
    void virtual Update(Uint32);
    int health;
    int score;
    void forward();
    void backward();
    void jumpp();
    void hitt();
    void duckk();

    // SDL_Texture *ourplayer;
    // SDL_Rect srcR, destR;
};
