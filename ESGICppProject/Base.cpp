#include "Base.h"

Base::Base()
{
	//création de la base via un tableau à deux dimensions
	base = new Field(taille, taille, TILE_EMPTY);
	int beachPos = std::rand() % 20;
	Zone* beach;
	int i;
	if (beachPos < 5)
	{
		if (beachPos < 5)
		{
			beach = new Zone(2, 0, 6, 2);
			this->base->build(*beach);
		}
		else
		{
			beach = new Zone(2, 8, 6, 2);
			this->base->build(*beach);
		}
	}
	else 
	{
		if (beachPos < 15) 
		{
			beach = new Zone(0, 2, 2, 6);
			this->base->build(*beach);
		}
		else {
			beach = new Zone(8, 2, 2, 6);
			this->base->build(*beach);
		}
	}
	
	gold = 3000;
}

Base::Base(Base & ba)
{
	this->base = ba.base;
	this->gold = ba.gold;
	this->Building_List = ba.getList();
}

bool Base::Add(Building build, int x, int y)
{
	int width = build.get_width();
	int height = build.get_height();
	int cost = build.get_cost();
	int size = this->Building_List.size();
	Zone* NewBuilding = new Zone(x, y, width, height);
	if (this->base->build(*NewBuilding))
	{
		this->Building_List.push_back(build);
		this->Building_List.resize(size + 1);
		cout << "Bâtiment construit" << endl;
		this->gold -= cost;
		build.nextUpdateCost();
		return true;
	}
	else {
		cout << "Le bâtiment ne peut pas être construit ici" << endl;
		return false;
	}
}

void Base::EraseBuilding(Building build)
{
	for (int i = 0; i < this->Building_List.size; i++)
	{
		if (this->Building_List[i] == build)
		{
			*this->Building_List.erase(this->Building_List[i]);
		}
	}
	/*std::list<Building>::iterator IsExisting;
	IsExisting = find(this->Building_List.begin(), this->Building_List.end(), build);
	if (IsExisting != this->Building_List.end())
	{
		this->Building_List.remove(*IsExisting);
	}*/
	
}

void Base::Upgrades(Building build)
{
	std::vector<Building>::iterator IsExisting;
	IsExisting = find(this->Building_List.begin(), this->Building_List.end(), build);
	if ((IsExisting != this->Building_List.end()) && ((gold - build.get_cost()) >= 0))
	{
		build.levelUp();
		this->gold -= build.get_cost();
		build.nextUpdateCost();
	}
	else if (gold - build.get_cost() < 0)
	{
		cout << "Pas assez d'or pour améliorer le bâtiment." << endl;
	}
	else
	{
		cout << "Ce bâtiment n'existe pas dans votre base." << endl;
	}
}

void Base::DisplayBase()
{
	std::vector<Building>::iterator p = this->Building_List.begin();
	while (p != this->Building_List.end()) {
		cout << *p << " ";
		p++;
	}
}

Field * Base::getBase()
{
	return this->base;
}

int Base::getGold()
{
	return this->gold;
}

void Base::setGold(int gol)
{
	this->gold = gol;
}

std::vector<Building> Base::getList()
{
	return this->Building_List;
}



Base::~Base()
{
	delete[] base;
}
