#include "Berserker.h"
#include <iostream>
using namespace std;

Berserker::Berserker(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive, int gold, int potion)
    : Character(n, h, atk, def, spatk, spdef, spd, alive, gold, potion) {
}

void Berserker::Attack(Character& target)
{
    cout << GetName()<< " swings his sword!" << std::endl;
    target.TakeDmg(*this, StatAtk);
}

void Berserker::Rage(Character&)
{
    std::cout << GetName() << "gets enraged! +10 Atk" << std::endl;
    StatAtk += 10;
}

void Berserker::SpAttack(Character& target)
{
    std::cout << "it does nothing ! " << std::endl;
}
