#pragma once
#include <string>

class Creature
{
public:
	std::string nom = "";
	int pointVie = 0;
	int degatAttaque = 0;
	int valeurDefense = 0;

	//constructeur
	Creature(std::string nomCreature, int pointDeVie, int DegatsAttaque, int ValeurDefense)
	{
		nom = nomCreature;
		pointVie = pointDeVie;
		degatAttaque = DegatsAttaque;
		valeurDefense = ValeurDefense;
	}
	///destructeurs
	virtual ~Creature()
	{}

	//Plante
	virtual void FinDeTour()
	{}

	//Electrique
	virtual int ModifierAttaque(int attaque)
	{
		return attaque;
	}
	void updateCreatureStats(const std::string& newInputNom, int newPointVie, int newAttaque, int newDef)
	{
		nom = newInputNom;
		pointVie = newPointVie;
		degatAttaque = newAttaque;
		valeurDefense = newDef;
	}
};


