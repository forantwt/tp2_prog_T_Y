#pragma once
#include "Creature.h"

class CreatureFeu : public Creature
{
public:

    CreatureFeu(std::string nom, int pv, int attaque, int defense)
        : Creature(nom, pv, attaque, defense)
    {
        
        degatAttaque = (int)(degatAttaque * 1.1);
    }
};