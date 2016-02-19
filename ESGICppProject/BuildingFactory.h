#pragma once
#include <iostream>
#include <fstream>      // std::ifstream
#include <string>
#include <vector>
#include "Building.h"

#define NUMBER_BUILDINGS 10
#define MAX_LENGTH_LINE 20

class BuildingFactory
{
public:
	vector<string> buildingList();
	Building* build(string name);
	Building* readNextBuilding(std::istream& stream);
private:
};