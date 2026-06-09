#pragma once
#include "Creature.h"

class CreaturePlante : public Creature
{
public:

    CreaturePlante(std::string nom, int pv, int attaque, int defense)
        : Creature(nom, pv, attaque, defense)
    {
        CreerAttaques();
    }

    void FinDeTour() override
    {
        pointVie += (int)(pointVie * 0.05);
    }
    void CreerAttaques() override
    {
        attaques.push_back(Attaque("Lance-herbes", 0.8));
        attaques.push_back(Attaque("Fouet", 1.0));
        attaques.push_back(Attaque("Vege-attaque", 1.2));
        attaques.push_back(Attaque("Tranche Herbe", 1.5));
    }
};