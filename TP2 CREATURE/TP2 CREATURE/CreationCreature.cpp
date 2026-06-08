#include <iostream>
#include <string>
#include <conio.h>
#include "Creature.h"
#include "CreatureFeu.h"
#include "CreatureEau.h"
#include "CreaturePlante.h"
#include "CreatureElectrique.h"

using namespace std;

Creature* CreationCreature()
{
    //declaration de variables
    int PointAptitude = 100;
    char input = 0;
    bool confirmation = false;
    int PointAptitudeDepenser = 0;
    string inputNom = " ";

    //Nom
    cout << "Veuillez creer votre premiere creature, " << endl
        << "Veuillez choisir le nom de votre creaure: ";

    cin >> inputNom;
    system("cls");

    // PV 

    cout << "Nom: " << inputNom << endl
        << "Point d'aptitude restant: " << PointAptitude << endl;

    while (confirmation == false)
    {
        cout << "1 point = 5 pv || Minimum -> 1 | Maximum -> 98" << endl
            << "Veuillez inserer le nombre de point que vous souhaitez depenser sur vos pv: ";
        cin >> PointAptitudeDepenser;

        if (1 > PointAptitudeDepenser || PointAptitudeDepenser > 98)
        {
            cout << "Choix Invalide." << endl;
        }
        else
        {
            cout << "Etes-vous sur de vouloir depenser " << PointAptitudeDepenser << " point d'aptitude sur vos points de vie?" << endl
                << "Votre Creature aura " << PointAptitudeDepenser * 5 << " pv." << endl
                << "[1] - Oui" << endl
                << "[0] - Non" << endl;

            input = _getch();

            if (input == '1')
            {
                confirmation = true;
            }
        }
    }

    int pointVie = PointAptitudeDepenser * 5;
    PointAptitude -= PointAptitudeDepenser;

    system("cls");

    // Attaque
    cout << "Nom: " << inputNom << endl
        << "PV: " << pointVie << endl
        << "Point d'aptitude restant: " << PointAptitude << endl;

    confirmation = false;

    while (confirmation == false)
    {
        cout << "1 point = +1 Att || Minimum -> 1 | Maximum -> " << PointAptitude - 1 << endl
            << "Veuillez inserer le nombre de point que vous souhaitez depenser en attaque: ";
        cin >> PointAptitudeDepenser;

        if (1 > PointAptitudeDepenser || PointAptitudeDepenser > PointAptitude - 1)
        {
            cout << "Choix Invalide." << endl;
        }
        else
        {
            cout << "Etes-vous sur de vouloir depenser " << PointAptitudeDepenser << " point d'aptitude en attaque?" << endl
                << "Votre Creature aura " << PointAptitudeDepenser << " de degats d'attaque." << endl
                << "[1] - Oui" << endl
                << "[0] - Non" << endl;

            input = _getch();

            if (input == '1')
            {
                confirmation = true;
            }
        }
    }

    int attaque = PointAptitudeDepenser;
    PointAptitude -= PointAptitudeDepenser;

    system("cls");

    //Defense

    cout << "Nom: " << inputNom << endl
        << "PV: " << pointVie << endl
        << "Att: " << attaque << endl << endl
        << "Point d'aptitude restant: " << PointAptitude << endl
        << "1 point = +1 DEF " << endl
        << "Vos " << PointAptitude << " points restants iront a votre defense." << endl << endl
        << "Veuillez appuyer quelque part pour continuer...";
    _getch();

    int def = PointAptitude;

    system("cls");


    // TYPE

    while (true)
    {
        cout << "Nom: " << inputNom << endl
            << "PV: " << pointVie << endl
            << "Att: " << attaque << endl
            << "Def: " << def << endl << endl;

        cout << "Veuillez choisir un type: " << endl << endl
            << "[1] = Feu" << endl
            << "[2] = Eau" << endl
            << "[3] = Plante" << endl
            << "[4] = Electrique" << endl;

        char ChoixDeType = _getch();

        system("cls");

        switch (ChoixDeType)
        {
        case '1':
        {
            return new CreatureFeu(inputNom, pointVie, attaque, def);
        }
        case '2':
        {
            return new CreatureEau(inputNom, pointVie, attaque, def);
        }
        case '3':
        {
            return new CreaturePlante(inputNom, pointVie, attaque, def);
        }
        case '4':
        {
            return new CreatureElectrique(inputNom, pointVie, attaque, def);
        }
        default:
        {
            cout << "Choix Invalide." << endl;
            _getch();
            system("cls");
        }
        }
    }
}
