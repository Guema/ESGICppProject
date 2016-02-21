#include <iostream>
#include <sstream>

#include "Base.h"
#include "Army.h"

using namespace std;

#define RETURN_MENU_CODE 100
#define QUIT_GAME_CODE 10

Base base;
Army army;

void NewGame();
void LoadGame();
void Play();

int main()
{	
	int choix = 0;		

	while (choix != QUIT_GAME_CODE)
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
			Play();
			break;
		case 2:	// Fonction de chargement de partie			
			LoadGame();
			break;
		case 3:	// Quitter le jeu
			choix = QUIT_GAME_CODE;
			break;
		default:
			system("cls");
			cout << "Je n'ai pas compris votre choix, veuillez choisir entre 1 et 3 ! \n" << endl;			
			break;
		}
	}	
	system("pause");
}

void NewGame()
{
	base = Base();
	army = Army();
}

void LoadGame()
{	
	string fichier;
	cout << "Entrer le nom du fichier a charger pour la base: ";
	cin >> fichier;
	base.LoadBase(fichier);
	cout << "Entrer le nom du fichier a charger pour l'armee: ";
	cin >> fichier;
	army.LoadArmy(fichier);
	Play();
}

void Play()
{
	int choix = 0;
	string name;
	string fichier;
	int x, y, id;

	while (choix != RETURN_MENU_CODE)
	{	
		cout << "Que Souhaitez vous faire : " << endl;
		cout << "1) Ajouter un batiment" << endl;
		cout << "2) Ameliorer un batiment" << endl;
		cout << "3) Detruire un batiment" << endl;
		cout << "4) Ajouter une unite" << endl;
		cout << "5) Ameliorer une unite" << endl;
		cout << "6) Detruire une unite" << endl;
		cout << "7) Afficher votre armee" << endl;
		cout << "8) Afficher la base" << endl;
		cout << "9) Sauvegarder une partie" << endl;
		cout << "10) Revenir au menu principal" << endl;

		cin >> choix;

		switch (choix)
		{
		case 1:	// Fonction d'ajouter de batiment
			cout << "Liste des noms des batiments existants : ";
			BuildingFactory::Get()->BuildingNameList();
			cout << "Saisir les parametres du batiment l'un apres l'autre : Name  CoteGauche  CoteHaute" << endl;			
			cin >> name >> x >> y;
			base.AddBuilding(name, x, y);
			break;
		case 2:	// Fonction d'ameliration de batiment
			cout << "Saisir l'ID du batiment a ameliorer: ";
			cin >> id;
			base.UpgradeBuilding(id);
			break;
		case 3:	// Fonction de suppression de batiment
			cout << "Saisir l'ID du batiment a enlever: ";
			cin >> id;
			base.RemoveBuilding(id);
			break;
		case 4:	// Fonction d'ajouter d'unite
			cout << "Liste des noms des unites existants : ";
			UnitFactory::Get()->UnitNameList();
			cout << "Saisir le nom de l'unite a ajouter : ";			
			cin >> name;
			army.AddUnit(name);
			break;
		case 5:	// Fonction d'ameliration d'unite
			cout << "Saisir l'ID de l'unite a ameliorer: ";
			cin >> id;
			army.UpgradeUnit(id);
			break;
		case 6:	// Fonction de suppression d'unite
			cout << "Saisir l'ID de l'unite a enlever: ";
			cin >> id;
			army.RemoveUnit(id);
			break;
		case 7:	// Fonction d'affichage d'armee
			army.DisplayArmy();
			break;
		case 8:	// Fonction d'affichage
			base.DisplayBase();
			break;
		case 9:	// Fonction de sauvegarde de partie
			cout << "Entrer le nom du fichier a sauvegarder pour la base: ";
			cin >> fichier;
			base.SaveBase(fichier);
			cout << "Entrer le nom du fichier a sauvegarder pour l'armee: ";
			cin >> fichier;
			army.SaveArmy(fichier);
			break;
		case 10:// Revenir au menu principal
			choix = RETURN_MENU_CODE;
			system("cls");
			break;
		default:
			system("cls");
			cout << "Je n'ai pas compris votre choix, veuillez choisir un chiffre entre 1 et 10 ! \n" << endl;
			break;
		}
	}
}