#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include "FighterInterface.h"

class Archer : public FighterInterface
{
public:
	//Constructor
	Archer(string fighter);
	~Archer();
	string getName();
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
	string name;
	char CLASS;
	int STR;
	int SPD;
	int baseSPD;
	int MGC;
	int HP;
	int HPMax;
	int DMG;
};
