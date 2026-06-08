#pragma once
#include <string>
#include "Creature.h"

class CreatureEau : public Creature
{
public:
    CreatureEau(std::string nom, int pv, int attaque, int defense)
        : Creature(nom, pv, attaque, defense)
    {
        degatAttaque += (int)(degatAttaque * 0.9);
    }
};