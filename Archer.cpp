#include "Archer.h"

Archer::Archer(std::string fighter, int hp, int str, int spd, int mgc)
{
	name = fighter;
	CLASS = 'A';
	HP = hp;
	HPMax = hp;
	STR = str;
	SPD = spd;
	baseSPD = spd;
	DMG = spd;
	MGC = mgc;
}

Archer::~Archer(){}
std::string Archer::getName()
{
	return name;
}

int Archer::getMaximumHP()
{
	return HPMax;
}

int Archer::getCurrentHP()
{
	return HP;
}

int Archer::getStrength()
{
	return STR;
}

int Archer::getSpeed()
{
	return SPD;
}

int Archer::getMagic()
{
	return MGC;
}

int Archer::getDamage()
{
	return DMG;
}

void Archer::takeDamage(int damage)
{
	damage = damage - (SPD/4);
	if (damage < 1)
	{
		damage = 1;
	}
	HP = HP - damage;
}

void Archer::reset()
{
	HP = HPMax;
	SPD = baseSPD;
	DMG = baseSPD;
}

void Archer::regenerate()
{
	HP = HP + (STR/6);
}

bool Archer::useAbility()
{
	++SPD;
	DMG = SPD;
	return true;
}
