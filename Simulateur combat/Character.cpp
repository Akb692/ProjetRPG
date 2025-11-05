#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive)
	: name(n), Health(h),MaxHealth(h), StatAtk(atk), StatDef(def), StatSpAtk(spatk), StatSpDef(spdef), StatSpeed(spd), IsAlive(alive) { }

void Character::DisplayStat() const
{
    std::cout << "Name : " << name << std::endl;
    std::cout << "HP : " << Health << std::endl;
    std::cout << "Atk : " << StatAtk << std::endl;
    std::cout << "Def : " << StatDef << std::endl;
    std::cout << "SpeAtk : " << StatSpAtk << std::endl;
    std::cout << "SpeDef : " << StatSpDef << std::endl;
    std::cout << "Speed : " << StatSpeed << std::endl;
    std::cout << endl;
}

int Character::DisplayHealth()
{
    std::cout << "HP : " << Health << std::endl;
    return 0;
}

void Character::TakeDmg(Character& c, int dmg)
{
    int RealDmg = (dmg - (0.5 * StatDef));
    Health = Health - RealDmg ;
    std::cout << c.name << " inflicts " << RealDmg << " damages to " << name << " ! " << std::endl;
}

void Character::TakeSpeDmg(Character& c, int dmg)
{
    int RealSpDmg =  (dmg - (0.5 * StatSpDef));
    Health = Health - RealSpDmg;
    std::cout << c.name << " inflicts " << RealSpDmg << " damages to " << name << " ! " << std::endl;
}

void Character::ReceiveHeal()
{
    Health += 15;

    if (Health > MaxHealth)
    {
        Health = MaxHealth;
    }
    
}

void Character::IsDead(Character* c)
{
    if (c->Health <= 0)
    {
        c->IsAlive = false;
    }
}