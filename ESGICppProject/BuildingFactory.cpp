#include "BuildingFactory.h"

/* Building factory constructor.
Register the types of buildings here.
*/
BuildingFactory::BuildingFactory()
{
	;
	Register("Building1", &Building1::Create);
	Register("Building2", &Building2::Create);
	Register("Building3", &Building3::Create);
}

void BuildingFactory::Register(const string &buildingName, CreateBuildinFgpn pfnCreate)
{
	m_FactoryMap[buildingName] = pfnCreate;
}

Building *BuildingFactory::build(const string &buildingName)
{
	FactoryMap::iterator it = m_FactoryMap.find(buildingName);
	if (it != m_FactoryMap.end())
		return it->second();
	return nullptr;
}

vector<string> BuildingFactory::buildingList()
{	
	vector<string> bdList;
	FactoryMap::iterator it, end = m_FactoryMap.end();
	for (it = m_FactoryMap.begin(); it != end; it++)
	{
		bdList.push_back(it->first);
	}
	for (int i = 0; i < bdList.size(); i++)
	{
		cout << bdList[i] << endl;
	}
	return bdList;
}

Building* BuildingFactory::readNextBuilding(istream& stream)
{	
	string s, name; 	
	int lvl = 1;	
	stream >> name >> lvl;
	
	Building *bd = build(name);	
	
	if (bd)
	{
		bd->setLevel(1);
		for (int i = 0; i < lvl-1; i++)
			bd->levelUp();
		return bd;
	}
	return nullptr;
}