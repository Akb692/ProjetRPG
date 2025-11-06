#include "InputManager.h"
#include "GameManager.h"
#include <iostream>
#include <cstdlib>

int InputManager::AskAction()
{
    int input;
    std::cout << "Select an action : ";
    std::cout << " 1 : Atk ";
    std::cout << " 2 : SpeAtk ";
    std::cout << " 3 : Heal "<< std::endl;
    std::cin >> input;

    while (input != 1 && input != 2 && input != 3)
    {
        std::cout << "Invalid choice. Try again : " << std::endl;
        std::cin >> input;
    }
    return input;
}

void InputManager::MapAction(Character* player, GameManager* gm)
{
    char choice;
    int encounter = rand() % 4 + 1;

    std::cout << "Choose a place to go : N/S/E/W " << std::endl;
    std::cin >> choice;

    while (choice != 'N' && choice != 'n' && choice != 'E' && choice != 'e' && choice != 'S' && choice != 's' && choice != 'W' && choice != 'w')
    {
        std::cout << "Invalid input. Try again." << std::endl;
        std::cin >> choice;
    }

    switch (encounter)
    {
    case 1: {
        int randgold = rand() % 51 + 50; 
        std::cout << "\033[33mYou find a chest ! : + " << randgold << " gold !\033[0m" << std::endl;
        break;
    }
    case 2:
        std::cout << "You find a loot (not implemented yet)" << std::endl;
        break;
    case 3:
        std::cout << "You encounter someone..." << std::endl;
        gm->StartCombat();
        break;
    case 4:
        std::cout << "Nothing seems to happen..." << std::endl;
        break;
    }
}
