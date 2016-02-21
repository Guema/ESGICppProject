#include "Base.h"

Base::Base()
{	
	field = Field(FIELD_SIZE, FIELD_SIZE, TILE_EMPTY);
	
	int beachPos = (rand() % 100) % 4; // NOTE: Donne la même valeur (3) chaque fois, pourquoi???
	cout << "beachPosition = " << beachPos << endl;
	Zone beach;
	switch (beachPos)
	{
	case 0:
		beach = Zone((FIELD_SIZE - BEACH_SIZE) / 2, 0, BEACH_SIZE, 1, TILE_LANDING);
		break;
	case 1:
		beach = Zone(0,(FIELD_SIZE - BEACH_SIZE) / 2, 1, BEACH_SIZE, TILE_LANDING);
		break;
	case 2:
		beach = Zone((FIELD_SIZE - BEACH_SIZE) / 2, FIELD_SIZE-1, BEACH_SIZE, 1, TILE_LANDING);
		break;
	case 3:
		beach = Zone(FIELD_SIZE-1, (FIELD_SIZE - BEACH_SIZE) / 2, 1, BEACH_SIZE, TILE_LANDING);
		break;
	default:
		break;
	} 	
	field.build(beach);
	gold = DEFAULT_GOLD;
	idCount = 1;
}

Base::Base(Field &f, int gold)
{
	field = f;
	this->gold = gold;
	idCount = 1;
	buildingList.clear();
}

Base::Base(Base & ba)
{
	field = ba.field;
	gold = ba.gold;
	buildingList = ba.getBuildingList();
}

bool Base::AddBuilding(string name, int x, int y)
{
	Building *pBuilding = BuildingFactory::Get()->build(name);

	if (pBuilding)
	{
		Zone z(x, y, pBuilding->getWidth(), pBuilding->getHeight(), idCount);
		if (field.isEmpty(z))
		{
			pBuilding->setZone(z);
			field.build(z);
			buildingList[idCount] = pBuilding;
			idCount++;
			cout << "ADD ok" << endl;
			return true;
		}
		else
			cout << "ERREUR: la zone choisie n'est pas vide pour construire!" << endl;
	}
	else
	{
		cout << "ERREUR: le nom choisi n'est pas un nom du batiment valide!" << endl;		
	}
	return false;
}

bool Base::RemoveBuilding(int id)
{
	BaseMap::iterator it;
	it = buildingList.find(id);
	if (it != buildingList.end())
	{
		field.erase(it->second->getZone());
		buildingList.erase(it);
		cout << "Remove ok" << endl;
		return true;
	}
	cout << "ERREUR: l'ID choisie n'existe pas - peut pas enlever!" << endl;
	return false;	
}

bool Base::UpgradeBuilding(int id)
{
	BaseMap::iterator it;
	it = buildingList.find(id);
	if (it != buildingList.end())
	{
		it->second->levelUp();
		cout << "Upgrade ok" << endl;
		return true;
	}
	cout << "ERREUR: l'ID choisie n'existe pas - peut pas ameliorer!" << endl;
	return false;
}

void Base::DisplayBase()
{
	cout << "Les batiments existants sur la terraine:" << endl;
	for (BaseMap::iterator it = buildingList.begin(); it != buildingList.end(); it++)
	{
		cout << *it->second << endl;
	}
	cout << "LA TERRAINE:" << endl;
	cout << field;
}

void Base::SaveBase(string myFile)
{
	ofstream myfile;
	myfile.open(myFile);
	
	if (myfile.is_open())
	{
		myfile << field;
		myfile << gold << endl;

		myfile << buildingList.size() << endl;
		for (BaseMap::iterator it = buildingList.begin(); it != buildingList.end(); it++)
		{
			myfile << (*it->second).getName() << " " << (*it->second).getLevel() << endl;
		}
		for (BaseMap::iterator it = buildingList.begin(); it != buildingList.end(); it++)
		{
			myfile << (*it->second).getX() << " " << (*it->second).getY() << endl;
		}
		cout << "SAVE ok" << endl;
	}
	else
		cout << "ERREUR: Impossible d'ouvrir le fichier pour sauvegarder!" << endl;
	myfile.close();
}

void Base::LoadBase(string myFile)
{
	ifstream myfile;
	int size;

	myfile.open(myFile);
	if (myfile.is_open())
	{
		myfile >> field;
		myfile >> gold;
		idCount = 1;
		buildingList.clear();

		myfile >> size;
		for (int i = 0; i < size; i++)
		{
			Building *pBuilding = BuildingFactory::Get()->readNextBuilding(myfile);
			if (pBuilding)
			{				
				buildingList[idCount] = pBuilding;
				idCount++;
			}
			else
				cout << "Erreur de lire du batiment " << i << "depuis fichier" << endl;
		}

		for (int i = 1; i < size; i++)
		{
			int x, y;
			myfile >> x >> y;
			buildingList[i+1]->setX(x); // i+1 car idCount commence à 1!
			buildingList[i+1]->setY(x);
		}
	}
	else
		cout << "ERREUR: Fichier non existe - Creer une nouvelle partie!" << endl;
	myfile.close();
}

Field Base::getField()
{
	return field;
}

BaseMap Base::getBuildingList()
{
	return buildingList;
}

Base::~Base()
{	
	buildingList.clear();	
}