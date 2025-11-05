#include "InputManager.h"
#include "Character.h"
#include "GameManager.h"

int InputManager::AskAction()
{
	int input;

	std::cout << "Select an action : " << std::endl;
	std::cout << " 1 : Atk " << std::endl;
	std::cout << " 2 : SpeAtk " << std::endl;
	std::cout << " 3 : Heal " << std::endl;
	std::cin >> input;

	if (input != 1 and input != 2 and input != 3)
	{
		std::cout << "Invalid choice. Try again : ";
		std::cin >> input;
	}

	return input;
}

void InputManager::MapAction()
{
	char choice;
	int encounter = rand() % 3 + 1;

	std::cout << "Choose a place to go : N/S/E/W " << std::endl;

	std::cin >> choice;

	while (choice != 'N' and choice != 'n' and choice != 'E' and choice != 'e' and choice != 'S' and choice != 's' and choice != 'W' and choice != 'w')
	{
		std::cout << "Invalid input. Try again." << std::endl;
		std::cin >> choice;
	}

	
	switch (encounter)
	{
	case 1:
		std::cout << "You find a chest" << std::endl;
		break;
	case 2:
		std::cout << "You find a loot" << std::endl;
		break;
	case 3:
		std::cout << "You find a mob" << std::endl;
		break;
	}

}