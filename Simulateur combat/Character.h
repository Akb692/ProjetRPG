#pragma once
#include <iostream>

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
    int Gold;
    int Potion;
    int FinalBossKey;
    bool isBossAlive;
    bool IsAlive;
    

    Character(const std::string& n, int h, int atk, int def, int spatk, int spdef, int spd, bool alive, int gold, int potion, int bosskey, bool isBossAlive);
    
    std::string GetName() const { return name; }
    void DisplayStat() const;
    void TakeDmg(Character& c, int dmg);
    void TakeSpeDmg(Character& c, int dmg);
    virtual void Attack(Character& target) = 0;
    virtual void SpAttack(Character& target) = 0;
    void ReceiveHeal();
    int DisplayHealth();
    void DisplayName() const;
    void IsDead(Character* c);
};
