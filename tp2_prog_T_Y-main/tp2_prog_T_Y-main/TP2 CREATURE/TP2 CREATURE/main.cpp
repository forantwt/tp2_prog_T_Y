#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <vector>

#include "Creature.h"
#include "CreatureFeu.h"
#include "CreatureEau.h"
#include "CreaturePlante.h"
#include "CreatureElectrique.h"
#include "CreationCreature.h"

using namespace std;

// collection polymorphique
vector<Creature*> creatures;


int main()
{
    bool FermerProgramme = false;

    while (FermerProgramme == false)
    {
        cout << "Bonjour, que souhaitez vous faire?" << endl
            << "[1] - Creer une creature" << endl
            << "[2] - Voir vos creations" << endl
			<< "[3] - Modifier la premiere creature" << endl
			<< "[4] - Supprimer toutes les creatures" << endl
            << "[5] - Fermer le programme" << endl;

        int choix = 0;
        cin >> choix;

        if (choix == 1)
        {
            Creature* nouvelleCreature = CreationCreature();
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
                cout << endl << endl << endl << endl << "                Vos Creatures:" << endl << endl << endl;

                for (int i = 0; i < creatures.size(); i++)
                {
                    cout << "Creature: " << creatures[i]->nom << endl
                        << "PV: " << creatures[i]->pointVie << endl
                        << "Att: " << creatures[i]->degatAttaque << endl
                        << "Def: " << creatures[i]->valeurDefense << endl;

                    if (dynamic_cast<CreatureFeu*>(creatures[i]))
                    {
                        cout << "Type: Feu" << endl << endl;
                    }
                    else if (dynamic_cast<CreatureEau*>(creatures[i]))
                    {
                        cout << "Type: Eau" << endl << endl;
                    }
                    else if (dynamic_cast<CreaturePlante*>(creatures[i]))
                    {
                        cout << "Type: Plante" << endl << endl;
                    }
                    else
                    {
                        cout << "Type: Electrique" << endl << endl;
                    }
                }
                cout << "Veuillez appuyer quelque part pour continuer...";
                _getch();
                system("cls");
            }
        }
        else if (choix == 3)
        {
            cout << "Modification de la premiere creature." << endl;
            if (!creatures.empty())
            {
				string newName;
				cout << "Entrez le nouveau nom de la creature: ";
				cin >> newName;

                int newPV;
				cout << "Entrez les nouveaux points de vie de la creature: ";
				cin >> newPV;

				int newAttaque;
				cout << "Entrez les nouveaux points d'attaque de la creature: ";
				cin >> newAttaque;

				int newDef;
				cout << "Entrez les nouveaux points de defense de la creature: ";
				cin >> newDef;
                

                creatures[0]->updateCreatureStats(newName, newPV, newAttaque, newDef);
                cout << "Creature modifiee avec succes!" << endl;

                cout << "\n=== Nouveau stats de la creature ===" << endl;
                cout << "Nom : " << newName << endl;
                cout << "PV : " << newPV << endl;
                cout << "Attaque : " << newAttaque << endl;
                cout << "Defense : " << newDef << endl;
            }
            else
            {
                cout << "Aucune creature a modifier." << endl;
            }
        }
        else if (choix == 4)
        {
            cout << "Suppression de toutes les creatures." << endl;
            for (Creature* c : creatures)
            {
                delete c;
            }
            creatures.clear();
        }
        else if (choix == 5)
        {
            cout << "Fermeture du programme." << endl;
            FermerProgramme = true;
        }
        else
        {
            cout << "Choix Invalide" << endl << endl;
        }
    }

    for (Creature* c : creatures)
    {
        delete c;
    }

    return 0;
}