#include "Army.h"

// Constructeur par défaut
Army::Army()
{
	gold = DEFAULT_ARMY_GOLD;
	idCount = 1;
}

/* 
Constructeur de la base via un montant d'or
@param int gold : le montant d'or à passer 
*/
Army::Army(int gold)
{	
	this->gold = gold;
	idCount = 1;
	unitList.clear();
}

/*
Constructeur par copie
@param Base & ar : l'armée à copier
*/
Army::Army(Army & ar)
{	
	gold = ar.gold;
	unitList = ar.unitList;
}

/*
Ajout d'une unité dans la liste d'armée
@string name : Le nom de l'unité
@return bool : true si l'unité a bien été ajouté, false sinon
*/
bool Army::AddUnit(string name)
{
	Unit *pUnit = UnitFactory::Get()->build(name);

	//véifie que l'unité existe bien dans la liste des unités définies
	if (pUnit)
	{
		unitList[idCount] = pUnit;
		idCount++;
		gold -= pUnit->getCost();
		cout << "ADD Unit ok" << endl;
		return true;
	}
	else
		cout << "ERREUR: le nom choisi n'est pas un nom d'unite valide!" << endl;
	return false;
}

/*
Améliorer une unité via son ID dans la liste
@int id : Identifiant de l'unité
@return bool : true si l'unité a bien été améliorée, false si celui-ci n'existe pas dans la liste
*/
bool Army::UpgradeUnit(int id)
{
	ArmyMap::iterator it;
	it = unitList.find(id);
	if (it != unitList.end())
	{
		gold -= it->second->nextUpdateCost();
		it->second->levelUp();
		cout << "Upgrade UNIT ok" << endl;
		return true;
	}
	cout << "ERREUR: l'ID choisie n'existe pas - peut pas ameliorer UNIT!" << endl;
	return false;
}

/*
Supprimer une unité via son ID dans la liste
@int id : Identifiant de l'unité
@return bool : true si l'unité a bien été supprimée, false si celui-ci n'existe pas dans la liste
*/
bool Army::RemoveUnit(int id)
{
	ArmyMap::iterator it;
	it = unitList.find(id);
	if (it != unitList.end())
	{		
		unitList.erase(it);
		cout << "Remove UNIT ok" << endl;
		return true;
	}
	cout << "ERREUR: l'ID choisie n'existe pas - peut pas enlever UNIT!" << endl;
	return false;	
}

// Affichage de l'armée
void Army::DisplayArmy()
{
	cout << "MONTANT D'OR RESTANT DE L'ARMEE : " << gold << endl;
	cout << "Les unites existants dans l'armee : " << endl;
	for (ArmyMap::iterator it = unitList.begin(); it != unitList.end(); it++)
	{
		cout << *it->second;
	}
	cout << endl;
}

/*
Sauvegarde de l'armée dans un fichier
@string myFile : le nom du fichier de sauvegarde
*/
void Army::SaveArmy(string myFile)
{
	ofstream myfile;
	myfile.open(myFile);
	
	if (myfile.is_open())
	{		
		myfile << unitList.size() << endl;
		for (ArmyMap::iterator it = unitList.begin(); it != unitList.end(); it++)
		{
			myfile << (*it->second).getName() << " " << (*it->second).getLevel() << endl;
		}		
		cout << "SAVE UNIT ok" << endl;
	}
	else
		cout << "ERREUR: Impossible d'ouvrir le fichier pour sauvegarder UNIT!" << endl;
	myfile.close();
}

/*
Chargement de l'armée via un fichier de sauvegarde
@string myFile : le nom du fichier de sauvegarde à charger
*/
void Army::LoadArmy(string myFile)
{
	ifstream myfile;
	int size;

	myfile.open(myFile);
	if (myfile.is_open())
	{		
		idCount = 1;
		unitList.clear();

		myfile >> size;
		for (int i = 0; i < size; i++)
		{
			Unit *pUnit = UnitFactory::Get()->readNextUnit(myfile);
			if (pUnit)
			{				
				unitList[idCount] = pUnit;
				idCount++;
			}
			else
				cout << "Erreur de lire d'unite " << i << "depuis fichier" << endl;
		}
	}
	else
		cout << "ERREUR: Fichier non existe - Creer une armee nulle !" << endl;
	myfile.close();
}

/*
Accesseur de la liste des unités ajoutées
@return ArmyMap : la liste des unités
*/
ArmyMap Army::getUnitList()
{
	return unitList;
}

// Le destructeur
Army::~Army()
{	
	unitList.clear();	
}