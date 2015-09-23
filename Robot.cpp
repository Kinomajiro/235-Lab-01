#pragma once
#include "Robot.h"

Robot::Robot(std::string fighter)
{
	smatch m;
	regex info("([:w:])\s(A|C|R)\s(\d+)\s(\d+)\s(\d+)\s(\d+)");

	bool found = regex_search(fighter, m, info);

	name = m[0];
	CLASS = m[1];
	HP = m[2];
	HPMax = m[2];
	STR = m[3];
	DMG = m[3];
	SPD = m[4];
	MGC = m[5];
	Energy = m[5]*2;
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
			DMG_Bonus = (STR  * ((Energy/(MGC*2))^4))
			Energy = Energy - ROBOT_ABILITY_COST;
			return true;
		}
	}
}
