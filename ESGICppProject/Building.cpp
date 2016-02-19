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
	os << "Building " << bd.get_name() << " - level " << bd.get_level() << endl;
	return os;
}

// Getters
string Building::get_name() const
{
	return name;
}

int Building::get_cost() const
{
	return cost;
}

int Building::get_width() const
{
	return width;
}

int Building::get_height() const
{
	return height;
}

int Building::get_hp() const
{
	return hp;
}

int Building::get_level() const
{
	return level;
}

// Setters
void Building::set_name(string nom)
{
	name = nom;
}

void Building::set_cost(int cout)
{
	cost = cout;
}

void Building::set_width(int w)
{
	width = w;
}

void Building::set_height(int h)
{
	height = h;
}

void Building::set_hp(int pv)
{
	hp = pv;
}

void Building::set_level(int lvl)
{
	level = lvl;
}