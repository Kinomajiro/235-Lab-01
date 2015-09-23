#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include "ArenaInterface.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"

class Roster : public ArenaInterface
{
public:

	Roster();

	//adders
	bool addFighter(std::string info);

	bool removeFighter(std::string name);

	//getters
	FighterInterface* getFighter(std::string name);
	int getSize();
private:
	vector<FighterInterface*> combatants;
};
