#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "FighterInterface.h"

class Cleric : public FighterInterface
{
public:
	//Constructor
	Cleric(std::string fighter, int hp, int str, int spd, int mgc);
	std::string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	int getDamage();

	void takeDamage(int damage);
	void reset();
	void regenerate();
	bool useAbility();
private:
	std::string name;
	char CLASS;
	int STR;
	int SPD;
	int MGC;
	int HP;
	int HPMax;
	int DMG;
	int Mana;
};
