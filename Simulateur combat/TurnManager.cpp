#include "TurnManager.h"


void TurnManager::EnemyTurn(Character* Enemy, Character* player)

{


	int Choice = rand() % 3 + 1;

	switch (Choice)
	{
	case 1:
		if (Enemy->IsAlive)
		{
			Enemy->Attack(*player);
			break;
		}

	case 2:
		if (Enemy->IsAlive)
		{
			Enemy->SpAttack(*player);
			break;
		}

	case 3:
		if (Enemy->IsAlive)
		{
			Enemy->ReceiveHeal();
			break;
		}
	}
}