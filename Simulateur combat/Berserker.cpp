#include "Berserker.h"
using namespace std;

Berserker::Berserker(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive)
	: Character(n, h, atk, def, spatk,spdef, spd, alive) { }

void Berserker::Attack(Character& target)
{
	cout << "The berserker swings his sword ! ";
	target.TakeDmg(target, StatAtk);
}

void Berserker::Rage(Character& target)
{
	std::cout << " The berserker gets enraged ! " << std::endl;
	StatAtk += 10;
}


void Berserker::SpAttack(Character& target)
{
	std::cout << "It does nothing ! " << std::endl;
}