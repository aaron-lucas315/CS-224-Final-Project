#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
class Game
{
public:
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update(Uint32);
    void render();
    void clean();
    bool running();
    bool checkCollision(SDL_Rect a, SDL_Rect b);
    static SDL_Renderer *renderer;
    SDL_Rect destR, srcR;
    SDL_Texture *background;
    int score;
    // Timer *mTimer;

private:
    int count = 0;
    bool isrunning;
    SDL_Window *window;
    // SDL_Renderer *renderer;
};
