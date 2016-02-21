#include "Building.h"

int Building::nextUpdateCost()
{
	return (int)(cost*costUpdateRate);
}

int Building::levelUp()
{
	hp = (int)(hp*(1 + healthUpdateRate));
	cost += nextUpdateCost();
	level++;
	return cost;
}

// Surchargeur d'écriture
ostream& operator<<(ostream& os, const Building & bd)
{
	os << bd.getName() << " - level " << bd.getLevel() << " HP = " << bd.getHP() << endl;
	return os;
}