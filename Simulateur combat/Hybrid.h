#pragma once
#include "Character.h"

class Hybrid : public Character
{
public:
    Hybrid(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive, int gold,int potion, int bosskey, bool isBossAlive);
    void Attack(Character& target) override;
    void SpAttack(Character& target) override;
};
