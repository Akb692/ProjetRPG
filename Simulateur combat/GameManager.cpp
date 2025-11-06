#include "GameManager.h"
#include "Berserker.h"
#include "Mage.h"
#include "Hybrid.h"
#include <iostream>
#include <cstdlib>

void GameManager::Init()
{
   
    TurnManage = new TurnManager();

    char input;
    std::string name;
    std::cout <<  "\033[31mGame init...\033[0m" << std::endl;
    Berserker TempBerserker("Berserker", 120, 20, 10, 5, 5, 10, true, 0, 0);
    Mage      TempMage("Mage", 100, 10, 5, 25, 10, 25, true, 0, 0);
    Hybrid    TempHybrid("Hybrid", 110, 15, 10, 15, 10, 12, true, 0, 0);

    TempBerserker.DisplayStat();
    TempMage.DisplayStat();
    TempHybrid.DisplayStat();

    std::cout << "Choose a class : Berserker (b/B) , Mage (m/M) , Hybrid (h/H)\n";
    std::cin >> input;

    while (input != 'b' && input != 'B' && input != 'm' && input != 'M' && input != 'h' && input != 'H')
    {
        std::cout << "Invalid input. Try again.";
        std::cin >> input;
    }

    std::cout << "Choose a name" << std::endl;
    std::cin >> name;

    Character* p = nullptr;

    if (input == 'b' || input == 'B')
        p = new Berserker(name, 120, 20, 10, 5, 5, 10, true, 0, 0);
    else if (input == 'm' || input == 'M')
        p = new Mage(name, 100, 10, 5, 25, 10, 25, true, 0, 0);
    else if (input == 'h' || input == 'H')
        p = new Hybrid(name, 110, 15, 10, 15, 10, 12, true, 0, 0);

    characters.push_back(p);
    player = p;
}

void GameManager::Run()
{
    bool gameRunning = true;
    while (gameRunning && player->IsAlive)
    {
        InputManage.MapAction(player, this);

        std::cout << "Current stats: " << std::endl;
        player->DisplayStat();
        
        std::cout << "Gold: " << player->Gold << std::endl;

        if (!player->IsAlive) {
            std::cout << "You have died... Game Over.";
            gameRunning = false;
        }
    }
}

void GameManager::StartCombat()
{
    int RandEnemy = rand() % 3 + 1;
    Character* Enemy = nullptr;
    switch (RandEnemy)
    {
    case 1:
        Enemy = new Berserker("The enemy", rand() % 10 + 60, rand() % 10 + 12, rand() % 10 + 6, rand() % 10 + 5, rand() % 10 + 5, rand() % 10 + 8, true, 0 , 0);
        break;
    case 2:
        Enemy = new Hybrid("The enemy", rand() % 10 + 60, rand() % 10 + 11, rand() % 10 + 7, rand() % 10 + 7, rand() % 10 + 7, rand() % 10 + 10, true, 0, 0);
        break;
    case 3:
        Enemy = new Mage("The enemy", rand() % 10 + 60, rand() % 10 + 10, rand() % 10 + 5, rand() % 10 + 14, rand() % 10 + 8, rand() % 10 + 9, true, 0, 0);
        break;
    }

    
    this->enemy = Enemy;

    

    bool CombatRunning = true;
    while (CombatRunning)
    {
        int choice = InputManage.AskAction();

        switch (choice)
        {
        case 1:
            player->Attack(*enemy);
            break;
        case 2:
            player->SpAttack(*enemy);
            break;
        case 3:
            player->ReceiveHeal();
            break;
        }

        if (enemy->IsAlive) {
            TurnManage->EnemyTurn(enemy, player);
        }

        std::cout << "player's ";
        player->DisplayHealth();

        std::cout << "enemy's ";
        enemy->DisplayHealth();

        enemy->IsDead(enemy);
        player->IsDead(player);

        if (!player->IsAlive)
        {
            std::cout << "defeat";
            CombatRunning = false;
        }

        if (!enemy->IsAlive)
        {
            int reward = rand() % 51 + 50;
            std::cout << "\033[32mvictoryyyyy  (+ " << reward << " gold)\033[0m" << std::endl;
            player->Gold += reward;
            CombatRunning = false;
        }
    }

    delete enemy;
    enemy = nullptr;
}

void GameManager::ShutDown()
{
    delete TurnManage;
    TurnManage = nullptr;

    for (auto* c : characters) delete c;
    characters.clear();
}
