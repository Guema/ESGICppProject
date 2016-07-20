#pragma once

#include <iostream>
#include <fstream>
#include "BuildingFactory.h"
#include "Field.h"

using namespace std;

#define FIELD_SIZE 20				// La taille du terrain
#define BEACH_SIZE 12				// La taille de la plage
#define DEFAULT_BASE_GOLD 100000	// Le montant d'or par défaut

typedef map<int, Building*> BaseMap;

class Base
{
public:
	Base();
	Base(Field&, int);
	Base(Base& ba);
	~Base(); 
	
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
	void setHQ(QG* qg) { this->hq = qg; }

private:	
	Field field;
	int gold;
	int idCount;
	BaseMap buildingList;
	QG* hq = nullptr;
};