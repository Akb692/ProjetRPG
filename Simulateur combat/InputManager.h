#pragma once
#include "Character.h"
class GameManager;

class InputManager
{
public:
    int AskAction();
    void MapAction(Character* player, GameManager* gm);
};
