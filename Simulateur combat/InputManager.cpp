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
    char choice2;
    int encounter = rand() % 6 + 1;

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
        player->Gold += randgold;
        break;
    }
    case 2:
        std::cout << "Something is glowing..." << std::endl;
        std::cout << "Do you take the risk ? (Y/N)" << std::endl;
        std::cin >> choice2;
        if (choice2 == 'y' || choice2 == 'Y')
        {
			int randchoice = rand() % 2 + 1;
            if (randchoice == 1)
            {
                int randpotion = rand() % 2 + 1;
                std::cout << "\032[32mYou found " << randpotion << " potion(s) !\032[0m" << std::endl;
                player->Potion += randpotion;
            }
            else if (randchoice == 2)
            {
                int randdmg = rand() % 21 + 10;
                std::cout << "\033[31m It was a trap ! You encounter someone...\033[0m" << std::endl;
                gm->StartCombat();
			}
		}
        else
        {
            std::cout << "You decide to walk away cautiously." << std::endl;
        }
        break;
    case 3:
        std::cout << "You encounter someone..." << std::endl;
        gm->StartCombat();
        break;
    case 4:
        std::cout << "Nothing seems to happen..." << std::endl;
        break;
    case 5:
        char choice;
        std::cout << "you encounter a merchant..." << std::endl;
        std::cout << "do you want to meet him ? (Y/N)" << std::endl;
		std::cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            int buychoice;
            std::cout << "1 : Buy Potion (20 gold) " << std::endl;
            std::cout << "2 : Buy a mysterious key (500 gold) " << std::endl;
            std::cout << "3 : Increase a stat (80 gold) " << std::endl;
            std::cout << "4 : Leave " << std::endl;
            std::cin >> buychoice;
            if (buychoice == 1)
            {
                if (player->Gold >= 20)
                {
                    player->Gold -= 20;
                    player->Potion += 1;
                    std::cout << "You bought a potion!" << std::endl;
                }
                else 
                {
                    std::cout << "Not enough gold!" << std::endl;
                }
            }
            else if (buychoice == 2)
            {
                if(player->FinalBossKey >= 1)
                {
                    std::cout << "There's no key to buy anymore.." << std::endl;
                    return;
				}
                if (player->Gold >= 500)
                {
                    player->Gold -= 500;
                    player->FinalBossKey += 1;
                    std::cout << "You bought a mysterious key!" << std::endl;
                }
                else
                {
                    std::cout << "Not enough gold!" << std::endl;
                }
			}
            else if (buychoice == 3)
            {
                if (player->Gold >= 80)
                {
                    int statchoice;
                    std::cout << "Which stat do you want to increase? " << std::endl;
                    std::cout << "1 : Atk " << std::endl;
                    std::cout << "2 : Def " << std::endl;
                    std::cout << "3 : SpeAtk " << std::endl;
                    std::cout << "4 : SpeDef " << std::endl;
                    std::cout << "5 : Speed " << std::endl;
                    std::cin >> statchoice;
                    switch (statchoice)
                    {
                    case 1:
                        player->StatAtk += 5;
                        break;
                    case 2:
                        player->StatDef += 5;
                        break;
                    case 3:
                        player->StatSpAtk += 5;
                        break;
                    case 4:
                        player->StatSpDef += 5;
                        break;
                    case 5:
                        player->StatSpeed += 5;
                        break;
                    default:
                        std::cout << "Invalid choice." << std::endl;
                        return;
                    }
                    player->Gold -= 80;
                    std::cout << "Stat increased!" << std::endl;
                }
                else
                {
                    std::cout << "Not enough gold!" << std::endl;
                }
            }
			else if (buychoice == 4)
            {
                std::cout << "You leave the merchant." << std::endl;
            }
        }
        else
        {
            std::cout << "You ignore him and walk away.." << std::endl;
		}
		break;
    
    case 6:
        char choice3;
        std::cout << "you found a giant door.." << std::endl;
        std::cout << "Use the key ? (Y/N)" << std::endl;
		std::cin >> choice3;
        if(choice3 == 'y' || choice3 == 'Y')
        {
            if (player->FinalBossKey >= 1)
            {
                std::cout << "You use the key to open the door..." << std::endl;
                gm->FinalBoss();
            }
            else
            {
                std::cout << "You don't have the key..." << std::endl;
            }
        }
        else
        {
            std::cout << "You decide to leave the door alone." << std::endl;
		}
    }
}
