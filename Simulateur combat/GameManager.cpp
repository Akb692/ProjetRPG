#include "GameManager.h"
#include "Character.h"
#include "Berserker.h"
#include "Mage.h"
#include "Hybrid.h"
#include "InputManager.h"
#include "TurnManager.h"
void GameManager::Init()
{
	char input;
	std::string name;
	Berserker TempBerserker("Berserker", 120, 20, 10, 5, 5, 10, true);
	Mage TempMage("Mage", 100, 10, 5, 25, 10, 25, true);
	Hybrid TempHybrid("Hybrid", 110, 15, 10, 15, 10, 12, true);
	std::cout << "Game init..." << std::endl;


	std::cout << " " << std::endl;
	TempBerserker.DisplayStat();
	std::cout << " " << std::endl;
	TempMage.DisplayStat();
	std::cout << " " << std::endl;
	TempHybrid.DisplayStat();

	std::cout << "Choose a class : Berserker (b/B) , Mage (m/M) , Hybrid (h/H)  " << std::endl;

	std::cin >> input;

	while (input != 'b' and input != 'B' and input != 'm' and input != 'M' and input != 'h' and input != 'H')
	{
		std::cout << "Invalid input. Try again." << std::endl;
		std::cin >> input;
	} 

	std::cout << "Choose a name" << std::endl;
	std::cin >> name;

	Character* p = nullptr;

	if (input == 'b' or input == 'B')
	{
		 p = new Berserker(name, 120, 20, 10, 5, 5, 10, true);
		
	}
	else if (input == 'm' or input == 'M')
	{
		p = new Mage(name, 100, 10, 5, 25, 10, 25, true);
	}
	else if (input == 'h' or input == 'H')
	{
		p = new Hybrid(name, 110, 15, 10, 15, 10, 12, true);
	}
	else 
	{
		std::cout << "Invalid input. Try again." << std::endl;
		std::cin >> input;
	}

	characters.push_back(p);

	player = p;


	Character* e = new Mage("Enemy1", 50, 10, 5, 25, 10, 25, true);
	characters.push_back(e);
	enemy = e; 
}

void GameManager::Run()
{
	bool gameRunning = true;
	while (gameRunning)
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

		

		TurnManage->EnemyTurn(enemy, player);

		std::cout << " " << std::endl;

		std::cout << "player's ";
		player->DisplayHealth();

		std::cout << " " << std::endl;

		std::cout << "enemy's ";
		enemy->DisplayHealth();

		std::cout << " " << std::endl;

		enemy->IsDead(enemy);
		player->IsDead(player);

		if(player->IsAlive == false)
		{
			std::cout << "defeat" << std::endl;
			gameRunning = false;
		}

		if (enemy->IsAlive == false)
		{
			std::cout << "victoryyyyy" << std::endl;
			gameRunning = false;
		}
	}
}

void GameManager::Test()
{
	InputManage.MapAction();
}