#pragma once
#include <iostream>
#include <fstream>      // std::ifstream
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "Building.h"

#define NUMBER_BUILDINGS 10
#define MAX_LENGTH_LINE 20

class BuildingFactory
{
public:
	vector<string> buildingList();
	Building* readNextBuilding(std::istream& stream);
	void Register(const string &buildingName, CreateBuildinFgpn pfnCreate);
	Building *build(const string &buildingName);

	~BuildingFactory() { m_FactoryMap.clear(); }

	static BuildingFactory *Get()
	{
		static BuildingFactory instance;
		return &instance;
	}

private:
	typedef map<string, CreateBuildinFgpn> FactoryMap;
	BuildingFactory();
	BuildingFactory(const BuildingFactory &) { }
	BuildingFactory &operator=(const BuildingFactory &) { return *this; }
	FactoryMap m_FactoryMap;
};