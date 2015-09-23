#pragma once
#include "Cleric.h"

Cleric::Cleric(std::string fighter)
{
	std::smatch m;
	std::regex info("([:w:])\s(A|C|R)\s(\d+)\s(\d+)\s(\d+)\s(\d+)");

	bool found = std::regex_search (fighter,m,info);

	name = m[0];
	CLASS = m[1];
	HP = m[2];
	HPMax = m[2];
	STR = m[3];
	SPD = m[4];
	MGC = m[5];
	DMG = m[5];
	Mana = m[5] * 5;
}

std::string Cleric::getName()
{
	return name;
}

int Cleric::getMaximumHP()
{
	return HPMax;
}

int Cleric::getCurrentHP()
{
	return HP;
}

int Cleric::getStrength()
{
	return STR;
}

int Cleric::getSpeed()
{
	return SPD;
}

int Cleric::getMagic()
{
	return MGC;
}

int Cleric::getDamage()
{
	return DMG;
}

void Cleric::takeDamage(int damage)
{
	damage = damage - (SPD/4);
	if (damage < 1)
	{
		damage = 1;
	}
	HP = HP - damage;
}

void Cleric::reset()
{
	HP = HPMax;
	Mana = MGC * 5;
}

void Cleric::regenerate()
{
	HP = HP + (STR/6);
	Mana = Mana + (MGC/5);
	if ((MGC/5) < 1)
	{
		++Mana;
	}

	if (Mana > (MGC*5))
	{
		Mana = MGC*5;
	}
}

bool Cleric::useAbility()
{
	if (Mana < CLERIC_ABILITY_COST)
	{
		return false;
	}
	else
	{
		int HEAL = MGC/3;
		if (HEAL < 1)
		{
			HEAL = 1;
		}
		Mana = Mana - CLERIC_ABILITY_COST;
		HP = HP + HEAL;
		if (HP > HPMax)
		{
			HP = HPMax;
		}
		return true;
	}
}
