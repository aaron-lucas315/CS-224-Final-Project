#include "Node.hpp"
#pragma once
#include <iostream>

class List
{
private:
    Node *head;
    Node *tail;

public:
    List();
    bool is_empty();
    //void show(Shape *head);
    void append(Movement *ob);           //adds node to the list
    void drawlist(SDL_Renderer *render); //renders the linked list on the screen
    void reverse();                      // reverses the list
    void delete_move();                  // deletes the tail node
    ~List();
};