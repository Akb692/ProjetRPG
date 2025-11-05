#include "Hybrid.h"
using namespace std;

Hybrid::Hybrid(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive)
	: Character(n, h, atk, def, spatk, spdef, spd, alive) {
}

void Hybrid::Attack(Character& target)
{
	cout << "The hybrid swings his arm ! ";
	target.TakeDmg(target, StatAtk);
}
void Hybrid::SpAttack(Character& target)
{
	cout << "The hybrid summons mysterious entities ! ";
	target.TakeSpeDmg(target, StatSpAtk);
}
