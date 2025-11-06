#include "GameManager.h"
#include "Berserker.h"
#include "Mage.h"
#include "Hybrid.h"
#include "Boss.h"
#include <iostream>
#include <cstdlib>

void GameManager::Init()
{
   
    TurnManage = new TurnManager();

    char input;
    std::string name;
    std::cout <<  "\033[31mGame init...\033[0m" << std::endl;
    Berserker TempBerserker("Berserker", 120, 20, 10, 5, 5, 10, true, 0, 0, 0, true);
    Mage      TempMage("Mage", 100, 10, 5, 25, 10, 25, true, 0, 0, 0, true);
    Hybrid    TempHybrid("Hybrid", 110, 15, 10, 15, 10, 12, true, 0, 0, 0, true);

    TempBerserker.DisplayStat();
    std::cout << std::endl;
    TempMage.DisplayStat();
    std::cout << std::endl;
    TempHybrid.DisplayStat();
    std::cout << std::endl;

    std::cout << "Choose a class : Berserker (b/B) , Mage (m/M) , Hybrid (h/H)" << std::endl;
    std::cin >> input;

    while (input != 'b' && input != 'B' && input != 'm' && input != 'M' && input != 'h' && input != 'H')
    {
        std::cout << "Invalid input. Try again." << std::endl;
        std::cin >> input;
    }

    std::cout << "Choose a name" << std::endl;
    std::cin >> name;

    Character* p = nullptr;

    if (input == 'b' || input == 'B')
        p = new Berserker(name, 120, 20, 10, 5, 5, 10, true, 0, 0, 0, true);
    else if (input == 'm' || input == 'M')
        p = new Mage(name, 100, 10, 5, 25, 10, 25, true, 0, 0, 0, true);
    else if (input == 'h' || input == 'H')
        p = new Hybrid(name, 110, 15, 10, 15, 10, 12, true, 0, 0, 0, true);

    characters.push_back(p);
    player = p;
}

void GameManager::Run()
{
    bool gameRunning = true;
    while (gameRunning && player->IsAlive and player->isBossAlive)
    {
        InputManage.MapAction(player, this);

        std::cout << "Current stats: " << std::endl;
        player->DisplayStat();

        if (!player->IsAlive) {
            std::cout << "You have died... Game Over." << std::endl;
            gameRunning = false;
        }
        if (player->isBossAlive == false) 
        {
            std::cout << "\033[33mThe Final Boss has fallen... You WON the game!\033[0m" << std::endl;
            gameRunning = false;
        }
    }
}

void GameManager::StartCombat()
{
    
    int bonusHP = difficultyLevel * 3;
    int bonusStats = difficultyLevel * 2;
    int RandEnemy = rand() % 3 + 1;

    Character* Enemy = nullptr;
    switch (RandEnemy)
    {
    case 1:
        Enemy = new Berserker("The enemy", rand() % 10 + 60 + bonusHP, rand() % 10 + 12 + bonusStats, rand() % 10 + 6 + bonusStats, rand() % 10 + 5 + bonusStats, rand() % 10 + 5 + bonusStats, rand() % 10 + 8 + bonusStats, true, 0 , 0, 0, true);
        break;
    case 2:
        Enemy = new Hybrid("The enemy", rand() % 10 + 60 + bonusHP, rand() % 10 + 12 + bonusStats, rand() % 10 + 6 + bonusStats, rand() % 10 + 5 + bonusStats, rand() % 10 + 5 + bonusStats, rand() % 10 + 8 + bonusStats, true, 0, 0, 0, true);
        break;
    case 3:
        Enemy = new Mage("The enemy", rand() % 10 + 60 + bonusHP, rand() % 10 + 12 + bonusStats, rand() % 10 + 6 + bonusStats, rand() % 10 + 5 + bonusStats, rand() % 10 + 5 + bonusStats, rand() % 10 + 8 + bonusStats, true, 0, 0, 0, true);
        break;
    }

    
    this->enemy = Enemy;

    

    bool CombatRunning = true;
    while (CombatRunning)
    {
        
        if (player->StatSpeed >= enemy->StatSpeed)
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
                if (player->Potion > 0)
                {
                    player->Potion -= 1;
                    player->ReceiveHeal();
                    break;
                }
                else
                {
                    std::cout << "No potions left!" << std::endl;
                }
                break;
            }

            if (enemy->IsAlive) 
            {
                TurnManage->EnemyTurn(enemy, player);
            }
			
        }
        else
        {
            std::cout << "enemy's turn" << std::endl;
            TurnManage->EnemyTurn(enemy, player);

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
                if (player->Potion > 0)
                {
                    player->Potion -= 1;
                    player->ReceiveHeal();
                }
                else
                {
                    std::cout << "No potions left!" << std::endl;
                }
                break;
            }
            
		}

        std::cout << "player's ";
        player->DisplayHealth();

        std::cout << "enemy's ";
        enemy->DisplayHealth();

        enemy->IsDead(enemy);
        player->IsDead(player);

        if (!player->IsAlive)
        {
            std::cout << "you fallen.. may you rest in peace..." << std::endl;
            CombatRunning = false;
        }

        if (!enemy->IsAlive)
        {
            int reward = rand() % 51 + 50;
            std::cout << "\033[32m Enemy defeated !  (+ " << reward << " gold)\033[0m" << std::endl;
            player->Gold += reward;

			difficultyLevel += 1;
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

void GameManager::FinalBoss()
{
    
	std::cout << "You gently open the door.." << std::endl;
    std::cout << "You feel a strong aura" << std::endl;
	std::cout << "A giant figure appears before you.." << std::endl;

    Character* boss = nullptr;
    boss = new Boss("The Fallen Caporal", rand() % 10 + 60, rand() % 10 + 12, rand() % 10 + 6, rand() % 10 + 5, rand() % 10 + 5, rand() % 10 + 8, true, 0, 0, 0, true);

    this->enemy = boss;

    bool CombatRunning = true;
    while (CombatRunning and player->isBossAlive)
    {
        if (player->StatSpeed >= enemy->StatSpeed)
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
                if (player->Potion > 0)
                {
                    player->Potion -= 1;
                    player->ReceiveHeal();
                }
                else
                {
                    std::cout << "No potions left!" << std::endl;
                }
                break;
            
            }

            if (enemy->IsAlive)
            {
                TurnManage->EnemyTurn(enemy, player);
            }

        }
        else
        {
            std::cout << "enemy's turn" << std::endl;
            TurnManage->EnemyTurn(enemy, player);

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
                if (player->Potion > 0)
                {
                    player->Potion -= 1;
                    player->ReceiveHeal();
                }
                else
                {
                    std::cout << "No potions left!" << std::endl;
                }
                break;
            }

        }

        std::cout << "player's " << std::endl;
        player->DisplayHealth();

        std::cout << "enemy's " << std::endl;
        enemy->DisplayHealth();

        enemy->IsDead(enemy);
        player->IsDead(player);

        if (!player->IsAlive)
        {
            std::cout << "defeat" << std::endl;
            CombatRunning = false;
        }

        if (!enemy->IsAlive)
        {
            std::cout << "\033[32m the end..\033[0m" << std::endl;
            player->isBossAlive = false;
            CombatRunning = false;
        }
    }
	delete enemy;
	enemy = nullptr;
}