#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive, int gold ,int potions)
    : name(n), Health(h), MaxHealth(h), StatAtk(atk), StatDef(def), StatSpAtk(spatk), StatSpDef(spdef), StatSpeed(spd), Gold(gold),Potion(potions), IsAlive(alive) {
}

void Character::DisplayStat() const
{
    std::cout << "Name : " << name << std::endl;
    std::cout << "HP : " << MaxHealth << std::endl;
    std::cout << "Atk : " << StatAtk << std::endl;
    std::cout << "Def : " << StatDef << std::endl;
    std::cout << "SpeAtk : " << StatSpAtk << std::endl;
    std::cout << "SpeDef : " << StatSpDef << std::endl;
    std::cout << "Speed : " << StatSpeed << std::endl;
    std::cout << " " << std::endl;
}

int Character::DisplayHealth()
{
    std::cout << "HP : " << Health << std::endl;
    return Health;
}

void Character::TakeDmg(Character& c, int dmg)
{
    int RealDmg = dmg - (0.5 * StatDef);
    if (RealDmg < 0) RealDmg = 0;
    Health -= RealDmg;
    std::cout << ">> " << RealDmg << " dmg taken!" << std::endl;
}

void Character::TakeSpeDmg(Character& c, int dmg)
{
    int RealSpDmg = dmg - (0.5 * StatSpDef);
    if (RealSpDmg < 0) RealSpDmg = 0;
    Health -= RealSpDmg;
    std::cout << ">> " << RealSpDmg << " spe-dmg taken!" << std::endl;
}

void Character::ReceiveHeal()
{
    Health += 15;
    if (Health > MaxHealth) Health = MaxHealth;
    std::cout << ">> Healed to " << Health << " HP." << std::endl;
}

void Character::IsDead(Character* c)
{
    if (c->Health <= 0)
    {
        c->IsAlive = false;
    }
}

void Character::DisplayName() const
{
    std::cout << name;
}