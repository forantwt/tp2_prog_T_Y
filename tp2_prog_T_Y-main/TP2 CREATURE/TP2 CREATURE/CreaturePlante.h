#pragma once
#include "Creature.h"

class CreaturePlante : public Creature
{
public:

    CreaturePlante(std::string nom, int pv, int attaque, int defense)
        : Creature(nom, pv, attaque, defense)
    {
    }

    void FinDeTour() override
    {
        pointVie += (int)(pointVie * 0.05);
    }
};