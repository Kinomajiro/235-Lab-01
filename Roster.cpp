#pragma once
#include "Roster.h"

bool Roster::addFighter(std::string info)
{
	smatch m;
	regex data("([:w:])\s(A|C|R)\s(\d+)\s(\d+)\s(\d+)\s(\d+)");

	bool found = regex_search(info, m, data);
	if (found == true)
	{
		int i = 0;
		while((combatants[i]->getName() != m[0]) && (i < combatants.size()))
		{
			i++;
		}
		if(i == combatants.size())
		{
			if (m[1] == 'A')
			{
				Archer* fighter_pointer = new Archer(info);
				combatants.push_back(fighter_pointer);
			}
			else if (m[1] == 'C')
			{
				Cleric* fighter_pointer = new Cleric(info);
				combatants.push_back(fighter_pointer);
			}
			else
			{
				Robot* fighter_pointer = new Robot(info);
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
