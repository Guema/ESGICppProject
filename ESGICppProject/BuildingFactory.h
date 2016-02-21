#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "Building.h"

class BuildingFactory
{
public:
	vector<string> BuildingNameList();
	Building* readNextBuilding(std::istream& stream);
	void Register(const string &buildingName, CreateBuildingFgpn pfnCreate);
	Building *build(const string &buildingName);

	~BuildingFactory() { m_FactoryMap.clear(); }

	static BuildingFactory *Get()
	{
		static BuildingFactory instance;
		return &instance;
	}

private:
	typedef map<string, CreateBuildingFgpn> FactoryMap;
	BuildingFactory();
	BuildingFactory(const BuildingFactory &) { }
	BuildingFactory &operator=(const BuildingFactory &) { return *this; }
	FactoryMap m_FactoryMap;
};