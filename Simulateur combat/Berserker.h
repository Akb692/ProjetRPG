#pragma once
#include "Character.h"

class Berserker : public Character
{
public:
    Berserker(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive, int gold,int potion);
    void Attack(Character& target) override;
    void Rage(Character& target);
    void SpAttack(Character& target) override;
};
