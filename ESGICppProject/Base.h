#pragma once

#include <iostream>
#include <fstream>

#include "BuildingFactory.h"
#include "Field.h"

using namespace::std;

#define FIELD_SIZE 20
#define BEACH_SIZE 12
#define DEFAULT_BASE_GOLD 100000

typedef map<int, Building*> BaseMap;

class Base
{
public:
	Base();
	Base(Field&, int);
	Base(Base& ba);
	bool AddBuilding(string name, int x, int y);
	bool RemoveBuilding(int id);
	bool UpgradeBuilding(int id);
	void DisplayBase();
	void SaveBase(string myFile);
	void LoadBase(string myFile);
	Field getField();
	BaseMap getBuildingList();
	
	int getGold() const { return gold; }
	void setGold(int gold) { this->gold = gold; }
	
	~Base();

private:	
	Field field;
	int gold;
	int idCount;
	BaseMap buildingList;
};