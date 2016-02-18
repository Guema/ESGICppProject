
#include <vector>
#include <memory>
#include <iostream>

#include "Zone.h"

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
   std::vector<Tile> slots;

public:
   Field(const int& dim_x,const int& dim_y, const Tile& s = TILE_EMPTY);
	virtual ~Field();

	int getW() const { return width; }
	int getH() const { return height; }
   int& operator()(const int& posx, const int& posy);
   int getTile(const int& posx, const int& posy) const;
   bool isEmpty(Zone& z) const;
   Zone findEmptyZone(const int& width,const int& height) const;
   bool build(Zone& z);
   void erase(Zone& z);
   friend std::ostream& operator<<(std::ostream& os, Field& field);
   friend std::istream& operator>>(std::istream& is, Field& field);
};

