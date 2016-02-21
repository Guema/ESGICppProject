#pragma once
#include <string>
#include <iostream>
#include <math.h>
#include "Base.h"
#include "BuildingFactory.h"
#include "Field.h"
#include "Zone.h"
#include <list>
using namespace std;

#define FIELD_SIZE 20
class Base
{
public:
	Base(int);
	Base(Field&, int);
	int AddBuilding(string name, int x, int y, int w, int h);
	int DeleteBuilding(int id);
	int LevelUpBuilding(int id);

	~Base();

private:
	Field *field;
	int gold;
	list<Building> buildingList;

};