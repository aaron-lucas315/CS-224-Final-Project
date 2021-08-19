#include "Game.hpp"
#include "TextureManager.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include "Pigeon.hpp"
#include "Player.hpp"
#include "Character.hpp"
#include <string>
#include <cstdio>  /* printf, scanf, puts, NULL */
#include <cstdlib> /* srand, rand */
#include <ctime>   /* time */

//Character *tempplayer;
Pigeon *newpig;
Player *player;
Character **parray;
Character *bg;

SDL_Renderer *Game::renderer = NULL;

Game::Game()
{
    score = 0;
    srcR.h = 500;
    srcR.w = 500;
    srcR.x = 0;
    srcR.y = 0;
    destR.x = 0;
    destR.y = 0;
    destR.w = srcR.w * 4;
    destR.h = srcR.h * 4;
    const char *x = "assets/lol.jpeg";
    background = TextureManager::LoadTexture(x);
}
Game::~Game()
{
}
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialised...\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created! \n";
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created! \n";
        }
        isrunning = true;
    }
    else
    {
        isrunning = false;
    }
    srand(time(NULL));

    newpig = new Pigeon("assets/pigeon.PNG", 0, rand() % 450 + 1);
    player = new Player("assets/spritesheet.PNG", 0, 550);
    bg = new Character("assets/lol.jpeg", 0, 0);
    parray = new Character *[10];
    for (int i = 0; i < 10; i++)
    {
        parray[i] = new Pigeon("assets/pigeon.PNG", rand() % 650 + 1, rand() % 450 + 1);
    }
    //playerTex.ourplayer = TextureManager::LoadTexture("assets/playerr.png");
    // pigeonTex.onepigeon = TextureManager::LoadTexture("assets/pigeon.jpg", renderer);
    // pigeonTex2.onepigeon = TextureManager::LoadTexture("assets/playerr.png", renderer);
}
void Game::handleEvents()
{
    bool in_jump = false;
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isrunning = false;
        break;

    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_LEFT)
        {
            player->backward();
        }
        else if (event.key.keysym.sym == SDLK_RIGHT)
        {
            player->forward();
        }
    case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_SPACE)
        {
            if (!player->in_jump)
            {
                player->jumpp();
            }
        }
        if (event.key.keysym.sym == SDLK_RSHIFT)
        {
            player->hitt();
        }
        if (event.key.keysym.sym == SDLK_DOWN)
        {
            player->duckk();
        }

    default:
        break;
    }
}
void Game::update(Uint32 framerate)
{

    //tempplayer->Update();
    if (newpig != nullptr)
    {
        newpig->Update();
        if (checkCollision(newpig->destRect, player->destRect))
        {
            score++;
            newpig = nullptr;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (parray[i] != nullptr)
        {
            parray[i]->Update();
            if (checkCollision(parray[i]->destRect, player->destRect))
            {
                score++;
                parray[i] = nullptr;
            }
        }
    }
    player->Update(framerate);
    if (count % 100 == 0)
    {
        std::cout << score << "\n";
    }
    count++;
    /* THIS WAS WHERE PIGEON MOVEMENT WAS DICTATED
*/
}
bool Game::running()
{
    return isrunning;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //tempplayer->Render();
    bg->Render();
    SDL_RenderCopy(Game::renderer, background, &srcR, &destR);
    if (newpig != nullptr)
    {
        newpig->Render();
    }
    for (int i = 0; i < 10; i++)
    {
        int a = rand() % 1000 + 1;
        if (parray[i] != nullptr and a > 500)
        {
            parray[i]->Render();
        }
    }
    player->Render();
    //ADD STUFF TO RENDER (TEXTURES)
    //rendered in sequence
    // SDL_RenderCopy(renderer, pigeonTex.onepigeon, NULL, &pigeonTex.destR);
    // SDL_RenderCopy(renderer, playerTex.ourplayer, NULL, &playerTex.destR);
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned \n";
}

bool Game::checkCollision(SDL_Rect a, SDL_Rect b)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    //If any of the sides from A are outside of B
    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}