#include "Player.hpp"
Player::Player(const char *texturesheet, int x, int y)
{
    //srcR.h = 128; //this is setting up the dimensions of the sprite on the screen
    //srcR.w = 128;

    charTexture = TextureManager::LoadTexture(texturesheet);

    xpos = x;
    ypos = y;
    jump = -1;
    hit = -1;
    duck = -1;
    forw = -1;
    in_duck = false;
    in_hit = false;
    in_jump = false;
    in_forw = false;
}
void Player::Update(Uint32 framerate)
{
    if (jump > -1 & jump < 8)
    {
        int temp = srcRect.x;
        srcRect.x = 65 * int(((SDL_GetTicks() / 100) % 8));

        if (temp != srcRect.x)
        {
            jump++;
        }
        if (jump < 4)
        {
            if (destRect.y - 10 >= 300)
            {
                destRect.y -= 10;
            }
        }
        else if (jump >= 5)
        {
            if (destRect.y + 10 <= 450)
                destRect.y += 10;
        }
        if (jump >= 8)
        {
            jump = -1;
            in_jump = false;
            destRect.y = ypos - 100;
        }
    }
    else if (duck > -1 & duck < 6)
    {
        srcRect.y = 1290;
        int temp = srcRect.x;
        int frame = int((SDL_GetTicks() / 100) % 6);
        if (frame < 6)
        {
            srcRect.x = 65 * frame;
        }
        //        else if (frame>=6)
        //        {
        //            srcRect.x=65*(frame-6);
        //        }

        if (temp != srcRect.x)
        {
            duck++;
        }

        if (duck >= 6)
        {
            duck = -1;
            in_duck = false;
            destRect.y = ypos - 100;
        }
    }
    else if (forw > -1 & forw < 8)
    {
        int temp = srcRect.x;
        srcRect.x = 64 * int(((SDL_GetTicks() / 50) % 8));

        if (temp != srcRect.x)
        {
            forw++;
            if (Flip == SDL_FLIP_NONE)
            {
                if (xpos + 5 < 800 - 100)
                {
                    xpos += 10;
                    destRect.x = xpos;
                }
            }
            else if (Flip == SDL_FLIP_HORIZONTAL)
            {
                if (xpos - 5 > 0)
                {
                    xpos -= 10;
                    destRect.x = xpos;
                }
            }
        }
        if (forw >= 8)
        {
            forw = -1;
            in_forw = false;
        }
    }
    else
    {
        srcRect.h = 64;
        srcRect.w = 65;
        srcRect.x = 65;
        srcRect.y = 711;

        destRect.x = xpos;
        destRect.y = ypos - 100;
        destRect.w = srcRect.w * 2;
        destRect.h = srcRect.h * 2;
    }
}
void Player::backward()
{
    Flip = SDL_FLIP_HORIZONTAL;
    if (xpos > 0 & !in_duck & !in_hit & !in_jump)
    {
        forw = 0;
        in_forw = true;
    }
}
void Player::forward()
{
    if (Flip == SDL_FLIP_HORIZONTAL)
    {
        Flip = SDL_FLIP_NONE;
    }
    if (xpos < 700 & !in_duck & !in_hit & !in_jump)
    {
        forw = 0;
        in_forw = true;
    }
}
void Player::jumpp()
{
    if (!in_forw & !in_duck & !in_hit)
    {
        jump = 0;
        in_jump = true;
    }
}

void Player::hitt()
{
    hit = 0;
    in_hit = true;
}

void Player::duckk()
{
    if (!in_jump & !in_hit & !in_forw)
    {
        duck = 0;
        in_duck = true;
    }
}
Player::~Player()
{
}
