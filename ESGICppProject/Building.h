#pragma once

#include <iostream>
#include <string>
#include "Zone.h"
#include "Unit.h"

using namespace std;

class Building
{
public:
	Building() {}
	// Fonctions principales
	int nextUpdateCost();
	int levelUp();
	void setMode(int mo);
	void attackUnit(Unit * un);
	Unit* detect();
	void supportEnergy(Building* build);
	void supportShield(Building* build);
	void repairBuilding(Building* build);

	friend ostream& operator<<(ostream& os, const Building & bd);

	virtual void setDefaultParameters() = 0;
	virtual void Free() = 0;
	// Getters
	string getName() const { return name; }
	int getCost() const { return cost; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	int getHP() const { return hp; }
	int getLevel() const { return level; }
	float getHPUpdateRate() const { return healthUpdateRate; }
	float getCostUpdateRate() const { return costUpdateRate; }
	Zone getZone() const { return zone; }
	int getX() const { return zone.getX(); }
	int getY() const { return zone.getY(); }
	int getType() const { return this->type; }
	int getFireRate() const { return this->firerate; }

	// Setters	
	void setName(string nom) { name = nom; }
	void setCost(int cout) { cost = cout; }
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
	void setHP(int pv) { hp = pv; }
	void setLevel(int lvl) { level = lvl; }
	void setFireRate(int spd) { firerate = spd; }
	void setHPUpdateRate(float hpRate) { healthUpdateRate = hpRate; }
	void setCostUpdateRate(float costRate) { costUpdateRate = costRate; }
	void setZone(Zone z) { zone = z; }
	void setX(int x) { zone.setX(x); }
	void setY(int y) { zone.setY(y); }

protected:
	string name;
	int maxInstances;
	int cost;
	int width;
	int height;
	int hp;
	int level;
	int attack = 0;
	int repair = 0;
	int firerate;
	int range = 0;
	float healthUpdateRate;
	float costUpdateRate;
	Zone zone;
	// 0 = QG, 1 = offensif, 2 = réparation
	int type;
	//0 = pas attaquante, 1 = attaque le plus proche, 2 = attaque le plus faible, 3 = attaque le plus loin
	int mode = 0;
	bool area_action = false;
};

typedef Building * (__stdcall *CreateBuildingFgpn)(void);

// Définition de Building1
class QG : public Building
{
public:
	QG() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "QG";
		maxInstances = 1;
		cost = 1000;
		width = 1;
		height = 1;
		hp = 1000;
		level = 0;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
		type = 0;
	}

	void Free() { delete this; }

	static Building * __stdcall Create() { return new QG(); }
};

// Définition de Building2
class FlameThrower : public Building
{
public:
	FlameThrower() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Lance-flamme";
		maxInstances = 2;
		cost = 2000;
		width = 2;
		height = 2;
		hp = 1500;
		attack = 20;
		firerate = 999;
		range = 2;
		level = 0;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
		type = 1;
		area_action = true;
	}

	void Free() { delete this; }

	static Building * __stdcall Create() { return new FlameThrower(); }
};

// Définition de Building3
class Gatling : public Building
{
public:
	Gatling() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Mitrailleuse";
		maxInstances = 3;
		cost = 2000;
		width = 2;
		height = 3;
		hp = 2500;
		attack = 40;
		firerate = 10;
		range = 5;
		level = 0;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
		type = 1;
	}

	void Free() { delete this; }

		static Building * __stdcall Create() { return new Gatling(); }
};

// Définition de Building1
class Canon : public Building
{
public:
	Canon() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Canon";
		maxInstances = 2;
		cost = 2000;
		width = 1;
		height = 1;
		hp = 2000;
		attack = 150;
		firerate = 2;
		range = 5;
		level = 0;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
		type = 1;
		area_action = true;
	}

	void Free() { delete this; }

	static Building * __stdcall Create() { return new Canon(); }
};

// Définition de Building2
class SniperTower : public Building
{
public:
	SniperTower() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Tour de sniper";
		maxInstances = 2;
		cost = 2000;
		width = 2;
		height = 2;
		hp = 1500;
		attack = 100;
		firerate = 4;
		range = 8;
		level = 0;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
		type = 1;
	}

	void Free() { delete this; }

	static Building * __stdcall Create() { return new SniperTower(); }
};

// Définition de Building3
class RepairBuilding : public Building
{
public:
	RepairBuilding() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Bâtiment de réparation";
		maxInstances = 1;
		cost = 3000;
		width = 2;
		height = 3;
		hp = 1000;
		firerate = 1;
		range = 5;
		level = 0;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
		type = 2;
		repair = 40;
	}

	void Free() { delete this; }

	static Building * __stdcall Create() { return new RepairBuilding(); }
};

// Définition de Building1
class ShieldGenerator : public Building
{
public:
	ShieldGenerator() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Générateur de bouclier";
		maxInstances = 1;
		cost = 1000;
		width = 1;
		height = 1;
		hp = 1000;
		range = 5;
		level = 0;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
		type = 2;
	}

	void Free() { delete this; }

	static Building * __stdcall Create() { return new ShieldGenerator(); }
};

// Définition de Building2
class EnergyGenerator : public Building
{
public:
	EnergyGenerator() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Générateur d'énergie";
		maxInstances = 2;
		cost = 2000;
		width = 2;
		height = 2;
		hp = 2000;
		range = 5;
		level = 0;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
		type = 2;
	}

	void Free() { delete this; }

	static Building * __stdcall Create() { return new EnergyGenerator(); }
};

/* Possible d'ajouter d'autres types de batiment */