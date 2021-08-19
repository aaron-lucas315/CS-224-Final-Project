#pragma once
#include "TextureManager.hpp"

class Button
{
private:
    // enum button_state
    // {
    //     MOUSE_OUT = 0,
    //     MOUSE_OVER = 1,
    //     CLICKED = 2
    // };
    SDL_Texture *charTexture;
    SDL_Rect srcRect, desRect;
    int m_xpos;
    int m_ypos;
    int m_width;
    int m_height;
    bool m_hovering;
    bool m_clicked;

public:
    Button();
    Button(const char *texturesheet, int x, int y, int width, int height, int magnification, SDL_Renderer *renderer);
    ~Button();
    void virtual Update();
    void Render(SDL_Renderer *renderer);

    bool get_hovering();
    void set_hovering(int, int);

    int get_height();
    int get_width();
    int get_Xpos();
    int get_Ypos();

};
