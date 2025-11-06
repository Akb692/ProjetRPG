#pragma once
#include <vector>
#include "Character.h"
#include "InputManager.h"
#include "TurnManager.h"

class GameManager
{
private:
    std::vector<Character*> characters;
    TurnManager* TurnManage = nullptr;
    InputManager InputManage;

    Character* player = nullptr;
    Character* enemy = nullptr;

public:
    void Init();
    void Run();
    void ShutDown();
    void Test();
    void StartCombat();
};
