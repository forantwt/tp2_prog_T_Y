#pragma once
#include <string>

class Attaque
{
public:
    std::string nom;
    float multiplicateur;

    Attaque(std::string pNom, float pMultiplicateur)
    {
        nom = pNom;
        multiplicateur = pMultiplicateur;
    }
};