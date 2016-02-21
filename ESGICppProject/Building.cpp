#include "Building.h"

// Calculer le cout d'amélioration pour le niveau prochain
int Building::nextUpdateCost()
{
	return (int)(cost*(1+costUpdateRate));
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

// Surchargeur d'écriture pour un batiment
ostream& operator<<(ostream& os, const Building & bd)
{
	os << bd.getName() << " - level " << bd.getLevel() << " - HP = " << bd.getHP() << endl;
	return os;
}