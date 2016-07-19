#include "UnitFactory.h"

/*
Unit factory constructor.
Register the types of Units here.
*/
UnitFactory::UnitFactory()
{
	Register("Kamikaze", &Kamikaze::Create);
	Register("Brute", &Brute::Create);
	Register("Fusilleur", &Fusilleur::Create);
	Register("Sniper", &Sniper::Create);
	Register("Bazooka", &Bazooka::Create);
	Register("M�decin de contact", &Contact_Medic::Create);
	Register("M�decin Seringue", &Needle_Medic::Create);
	Register("M�decin de zone", &AOE_Medic::Create);
}

// D�finition de la map
void UnitFactory::Register(const string &UnitName, CreateUnitFgpn pfnCreate)
{
	m_FactoryMap[UnitName] = pfnCreate;
}

// Instancier une nouvelle unit� � partir de son nom
Unit *UnitFactory::build(const string &unitName)
{
	FactoryMap::iterator it = m_FactoryMap.find(unitName);
	if (it != m_FactoryMap.end())
		return it->second();
	return nullptr;
}

// Cr�er une unit� et l'am�liorer au nom et niveau saisis
Unit* UnitFactory::readNextUnit(istream& stream)
{
	string name;
	int lvl = 0;
	stream >> name >> lvl;

	Unit *u = build(name);

	if (u)
	{
		u->setLevel(0);
		for (int i = 0; i < lvl; i++)
			u->levelUp();
	}
	return u;
}

// Retourner la liste des noms des unit�s
vector<string> UnitFactory::UnitNameList()
{
	vector<string> uList;
	FactoryMap::iterator it, end = m_FactoryMap.end();
	for (it = m_FactoryMap.begin(); it != end; it++)
	{
		uList.push_back(it->first);
	}
	for (int i = 0; i < uList.size(); i++)
	{
		cout << uList[i] << "     ";
	}
	cout << endl;
	return uList;
}