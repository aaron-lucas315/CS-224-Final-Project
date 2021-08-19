#include "Button.hpp"

Button::Button()
{
    m_xpos = 0;
    m_ypos = 0;
}

Button::Button(const char *texturesheet, int x, int y, int width, int height, int magnification, SDL_Renderer *renderer)
{
    charTexture = TextureManager::LoadTexture(texturesheet, renderer);

    m_xpos = x;
    m_ypos = y;
    m_height = height;
    m_width = width;

    srcRect.h = height;
    srcRect.w = width;
    srcRect.x = 0;
    srcRect.y = 0;

    desRect.w = srcRect.w * magnification;
    desRect.h = srcRect.h * magnification;
    desRect.x = m_xpos;
    desRect.y = m_ypos;
}

Button::~Button(){};

void Button::Update()
{
}

void Button::Render(SDL_Renderer *renderer)
{
    SDL_RenderCopyEx(renderer, charTexture, 0, &desRect, 0, NULL, SDL_FLIP_NONE);
}

bool Button::get_hovering()
{
    return m_hovering;
}

void Button::set_hovering(int mouse_posx, int mouse_posy)
{
    if (mouse_posx <= (m_xpos + m_width) &&
        mouse_posx >= m_xpos &&
        mouse_posy <= (m_ypos + m_height) &&
        mouse_posy >= m_ypos)
    {
        m_hovering = true;
        // std::cout << "Mouse is hovering" << std::endl;
    }

    else
    {
        m_hovering = false;
    }
}

int Button::get_Xpos()
{
    return m_xpos;
}

int Button::get_Ypos()
{
    return m_ypos;
}

int Button::get_width()
{
    return m_width;
}

int Button::get_height()
{
    return m_height;
}
