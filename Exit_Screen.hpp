#include "Screen.hpp"

class Exit_Screen : public Screen
{
private:
    bool m_won_game;

public:
    void set_won_game(bool);
    bool get_won_game();
    virtual void display_screen(SDL_Renderer *);
};
