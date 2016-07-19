#include "BuildingFactory.h"

/* 
Building factory constructor.
Register the types of buildings here.
*/
BuildingFactory::BuildingFactory()
{
	
	Register("QG", &QG::Create);
	Register("Lance-Flamme", &FlameThrower::Create);
	Register("Mittrailleuse", &Gatling::Create);
	Register("Canon", &Canon::Create);
	Register("Tour de sniper", &SniperTower::Create);
	Register("G�n�rateur d'energie", &EnergyGenerator::Create);
	Register("G�n�rateur de bouclier", &ShieldGenerator::Create);
	Register("B�timent de r�paration", &RepairBuilding::Create);
}

// D�finition de la map
void BuildingFactory::Register(const string &buildingName, CreateBuildingFgpn pfnCreate)
{
	m_FactoryMap[buildingName] = pfnCreate;
}

// Instancier un nouveau batiment � partir de son nom
Building *BuildingFactory::build(const string &buildingName)
{
	FactoryMap::iterator it = m_FactoryMap.find(buildingName);
	if (it != m_FactoryMap.end())
		return it->second();
	return nullptr;
}

// Cr�er un batiment et l'am�liorer au nom et niveau saisis
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

// Retourner la liste des noms des batiments
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