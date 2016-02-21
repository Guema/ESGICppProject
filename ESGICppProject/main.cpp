#include <iostream>
#include <sstream>

#include "Building.h"
#include "BuildingFactory.h"
#include "Zone.h"
#include "Field.h"
#include "Base.h"

using namespace std;

Base base;

string fichier = "Test.txt";
void Play();
void LoadGame();

int main()
{	
	int choix = 0;		

	/*Menu principal*/
	while (choix != 3)
	{
		cout << "Bienvenue dans HQ Attack. Que souhaitez vous faire : " << endl;
		cout << "1) Creer une nouvelle partie" << endl;
		cout << "2) Charger une partie" << endl;
		cout << "3) Quitter le jeu" << endl;
		cout << "Entrez votre choix en tapant 1 ou 2 ou 3" << endl;
		cin >> choix;
		switch (choix)
		{
		case 1:	// Fonction de creer une nouvelle partie
			base = Base();
			Play();
			break;
		case 2:	// Fonction de chargement de partie			
			LoadGame();
			break;
		case 3:	// Quitter le jeu			
			break;
		default:
			cout << "Je n'ai pas compris votre choix, veuillez choisir entre 1 et 3" << endl;			
			break;
		}
	}	
	system("pause");
}

/*Chargement du fichier de sauvegarde*/
void LoadGame()
{	
	cout << "Entrer le nom du fichier a charger: ";
	cin >> fichier;
	base.LoadBase(fichier);
	Play();
}

/*Lancement du jeu*/
void Play()
{
	int choix = 0;
	string name;
	int x, y, id;	
	vector<string> bdl;

	/*Menu d'accueil du jeu*/
	while (choix != 8)
	{	
		cout << "Que Souhaitez vous faire : " << endl;
		cout << "1) Construire un batiment" << endl;
		cout << "2) Detruire un batiment" << endl;
		cout << "3) Ameliorer un batiment" << endl;
		cout << "4) Creer une unite" << endl;
		cout << "5) Voir votre armee" << endl;
		cout << "6) Afficher la base" << endl;
		cout << "7) Sauvegarder une partie" << endl;
		cout << "8) Revenir au menu principal" << endl;

		cin >> choix;

		switch (choix)
		{
		case 1:	// Fonction de création de bâtiment
			cout << "Saisir les parametres du batiment l'un apres l'autre : Name  CoteGauche  CoteHaute" << endl;
			cout << "Liste des noms des batiments existants:" << endl;
			BuildingFactory::Get()->buildingList();			
			cin >> name >> x >> y;
			base.AddBuilding(name, x, y);
			break;
		case 2:	// Fonction de suppression de batiment
			cout << "Saisir l'ID du batiment a enlever: ";
			cin >> id;
			base.RemoveBuilding(id);
			break;
		case 3:	// Fonction d'ameliration de batiment
			cout << "Saisir l'ID du batiment a ameliorer: ";
			cin >> id;
			base.UpgradeBuilding(id);
			break;
		case 4:	// Fonction de creation d'unite
			break;
		case 5:	// Fonction d'affichage d'armee
			break;
		case 6:	// Fonction d'affichage
			base.DisplayBase();
			break;
		case 7:	// Fonction de sauvegarde de partie
			cout << "Entrer le nom du fichier a sauvegarder: ";
			cin >> fichier;
			base.SaveBase(fichier);
			break;
		case 8:	// Revenir au menu principal
			break;
		default:
			cout << "Je n'ai pas compris votre choix, veuillez choisir un chiffre entre 1 et 8" << endl;
			break;
		}
	}
}