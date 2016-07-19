#include "Unit.h"

// Calculer le cout d'amélioration pour le niveau prochain
int Unit::nextUpdateCost()
{
	return (int)(cost*(1 + costUpdateRate));
}


void Unit::heal(Unit * uni)
{
	uni->setHP(uni->getHP() + this->healing);
}

void Unit::AttackBuilding(Building * build, Building * QG)
{
	build->setHP(build->getHP() - this->attack);
	if (QG->getType() == 0 && build->getType() != 0)
		QG->setHP(QG->getHP() - (this->attack*0.1));
	isAttacking = true;
}

bool Unit::checkRange()
{
	return false;
}

// Améliorer l'unité au niveau prochain
// Retourner le cout pour l'amélioration
int Unit::levelUp()
{
	if (this->type == 1)
		healing = (int)(healing*(1 + attackUpdateRate));
	else
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
