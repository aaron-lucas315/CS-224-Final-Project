#pragma once
#include "Globals.hpp"

class Screen
{
protected:
    SDL_Texture *m_background;

public:
    Screen();
    Screen(SDL_Renderer *renderer);
    virtual ~Screen();
    virtual void render(SDL_Renderer *renderer);
    virtual std::string button_hover(int, int);
    // virtual void check_button(std::string &cur_screen);
    virtual void update(bool& , std::string&, SDL_Renderer* renderer);
};
