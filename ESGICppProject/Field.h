#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Zone.h"

typedef int Slot;

#define SLOT_EMPTY -1
#define SLOT_LANDING -2
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

	int getW() const { return width; }
	int getH() const { return height; }
   int& operator()(const int& posx, const int& posy);
   bool isEmpty(Zone& z);
   Zone findEmptyZone(const int& width,const int& height);
   bool build(const Zone& z);
};

std::ostream& operator<<(std::ostream& os, Field& field);