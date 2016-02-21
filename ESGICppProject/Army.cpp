#include "Army.h"

// Constructeur par d�faut
Army::Army()
{
	gold = DEFAULT_ARMY_GOLD;
	idCount = 1;
}

/* 
Constructeur de la base via un montant d'or
@param int gold : le montant d'or � passer 
*/
Army::Army(int gold)
{	
	this->gold = gold;
	idCount = 1;
	unitList.clear();
}

/*
Constructeur par copie
@param Base & ar : l'arm�e � copier
*/
Army::Army(Army & ar)
{	
	gold = ar.gold;
	unitList = ar.unitList;
}

/*
Ajout d'une unit� dans la liste d'arm�e
@string name : Le nom de l'unit�
@return bool : true si l'unit� a bien �t� ajout�, false sinon
*/
bool Army::AddUnit(string name)
{
	Unit *pUnit = UnitFactory::Get()->build(name);

	//v�ifie que l'unit� existe bien dans la liste des unit�s d�finies
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
Am�liorer une unit� via son ID dans la liste
@int id : Identifiant de l'unit�
@return bool : true si l'unit� a bien �t� am�lior�e, false si celui-ci n'existe pas dans la liste
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
Supprimer une unit� via son ID dans la liste
@int id : Identifiant de l'unit�
@return bool : true si l'unit� a bien �t� supprim�e, false si celui-ci n'existe pas dans la liste
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

// Affichage de l'arm�e
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
Sauvegarde de l'arm�e dans un fichier
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
Chargement de l'arm�e via un fichier de sauvegarde
@string myFile : le nom du fichier de sauvegarde � charger
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
Accesseur de la liste des unit�s ajout�es
@return ArmyMap : la liste des unit�s
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