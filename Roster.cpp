#pragma once
#include "Roster.h"

bool Roster::addFighter(std::string info)
{
	std::smatch m;
	std::regex data("([:w:])(A|C|R)(\\d+)(\\d+)(\\d+)(\\d+)");
	bool found = std::regex_search(info, m, data);

	if (found == true)
	{
		int i = 0;
		while((combatants[i]->getName() != m[0]) && (i < combatants.size()))
		{
			i++;
		}
		if(i == combatants.size())
		{
			std::string name = m[0];
			int HP = m[2];
			int STR = m[3];
			int SPD = m[4];
			int MGC = m[5];

			if (m[1] == 'A')
			{
				Archer* fighter_pointer = new Archer(name, HP, STR, SPD, MGC);
				combatants.push_back(fighter_pointer);
			}
			else if (m[1] == 'C')
			{
				Cleric* fighter_pointer = new Cleric(name, HP, STR, SPD, MGC);
				combatants.push_back(fighter_pointer);
			}
			else
			{
				Robot* fighter_pointer = new Robot(name, HP, STR, SPD, MGC);
				combatants.push_back(fighter_pointer);
			}
		}
		else
		{
			found = false;
		}
	}
	return found;
}

bool Roster::removeFighter(std::string name)
{
	bool found = false;

	for (int i = 0; i < combatants.size(); ++i)
	{
		if (combatants[i]->getName() == name)
		{
			FighterInterface* temp_pointer = combatants[combatants.size()-1];
			combatants[i] = combatants[combatants.size()-1];
			combatants[i] = temp_pointer;

			combatants.pop_back();

			found = true;

			i = combatants.size()-1;
		}
	}
	return found;
}

FighterInterface* Roster::getFighter(std::string name)
{
	for (int i=0; i < combatants.size(); ++i)
	{
		if (combatants[i]->getName() == name)
		{
			return combatants[i];
		}
	}
	return NULL;
}

int Roster::getSize()
{
	return combatants.size();
}
