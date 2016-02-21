#include "Building.h"

// Calculer le cout d'am�lioration pour le niveau prochain
int Building::nextUpdateCost()
{
	return (int)(cost*(1+costUpdateRate));
}

// Am�liorer le batiment au niveau prochain
// Retourner le cout pour l'am�lioration
int Building::levelUp()
{
	int updateCost = nextUpdateCost();
	hp = (int)(hp*(1 + healthUpdateRate));
	cost += updateCost;
	level++;
	return updateCost;
}

// Surchargeur d'�criture pour un batiment
ostream& operator<<(ostream& os, const Building & bd)
{
	os << bd.getName() << " - level " << bd.getLevel() << " - HP = " << bd.getHP() << endl;
	return os;
}