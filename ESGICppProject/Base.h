#pragma once
#include <string>
#include <iostream>
#include <math.h>
#include "Base.h"
#include "BuildingFactory.h"
#include "Field.h"
#include "Zone.h"
#include <vector>
using namespace::std;

class Base
{
public:
	Base();
	Base(Base& ba);
	bool Add(Building build, int x, int y);
	void EraseBuilding(Building build);
	void Upgrades(Building build);
	void DisplayBase();
	Field* getBase();
	int getGold();
	void setGold(int gol);
	std::vector<Building> getList();
	~Base();

private:
	Field* base;
	int gold;
	const static int taille = 20;
	std::vector<Building> Building_List;

};