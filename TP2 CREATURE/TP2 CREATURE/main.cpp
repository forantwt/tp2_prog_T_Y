#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "Creature.h"

using namespace std;

vector<Creature> creatures;

//declarations de fonctions
Creature  CreationCreature();


int main()
{

    bool FermerProgramme = false;

    while (FermerProgramme == false)
    {
        cout << "Bonjour, que souhaitez vous faire?" << endl
            << "[1] - Creer une creature" << endl
            << "[2] - Voir vos creations" << endl
            << "[3] - Fermer le programme" << endl;

        int choix = 0;
        cin >> choix;

        if (choix == 1)
        {
            //mets nouvelle creature dans la boite (creatures)
            Creature nouvelleCreature = CreationCreature();
            creatures.push_back(nouvelleCreature);

            cout << "Creature cree avec succes!" << endl;
        }
        else if (choix == 2)
        {
            if (creatures.empty())
            {
                cout << "Vous n'avez aucune creature." << endl << endl;        
            }
            else
            {
                cout << "Vos Creatures" << endl << endl << endl;

                for (int i = 0; i < creatures.size(); i++)
                {
                    
                    string TypeDeLaCreature;
                    switch (creatures[i].type)
                    {
                        case TypeCreature::Feu:
                        {
                            TypeDeLaCreature = "Feu";
                            break;
                        }
                        case TypeCreature::Eau:
                        {
                            TypeDeLaCreature = "Eau";
                            break;
                        }
                        case TypeCreature::Plante:
                        {
                            TypeDeLaCreature = "Plante";
                            break;
                        }
                        
                        case TypeCreature::Electrique:
                        {
                            TypeDeLaCreature = "Electrique";
                            break;
                        }
                    }

                    cout <<  "Creature: " << creatures[i].nom << endl
                        << "PV: " << creatures[i].pointVie << endl
                        << "Att: " << creatures[i].degatAttaque << endl
                        << "Type: " << TypeDeLaCreature << endl
                        << "Def: " << creatures[i].valeurDefense << endl << endl;
                }
            }
        }
        else if (choix == 3)
        {
            cout << "Fermeture du programme.";
            FermerProgramme = true;
        }
        else
        {
            cout << "Choix Invalide" << endl << endl;
        }
    }
	return 0;
}

Creature CreationCreature()
{
    int PointAptitude = 100;
    char input = 0;

	//prompt pr le nom de la creature
	cout << "Veuillez creer votre premiere creature, " << endl << endl << "Veuillez choisir le nom de votre creaure: ";
	string inputNom = " ";
	cin >> inputNom;
	system("cls");


    //prompt pr le type de la creature
    bool confirmation = false;
    TypeCreature ChoixDeType;

    while (confirmation == false)
    {
        cout << "Nom: " << inputNom << endl
            << "Veuillez choisir le type de " << inputNom << ": " << endl << endl
            << "[1] = Feu" << endl
            << "[2] = Eau" << endl
            << "[3] = Plante" << endl
            << "[4] = Electrique" << endl;

        char inputType = _getch();

        switch (inputType)
        {
            case '1':
            {
                ChoixDeType = TypeCreature::Feu;
                confirmation = true;
                break;
            }
            case '2':
            {
                ChoixDeType = TypeCreature::Eau;
                confirmation = true;
                break;
            }
            case '3':
            {
                ChoixDeType = TypeCreature::Plante;
                confirmation = true;
                break;
            }
            case '4':
            {
                ChoixDeType = TypeCreature::Electrique;
                confirmation = true;
                break;
            }
            default:
            {
                system("cls");
                cout << "Choix invalide!" << endl;
            }

        }
    }
    system("cls");

    string TypeDeLaCreature;

    switch (ChoixDeType)
    {
        case TypeCreature::Feu:
        {
            TypeDeLaCreature = "Feu";
            break;
        }
        case TypeCreature::Eau:
        {
            TypeDeLaCreature = "Eau";
            break;
        }
        case TypeCreature::Plante:
        {
            TypeDeLaCreature = "Plante";
            break;
        }
        case TypeCreature::Electrique:
        {
            TypeDeLaCreature = "Electrique";
            break;
        }
    
    }

	//prompt pr les pv
    cout << "Nom: " << inputNom << endl
        << "Type: " << TypeDeLaCreature << endl << endl
        << "Point d'aptitude restant: " << PointAptitude << endl;
       
        int PointAptitudeDepenser = 0;
        confirmation = false;
      

        while (confirmation == false)
        {
            cout << "1 point = 5 pv || Minimum -> 1 | Maximum -> 98" << endl
                << "Veuillez inserer le nombre de point que vous souhaitez depenser sur vos pv: ";
            cin >> PointAptitudeDepenser;

            //si le nombre de point depenser ne respecte pas les criteres
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

        //prompt pour les degats

        cout << "Nom: " << inputNom << endl
            << "Type: " << TypeDeLaCreature << endl
            << "PV: " << pointVie << endl << endl 
            << "Point d'aptitude restant: " << PointAptitude << endl;
        
        confirmation = false;

        while (confirmation == false)
        {
          

            cout << "1 point = +1 Att || Minimum -> 1 | Maximum -> " << PointAptitude - 1 << endl
                << "Veuillez inserer le nombre de point que vous souhaitez depenser en attaque: ";
            cin >> PointAptitudeDepenser;

            //si le nombre de point depenser ne respecte pas les criteres
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

        //prompt pour la defense

        cout << "Nom: " << inputNom << endl
            << "Type: " << TypeDeLaCreature << endl
            << "PV: " << pointVie << endl 
            << "Att: " << attaque << endl << endl
            << "Point d'aptitude restant: " << PointAptitude << endl;

        cout << "1 point = +1 DEF " << endl
            << "Vos " << PointAptitude << " points restants iront a votre defense." << endl << endl
            << "Veuillez appuyer quelque part pour continuer...";
        _getch();
           
        int def = PointAptitudeDepenser;

        system("cls");
        
        return Creature(inputNom, ChoixDeType, pointVie, attaque, def);
}
