#pragma once
#include "Character.h"

class Mage : public Character
{
public:
    Mage(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive, int gold,int potion, int bosskey, bool isBossAlive);
    void SpAttack(Character& target) override;
    void Attack(Character& target) override;
};
