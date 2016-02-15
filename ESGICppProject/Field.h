#pragma once

#include <vector>
#include <memory>

#include "Zone.h"

typedef int Slot;

#define SLOT_EMPTY -1
#define SLOT_BUILDING -2
#define SLOT_UNREACHABLE -4
#define SLOT_BUILDING 1

class Field
{
protected:
   int width;
   int height;
   std::unique_ptr<std::vector<Slot> > slots;

public:
   Field(const int& dim_x,const int& dim_y, const Slot& s = SLOT_EMPTY);
	virtual ~Field();

	int getW() { return width; }
	int getH() { return height; }
   int& operator()(const int& posx, const int& posy);
   bool isEmpty(const Zone& z);
   Zone findEmptyZone(const int& width,const int& height);
};