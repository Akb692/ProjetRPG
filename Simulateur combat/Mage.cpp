#include "Mage.h"
#include <iostream>
using namespace std;

Mage::Mage(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive, int gold,int potion)
    : Character(n, h, atk, def, spatk, spdef, spd, alive, gold,potion) {
}

void Mage::Attack(Character& target)
{
    std::cout << GetName() << " strikes with his staff! " << std::endl;
    target.TakeDmg(*this, StatAtk);
}

void Mage::SpAttack(Character& target)
{
    cout << GetName() << " fires his fireballs! " << std::endl;
    target.TakeSpeDmg(*this, StatSpAtk);
}

void Mage::Heal()
{
    cout << GetName() << " heals himself! " << std::endl;
    ReceiveHeal();
}
