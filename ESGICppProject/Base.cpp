#include "Base.h"

/*Constructeur par défaut*/
Base::Base()
{	
	field = Field(FIELD_SIZE, FIELD_SIZE, TILE_EMPTY);
	
	int beachPos = (rand() % 100) % 4;
	int beachPos = (rand() % 100) % 4;
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
	gold = DEFAULT_BASE_GOLD;
	idCount = 1;
}

/*Constructeur de la base via un terrain et un montant d'or
@param Field &f : la zone utilisée par la base
@param int gold : l'or disponible au début*/
Base::Base(Field &f, int gold)
{
	field = f;
	this->gold = gold;
	idCount = 1;
	buildingList.clear();
}

/*Constructeur par copie
@param Base & ba : la base à copier*/
Base::Base(Base & ba)
{
	field = ba.field;
	gold = ba.gold;
	buildingList = ba.getBuildingList();
}

/*Ajout de bâtiment présent dans une liste prédéfinie
@string name : Le nom du bâtiment
@int x : Position du bâtiment en x
@int y : Position du bâtiment en y
@return bool : true si le bâtiment a bien été ajouté, false sinon*/
bool Base::AddBuilding(string name, int x, int y)
{
	Building *pBuilding = BuildingFactory::Get()->build(name);

	//véifie que le bâtiment existe bien dans la liste des bâtiments disponible
	if (pBuilding)
	{
		Zone z(x, y, pBuilding->getWidth(), pBuilding->getHeight(), idCount);
		if (field.isEmpty(z))
		{
			pBuilding->setZone(z);
			field.build(z);
			buildingList[idCount] = pBuilding;
			idCount++;
			gold -= pBuilding->getCost();
			cout << "ADD ok" << endl;
			return true;
		}
		else
			cout << "ERREUR: la zone choisie n'est pas vide pour construire!" << endl;
	}
	else
		cout << "ERREUR: le nom choisi n'est pas un nom du batiment valide!" << endl;		
	return false;
}

bool Base::UpgradeBuilding(int id)
@int id : Identifiant du bâtiment
@return bool : true si le bâtiment a bien été supprimé, false si celui-ci n'existe pas sur le terrain*/
{
	BaseMap::iterator it;
	it = buildingList.find(id);
	if (it != buildingList.end())
	{
		gold -= it->second->nextUpdateCost();
		it->second->levelUp();
		cout << "Upgrade ok" << endl;
		return true;
	}
	cout << "ERREUR: l'ID choisie n'existe pas - peut pas ameliorer!" << endl;
	return false;
}

bool Base::RemoveBuilding(int id)
@int id : Identifiant du bâtiment
@return bool : true si le bâtiment a bien été amélioré, false si celui-ci n'existe pas sur le terrain*/
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

/*Affichage de la base via l'état de toute les postions présentes dessus*/
void Base::DisplayBase()
{
	cout << "MONTANT D'OR RESTANT : " << gold << endl;
	cout << "Les batiments existants sur le terrain : " << endl;
	for (BaseMap::iterator it = buildingList.begin(); it != buildingList.end(); it++)
	{
		cout << *it->second;
	}
	cout << endl;
	cout << "LE TERRAIN : " << endl;
	cout << field;
	cout << endl;
}

/*Sauvegarde de la base dans un fichier
@string myFile : le nom du fichier de sauvegarde*/
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

/*Chargement d'une base via un fichier de sauvegarde
@string myFile : le nom du fichier de sauvegarde à charger*/
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

/*Accesseur du terrain
@return Field : l'état du terrain*/
Field Base::getField()
{
	return field;
}

/*Accesseur de la liste des bâtiments construits
@return BaseMap : la liste des bâtiments*/
BaseMap Base::getBuildingList()
{
	return buildingList;
}

/*Accesseur de l'or du joueur
@return int : le montant d'or à disposition du joueur*/
Base::~Base()
{	
	buildingList.clear();	
}