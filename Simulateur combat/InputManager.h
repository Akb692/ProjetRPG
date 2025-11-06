#pragma once
#include "Character.h"

// Forward declaration pour éviter l'inclusion circulaire
class GameManager;

class InputManager
{
public:
    int AskAction();
    void MapAction(Character* player, GameManager* gm);
};
