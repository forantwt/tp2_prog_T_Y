#pragma once 
#include <string>
#include "Creature.h"
class CreatureFeu : public Creature
{
public:
	CreatureFeu(std::string nom, int pv, int attaque, int defense)
	{
		degatAttaque = degatAttaque * 1.1;
	}
};
