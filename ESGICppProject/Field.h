
#include <vector>
#include <memory>
#include <iostream>

#include "Zone.h"

using namespace std;
typedef int Tile;

#define TILE_EMPTY -1
#define TILE_LANDING -2
#define TILE_UNREACHABLE -4
#define TILE_OUT_OF_BOUND 0
#define TILE_BUILDING 1

class Field
{
protected:
   int width;
   int height;
   vector<Tile> slots;

public:
	Field(const int& dim_x,const int& dim_y, const Tile& s = TILE_EMPTY);
	Field(const Field &f);
	void swap(Field &f);
	Field & operator=(Field &f);
	virtual ~Field();

	int getW() const { return width; }
	int getH() const { return height; }
	int& operator()(const int& posx, const int& posy);
	int getTile(const int& posx, const int& posy) const;
	bool isEmpty(Zone& z) const;
	Zone findEmptyZone(const int& width,const int& height) const;
	bool build(Zone& z);
	void erase(Zone& z);
	friend ostream& operator<<(ostream& os, Field& field);
	friend istream& operator>>(istream& is, Field& field);
};

