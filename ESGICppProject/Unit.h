#pragma once

#include <iostream>
#include <string>
#include "Building.h"

using namespace std;

class Unit
{
public:
	Unit() {}
	// Fonctions principales
	int nextUpdateCost();

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

	//
	void heal(Unit* uni);
	void AttackBuilding(Building * build, Building * QG);
	bool checkRange();
	int levelUp();

protected:
	string name;
	int maxInstances;
	int cost;
	int healing = 0;
	int attack = 0;
	float firerate;
	int range;
	int hp;
	float speed;
	int level;
	float attackUpdateRate;
	float firerateUpdateRate;
	float rangeUpdateRate;
	float healthUpdateRate;
	float costUpdateRate;
	bool isAttacking = false;
	bool blast_zone;
	//1 si unité de soutien, 2 sinon
	int type;
};

typedef Unit * (__stdcall *CreateUnitFgpn)(void);

class Kamikaze : public Unit
{
public:
	Kamikaze() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Kamikaze";
		maxInstances = 1;
		cost = 100;
		attack = 200;
		firerate = 1.0f;
		range = 1;
		hp = 300;
		speed = 3.0f;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		blast_zone = true;
		type = 2;
	}

	void autodestruction() {
		if (isAttacking) {
			this->hp = 0;
		}
	}

	void Free() { delete this; }

	static Unit * __stdcall Create() { return new Kamikaze(); }
};

class Brute : public Unit
{
public:
	Brute() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Brute";
		maxInstances = 1;
		cost = 100;
		attack = 150;
		firerate = 1.0f;
		range = 1;
		hp = 500;
		speed = 2.0f;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		blast_zone = false;
		type = 2;
	}

	void Free() { delete this; }

	static Unit * __stdcall Create() { return new Brute(); }
};

class Fusilleur : public Unit
{
public:
	Fusilleur() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Fusilleur";
		maxInstances = 1;
		cost = 100;
		attack = 10;
		firerate = 3.0f;
		range = 5;
		hp = 700;
		speed = 1.0f;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		blast_zone = false;
		type = 2;
	}

	void Free() { delete this; }

	static Unit * __stdcall Create() { return new Fusilleur(); }
};

class Sniper : public Unit
{
public:
	Sniper() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Sniper";
		maxInstances = 1;
		cost = 100;
		attack = 10;
		firerate = 0.2f;
		range = 10;
		hp = 700;
		speed = 0.5f;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		blast_zone = false;
		type = 2;
	}

	void Free() { delete this; }

	static Unit * __stdcall Create() { return new Sniper(); }
};

class Bazooka : public Unit
{
public:
	Bazooka() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Bazooka";
		maxInstances = 1;
		cost = 100;
		attack = 10;
		firerate = 0.2f;
		range = 5;
		hp = 500;
		speed = 0.5f;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		blast_zone = true;
		type = 2;
	}

	void Free() { delete this; }

	static Unit * __stdcall Create() { return new Bazooka(); }
};


class Contact_Medic : public Unit
{
public:
	Contact_Medic() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Médecin de contact";
		maxInstances = 1;
		cost = 100;
		healing = 50;
		firerate = 3.0f;
		range = 1;
		hp = 250;
		speed = 2.0f;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		blast_zone = false;
		type = 1;
	}

	void Free() { delete this; }

	static Unit * __stdcall Create() { return new Contact_Medic(); }
};

class Needle_Medic : public Unit
{
public:
	Needle_Medic() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Médecin Seringue";
		maxInstances = 1;
		cost = 100;
		healing = 30;
		firerate = 3.0f;
		range = 5;
		hp = 300;
		speed = 1.0f;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		blast_zone = false;
		type = 1;
	}

	void Free() { delete this; }

	static Unit * __stdcall Create() { return new Needle_Medic(); }
};

class AOE_Medic : public Unit
{
public:
	AOE_Medic() { setDefaultParameters(); }
	void setDefaultParameters()
	{
		name = "Médecin de zone";
		maxInstances = 1;
		cost = 100;
		healing = 5;
		firerate = 3.0f;
		range = 10;
		hp = 250;
		speed = 0.5f;
		level = 0;
		attackUpdateRate = 0.1f;
		firerateUpdateRate = 0.1f;
		rangeUpdateRate = 0.1f;
		healthUpdateRate = 0.2f;
		costUpdateRate = 0.1f;
		blast_zone = true;
		type = 1;
	}

	void Free() { delete this; }

	static Unit * __stdcall Create() { return new AOE_Medic(); }
};

/* Possible d'ajouter d'autres types d'uniité */