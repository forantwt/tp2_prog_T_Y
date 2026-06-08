#pragma once
#include <cstdlib>
#include "Creature.h"

class CreatureElectrique : public Creature
{
public:

    CreatureElectrique(std::string nom, int pv, int attaque, int defense)
        : Creature(nom, pv, attaque, defense)
    {}

    int ModifierAttaque(int attaque) override
    {
        int chance = rand() % 100;

        if (chance < 20)
        {
            return attaque * 2;
        }

        return attaque;
    }
};