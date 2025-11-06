#include "Boss.h"
#include <iostream>
using namespace std;

Boss::Boss(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive, int gold, int potion, int bosskey,bool isBossAlive)
    : Character(n, h, atk, def, spatk, spdef, spd, alive, gold, potion, bosskey, isBossAlive) {
}

void Boss::Attack(Character& target)
{
    cout << GetName() << " jumps at you !" << std::endl;
    target.TakeDmg(*this, StatAtk);
}

void Boss::Rage(Character&)
{
    std::cout << GetName() << "gets enraged! +10 Atk" << std::endl;
    StatAtk += 10;
}

void Boss::SpAttack(Character& target)
{
    std::cout << GetName() << "reminds you how weak you truly are.." << std::endl;
    target.TakeSpeDmg(*this, StatAtk);
}
