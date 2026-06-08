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
            << "[3] - Fermer le programme" << endl;

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
                cout << "Vos Creatures" << endl << endl << endl;

                for (int i = 0; i < creatures.size(); i++)
                {
                    cout << "Creature: " << creatures[i]->nom << endl
                        << "PV: " << creatures[i]->pointVie << endl
                        << "Att: " << creatures[i]->degatAttaque << endl;

                    // 🔥 AFFICHAGE TYPE (via dynamic_cast)
                    if (dynamic_cast<CreatureFeu*>(creatures[i]))
                        cout << "Type: Feu" << endl;

                    else if (dynamic_cast<CreatureEau*>(creatures[i]))
                        cout << "Type: Eau" << endl;

                    else if (dynamic_cast<CreaturePlante*>(creatures[i]))
                        cout << "Type: Plante" << endl;

                    else if (dynamic_cast<CreatureElectrique*>(creatures[i]))
                        cout << "Type: Electrique" << endl;

                    else
                        cout << "Type: Inconnu" << endl;

                    cout << "Def: " << creatures[i]->valeurDefense << endl << endl;
                }
            }
        }

        else if (choix == 3)
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