#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Unit.h"

class UnitFactory
{
public:
	vector<string> UnitNameList();
	Unit* readNextUnit(std::istream& stream);
	void Register(const string &UnitName, CreateUnitFgpn pfnCreate);
	Unit *build(const string &unitName);

	~UnitFactory() { m_FactoryMap.clear(); }

	static UnitFactory *Get()
	{
		static UnitFactory instance;
		return &instance;
	}

private:
	typedef map<string, CreateUnitFgpn> FactoryMap;
	UnitFactory();
	UnitFactory(const UnitFactory &) { }
	UnitFactory &operator=(const UnitFactory &) { return *this; }
	FactoryMap m_FactoryMap;
};