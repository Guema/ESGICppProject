#pragma once
#include <string>
#include <iostream>
#include <math.h>
#include "Base.h"
#include "BuildingFactory.h"
#include "Field.h"
#include "Zone.h"
#include <list>
using namespace::std;

class Base
{
public:
	Base();
	Base(Base& ba);
	int Add(Building build, int x, int y);
	~Base();

private:
	int **base;
	int gold;
	const static int taille = 20;
	std::list<Building> Building_List;

};