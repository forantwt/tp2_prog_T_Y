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
		//nom
		nom = nomCreature; 
		
		//pv
		pointVie = pointDeVie;

		//attaque
		degatAttaque = DegatsAttaque;
		
		//defense
		valeurDefense = ValeurDefense;
    }

	//destructeurs
	virtual ~Creature()
	{

	}
};

