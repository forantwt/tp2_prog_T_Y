#pragma once
#include "Creature.h"

class CreatureFeu : public Creature
{
public:

    CreatureFeu(std::string nom, int pv, int attaque, int defense)
        : Creature(nom, pv, attaque, defense)
    {
        degatAttaque = (int)(degatAttaque * 1.1);
        CreerAttaques();
    }

    void CreerAttaques() override
    {
        attaques.push_back(Attaque("Etincelle", 0.8));
        attaques.push_back(Attaque("Inferno", 1.0));
        attaques.push_back(Attaque("Lance-flammes", 1.2));
        attaques.push_back(Attaque("Tornade de feu", 1.5));
    }
};