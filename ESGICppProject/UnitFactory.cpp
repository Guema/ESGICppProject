#include "UnitFactory.h"

/* Unit factory constructor.
Register the types of Units here.
*/
UnitFactory::UnitFactory()
{	
	Register("Unit1", &Unit1::Create);
	Register("Unit2", &Unit2::Create);
	Register("Unit3", &Unit3::Create);
}

void UnitFactory::Register(const string &UnitName, CreateUnitFgpn pfnCreate)
{
	m_FactoryMap[UnitName] = pfnCreate;
}

Unit *UnitFactory::build(const string &unitName)
{
	FactoryMap::iterator it = m_FactoryMap.find(unitName);
	if (it != m_FactoryMap.end())
		return it->second();
	return nullptr;
}

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