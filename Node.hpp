#pragma once
#include "Movement.hpp"

class Node
{
public:
    Movement *m_movement; //node stores a shape pointer
    Node *next = nullptr; //stores a pointer to the next node
};
