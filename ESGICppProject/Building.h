#pragma once

#include <iostream>
#include <string>
#include "Zone.h"
#include "Building.h"

class Building
{


private:
	std::string name;
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