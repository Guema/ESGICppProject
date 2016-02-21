#include "Unit.h"

int Unit::nextUpdateCost()
{
	return (int)(cost*(1 + costUpdateRate));
}

int Unit::levelUp()
{
	attack = (int)(attack*(1 + attackUpdateRate));
	firerate = firerate*(1 + firerateUpdateRate);
	range = (int)(range*(1 + rangeUpdateRate));
	hp = (int)(hp*(1 + healthUpdateRate));
	cost += nextUpdateCost();
	level++;
	return cost;
}

// Surchargeur d'écriture
ostream& operator<<(ostream& os, const Unit & u)
{
	os << u.getName() << " - level " << u.getLevel() << " HP = " << u.getHP() << endl;
	return os;
}