#pragma once
#include <string>
#include <cmath>
#include <vector>
#include "Attaque.h"



class Creature
{
public:
	std::vector<Attaque> attaques;
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

	int CalculDegats(int indiceAttaque, Creature* cible)
	{
		if (indiceAttaque < 0 || indiceAttaque >= attaques.size())
		{
			return 0;
		}

		float statAttaque = degatAttaque;
		float multiplicateurDegats = attaques[indiceAttaque].multiplicateur;
		float statDefenseEnnemi = cible->valeurDefense;


		float dommages = statAttaque * multiplicateurDegats * (100.0f / (100.0f + statDefenseEnnemi));

		return round(dommages);
	}

	virtual void CreerAttaques() = 0;
};


