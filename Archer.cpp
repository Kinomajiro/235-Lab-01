#pragma once
#include "Archer.h"

Archer::Archer(std::string fighter)
{
	std::smatch m;
	std::regex info ("([:w:])(A|C|R)(\\d+)(\\d+)(\\d+)(\\d+)");
	std::regex_search(fighter, m, info);

	name = m[0];
	CLASS = m[1];
	HP = m[2];
	HPMax = m[2];
	STR = m[3];
	SPD = m[4];
	baseSPD = m[4];
	DMG = m[4];
	MGC = m[5];
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
