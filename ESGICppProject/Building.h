#pragma once

#include <iostream>
#include <string>
#include "Zone.h"

using namespace std;

class Building
{
public:	
	Building() {}
	// Fonctions principales
	int nextUpdateCost();
	int levelUp();

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
	
	// Setters	
	void setName(string nom) { name = nom; }
	void setCost(int cout) { cost = cout; }
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
	void setHP(int pv) { hp = pv; }
	void setLevel(int lvl) { level = lvl; }
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
	float healthUpdateRate;
	float costUpdateRate;
	Zone zone;
};

typedef Building * (__stdcall *CreateBuildinFgpn)(void);

class Building1 : public Building
{
public:
	Building1() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Building1";
		maxInstances = 1;
		cost = 1000;
		width = 1;
		height = 1;
		hp = 1000;
		level = 1;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
	}
	
	void Free() { delete this; }

	static Building * __stdcall Create() { return new Building1(); }
};

class Building2 : public Building
{
public:
	Building2() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Building2";
		maxInstances = 2;
		cost = 1000;
		width = 2;
		height = 2;
		hp = 1000;
		level = 1;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
	}

	void Free() { delete this; }

	static Building * __stdcall Create() { return new Building2(); }
};

class Building3 : public Building
{
public:
	Building3() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Building3";
		maxInstances = 3;
		cost = 1000;
		width = 2;
		height = 3;
		hp = 1000;
		level = 1;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		zone = Zone(0, 0, width, height);
	}

	void Free() { delete this; }

	static Building * __stdcall Create() { return new Building3(); }
};