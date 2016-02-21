#pragma once

#include <iostream>
#include <fstream>

#include "UnitFactory.h"

using namespace::std;

typedef map<int, Unit*> ArmyMap;

class Army
{
public:
	Army();	
	bool AddUnit(string name);
	bool UpgradeUnit(int id); 
	bool RemoveUnit(int id);	
	void DisplayArmy();
	void SaveArmy(string myFile);
	void LoadArmy(string myFile);
	ArmyMap getUnitList();
	
	~Army();

private:
	int idCount;
	ArmyMap unitList;
};