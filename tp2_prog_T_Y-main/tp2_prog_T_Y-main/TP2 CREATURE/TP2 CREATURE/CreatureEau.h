#pragma once
#include <string>
#include "Creature.h"

class CreatureEau : public Creature
{
public:
    CreatureEau(std::string nom, int pv, int attaque, int defense)
        : Creature(nom, pv, attaque, defense)
    {
        degatAttaque = (int)(degatAttaque * 0.9);
        CreerAttaques();
    }

    void CreerAttaques() override
    {
        attaques.push_back(Attaque("Jet d'eau", 0.8));
        attaques.push_back(Attaque("Surf", 1.0));
        attaques.push_back(Attaque("Cascade", 1.2));
        attaques.push_back(Attaque("Tsunami", 1.5));
    }
};