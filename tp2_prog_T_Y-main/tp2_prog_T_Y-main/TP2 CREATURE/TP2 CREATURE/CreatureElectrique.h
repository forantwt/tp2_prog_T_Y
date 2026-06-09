#pragma once
#include <cstdlib>
#include "Creature.h"

class CreatureElectrique : public Creature
{
public:

    CreatureElectrique(std::string nom, int pv, int attaque, int defense)
        : Creature(nom, pv, attaque, defense)
    {
        CreerAttaques();
    }

    int ModifierAttaque(int attaque) override
    {
        int chance = rand() % 100;

        if (chance < 20)
        {
            return attaque * 2;
        }

        return attaque;
    }

    void CreerAttaques() override
    {
        attaques.push_back(Attaque("Étincelle", 0.8));
        attaques.push_back(Attaque("Éclair", 1.0));
        attaques.push_back(Attaque("Tonnerre", 1.2));
        attaques.push_back(Attaque("Foudre divine", 1.5));
    }
};