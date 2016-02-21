#pragma once

#include <iostream>
#include <fstream>
#include "UnitFactory.h"

using namespace std;

#define DEFAULT_ARMY_GOLD 50000		// Le montant d'or par défaut de l'armée
typedef map<int, Unit*> ArmyMap;

class Army
{
public:
	Army();
	Army(int gold);
	Army(Army &ar);
	~Army();

	bool AddUnit(string name);
	bool UpgradeUnit(int id); 
	bool RemoveUnit(int id);	
	void DisplayArmy();
	void SaveArmy(string myFile);
	void LoadArmy(string myFile);
	ArmyMap getUnitList();

private:
	int gold;
	ArmyMap unitList;
	int idCount;
};