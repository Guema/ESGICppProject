#pragma once

#include <iostream>
#include <string>

using namespace std;

class Unit
{
public:	
	Unit() {}
	// Fonctions principales
	int nextUpdateCost();
	int levelUp();

	friend ostream& operator<<(ostream& os, const Unit & u);

	virtual void setDefaultParameters() = 0;
	virtual void Free() = 0;
	// Getters
	string getName() const { return name; }
	int getCost() const { return cost; }
	int getHP() const { return hp; }
	int getLevel() const { return level; }
	float getHPUpdateRate() const { return healthUpdateRate; }
	float getCostUpdateRate() const { return costUpdateRate; }
	
	// Setters	
	void setName(string nom) { name = nom; }
	void setCost(int cout) { cost = cout; }
	void setHP(int pv) { hp = pv; }
	void setLevel(int lvl) { level = lvl; }
	void setHPUpdateRate(float hpRate) { healthUpdateRate = hpRate; }
	void setCostUpdateRate(float costRate) { costUpdateRate = costRate; }
	
protected:
	string name;
	int maxInstances;
	int cost;
	int attack;
	float firerate;
	int range;
	int hp;
	int level;
	float attackUpdateRate;
	float firerateUpdateRate;
	float rangeUpdateRate;
	float healthUpdateRate;
	float costUpdateRate;
};

typedef Unit * (__stdcall *CreateUnitFgpn)(void);

class Unit1 : public Unit
{
public:
	Unit1() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Unit1";
		maxInstances = 1;
		cost = 100;
		attack = 10;
		firerate = 0.5f;
		range = 10;
		hp = 1000;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
	}
	
	void Free() { delete this; }

	static Unit * __stdcall Create() { return new Unit1(); }
};

class Unit2 : public Unit
{
public:
	Unit2() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Unit2";
		maxInstances = 2;
		cost = 200;
		attack = 10;
		firerate = 0.5f;
		range = 10;
		hp = 2000;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
	}

	void Free() { delete this; }

	static Unit * __stdcall Create() { return new Unit2(); }
};

class Unit3 : public Unit
{
public:
	Unit3() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Unit3";
		maxInstances = 3;
		cost = 300;
		attack = 10;
		firerate = 0.5f;
		range = 10;
		hp = 3000;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
	}

	void Free() { delete this; }

	static Unit * __stdcall Create() { return new Unit3(); }
};