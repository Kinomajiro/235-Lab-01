#include "Robot.h"

Robot::Robot(std::string fighter, int hp, int str, int spd, int mgc)
{
	name = fighter;
	CLASS = 'R';
	HP = hp;
	HPMax = hp;
	STR = str;
	DMG = str;
	SPD = spd;
	MGC = mgc;
	Energy = mgc*2;
	DMG_Bonus = 0;
}

std::string Robot::getName()
{
	return name;
}

int Robot::getMaximumHP()
{
	return HPMax;
}

int Robot::getCurrentHP()
{
	return HP;
}

int Robot::getStrength()
{
	return STR;
}

int Robot::getSpeed()
{
	return SPD;
}

int Robot::getMagic()
{
	return MGC;
}

int Robot::getDamage()
{
	int attack = DMG;

	if (DMG_Bonus > 0)
	{
		attack = DMG + DMG_Bonus;
		DMG_Bonus = 0;
	}
	return attack;
}

void Robot::takeDamage(int damage)
{
	damage = damage - (SPD/4);
	if (damage < 1)
	{
		damage = 1;
	}
	HP = HP - damage;
}

void Robot::reset()
{
	HP = HPMax;
	Energy = MGC*2;
	DMG_Bonus = 0;
}

void Robot::regenerate()
{
	HP = HP + (STR/6);
}

bool Robot::useAbility()
{
	if (Energy < ROBOT_ABILITY_COST)
	{
		return false;
	}
	else
	{
		DMG_Bonus = (STR  * ((Energy/(MGC*2))^4));
		Energy = Energy - ROBOT_ABILITY_COST;
		return true;
	}
}
