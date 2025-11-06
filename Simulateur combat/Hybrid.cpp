#include "Hybrid.h"
#include <iostream>
using namespace std;

Hybrid::Hybrid(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive, int gold,int potion)
    : Character(n, h, atk, def, spatk, spdef, spd, alive, gold,potion) {
}

void Hybrid::Attack(Character& target)
{
    cout << GetName() << " swings his arm! " << std::endl;
    target.TakeDmg(*this, StatAtk);
}
void Hybrid::SpAttack(Character& target)
{
    cout << GetName() << " summons mysterious entities! " << std::endl;
    target.TakeSpeDmg(*this, StatSpAtk);
}
