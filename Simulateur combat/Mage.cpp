#include "Mage.h"
using namespace std;

Mage::Mage(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive)
	: Character(n, h, atk, def, spatk, spdef, spd, alive) {
}

void Mage::Attack(Character& target)
{
	std::cout << "The mage strikes with his staff! ";
	target.TakeDmg(target, StatAtk);
}
void Mage::SpAttack(Character& target)
{
	cout << "The mage fires his fireballs ! ";
	target.TakeSpeDmg(target, StatSpAtk);
}

void Mage::Heal()
{
	cout << "The mage heals himself ! ";
	ReceiveHeal();
}