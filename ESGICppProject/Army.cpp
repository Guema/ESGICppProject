#include "Army.h"

Army::Army()
{		
	idCount = 1;
}

bool Army::AddUnit(string name)
{
	Unit *pUnit = UnitFactory::Get()->build(name);

	if (pUnit)
	{
		unitList[idCount] = pUnit;
		idCount++;
		cout << "ADD Unit ok" << endl;
		return true;
	}
	else
		cout << "ERREUR: le nom choisi n'est pas un nom d'unite valide!" << endl;
	return false;
}

bool Army::UpgradeUnit(int id)
{
	ArmyMap::iterator it;
	it = unitList.find(id);
	if (it != unitList.end())
	{
		it->second->levelUp();
		cout << "Upgrade UNIT ok" << endl;
		return true;
	}
	cout << "ERREUR: l'ID choisie n'existe pas - peut pas ameliorer UNIT!" << endl;
	return false;
}

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

void Army::DisplayArmy()
{
	cout << "Les unites existants dans l'armee : " << endl;
	for (ArmyMap::iterator it = unitList.begin(); it != unitList.end(); it++)
	{
		cout << *it->second;
	}
	cout << endl;
}

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
		cout << "ERREUR: Fichier non existe - Creer une nouvelle partie!" << endl;
	myfile.close();
}

ArmyMap Army::getUnitList()
{
	return unitList;
}

Army::~Army()
{	
	unitList.clear();	
}