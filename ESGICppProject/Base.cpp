#include "Base.h"

Base::Base()
{
	//cr�ation de la base via un tableau � deux dimensions
	base = new int*[taille];
	for (int i = 0; i < taille; i++) {
		base[i] = new int[taille];
		for (int j = 0; j < taille; j++) {
			//�tat de la case : 0 -> libre, 1 -> occup�e, 2 -> plage d�barquement
			base[i][j] = 0;
		}
	}
	int beach = std::rand() % 20;
	if (beach < 5) {
		for (int i = 0; i < 2; i++) {
			for (int j = 2; j < 8; j++) {
				base[i][j] = 2;
			}
		}
	}
	else if ((beach >= 5) && (beach < 10)) {
		for (int i = 2; i < 8; i++) {
			for (int j = 0; j < 2; j++) {
				base[i][j] = 2;
			}
		}
	}
	else if ((beach >= 10) && (beach < 15)) {
		for (int i = 8; i < 10; i++) {
			for (int j = 2; j < 8; j++) {
				base[i][j] = 2;
			}
		}
	}
	else{
		for (int i = 2; i < 8; i++) {
			for (int j = 8; j < 10; j++) {
				base[i][j] = 2;
			}
		}
	}
}

Base::Base(Base & ba)
{
	this->base = ba.base;
	this->gold = ba.gold;
}

int Base::Add(Building build, int x, int y)
{
	int width = build.get_width;
	int height = build.get_height;
	if (base[x][y] == 0)
	{
		for (int i = 0; i < height; i++) 
		{
			if (base[i][y] == 0)
			{
				for (int j = 0; j < width; j++)
				{
					if (base[i][j] != 0) 
					{
						cout << "Le b�timent ne peut pas �tre construit ici" << endl;
						return 0;
					}
				}
			}
			else
			{
				cout << "Le b�timent ne peut pas �tre construit ici" << endl;
				return 0;
			}
		}
		Building_List.push_back(build);
		cout << "B�timent construit" << endl;
		return 1;
	}
	else {
		cout << "Le b�timent ne peut pas �tre construit ici" << endl;
		return 0;
	}
}



Base::~Base()
{
	for (int i = 0; i < taille; ++i)
	{
		delete[] base[i];
	}
	delete[] base;
}