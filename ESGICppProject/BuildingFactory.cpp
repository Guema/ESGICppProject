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

void BuildingFactory::Register(const string &buildingName, CreateBuildingFgpn pfnCreate)
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

Building* BuildingFactory::readNextBuilding(istream& stream)
{
	string name;
	int lvl = 0;
	stream >> name >> lvl;

	Building *bd = build(name);

	if (bd)
	{
		bd->setLevel(0);
		for (int i = 0; i < lvl; i++)
			bd->levelUp();		
	}
	return bd;
}

vector<string> BuildingFactory::BuildingNameList()
{	
	vector<string> bdList;
	FactoryMap::iterator it, end = m_FactoryMap.end();
	for (it = m_FactoryMap.begin(); it != end; it++)
	{
		bdList.push_back(it->first);
	}
	for (int i = 0; i < bdList.size(); i++)
	{
		cout << bdList[i] << "     ";
	}
	cout << endl;
	return bdList;
}