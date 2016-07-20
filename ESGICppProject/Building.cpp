#include "Building.h"

// Calculer le cout d'amélioration pour le niveau prochain
int Building::nextUpdateCost()
{
	return (int)(cost*(1 + costUpdateRate));
}

// Améliorer le batiment au niveau prochain
// Retourner le cout pour l'amélioration
int Building::levelUp()
{
	int updateCost = nextUpdateCost();
	hp = (int)(hp*(1 + healthUpdateRate));
	cost += updateCost;
	level++;
	return updateCost;
}


void Building::setMode(int mo)
{
	this->mode = mo;
}

void Building::attackUnit(Unit * un)
{
	un->setHP(un->getHP() - this->attack);
}

Unit * Building::detect()
{
	Unit * unit;
	while (true)
	{

	}
	return nullptr;
}

void Building::supportEnergy(Building * build)
{
	build->setFireRate(build->getFireRate() + 10);
}

void Building::supportShield(Building * build)
{
	build->setHP(build->getHP() + 1000);
}

void Building::repairBuilding(Building * build)
{
	build->setHP(build->getHP() + this->repair);
}

// Surchargeur d'écriture pour un batiment
ostream& operator<<(ostream& os, const Building & bd)
{
	os << bd.getName() << " - level " << bd.getLevel() << " - HP = " << bd.getHP() << endl;
	return os;
}