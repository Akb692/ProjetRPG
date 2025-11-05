#pragma once
#include <iostream>
#include <vector>

class Character
{
private:
	std::string name;
	int Health;
	int MaxHealth;
public:
	int StatAtk;
	int StatDef;
	int StatSpAtk;
	int StatSpDef;
	int StatSpeed;
	bool IsAlive;

	Character(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive);

	void DisplayStat() const;
	void TakeDmg(Character& c, int dmg);
	void TakeSpeDmg(Character& c, int dmg);
	virtual void Attack(Character& target) = 0;
	virtual void SpAttack(Character& target) = 0;
	void ReceiveHeal();
	int DisplayHealth();
	void IsDead(Character* c);
};

