#include "BuildingFactory.h"

vector<string> BuildingFactory::buildingList()
{
	vector<string> nameList(NUMBER_BUILDINGS, "");
	for (int i = 0; i < nameList.size(); i++)
	{
		nameList[i] = "BUILDING " + i;
	}
	return nameList;
}

Building* BuildingFactory::build(string name)
{
	vector<string> nameList = buildingList();
	for (int i = 0; i < nameList.size(); i++)
	{
		if (name == nameList[i])
		{
			Building *bd = new Building;
			bd->set_name(name);
			return bd;
		}
	}
	return nullptr;
}

Building* BuildingFactory::readNextBuilding(istream& stream)
{	
	char name[MAX_LENGTH_LINE];
	stream.get(name, MAX_LENGTH_LINE, ' ');
	int lvl;
	stream >> lvl;
	Building *bd = build(name);
	if (bd != nullptr)
	{
		for (int i = 0; i < lvl; i++)
			bd->levelUp();
	}
	return bd;
}