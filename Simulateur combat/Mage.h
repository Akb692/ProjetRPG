#pragma once
#include "Character.h"


class Mage : public Character
{
public:
	
	
	Mage(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive);
	void SpAttack(Character& target) override;
	void Heal();
	void Attack(Character& target) override;
};

