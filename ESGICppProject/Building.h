#pragma once

#include <iostream>
#include <string>
#include "Zone.h"

using namespace std;

class Building
{
public:	
	// Fonctions principales
	int nextUpdateCost();
	int levelUp();

	// Getters
	string get_name() const;
	int get_cost() const;
	int get_width() const;
	int get_height() const;
	int get_hp() const;
	int get_level() const;

	// Setters
	void set_name(string nom);
	void set_cost(int cout);
	void set_width(int w);
	void set_height(int h);
	void set_hp(int pv);
	void set_level(int lvl);

private:
	string name;
	int maxInstances;
	int cost;
	int width;
	int height;
	int hp;
	int level;
	float healthUpdateRate;
	float costUpdateRate;
	Zone zone;
};

ostream& operator<<(ostream& os, const Building & bd);