#pragma once

#include <list>
#include <memory>

typedef int Slot;

#define SLOT_EMPTY -1
#define SLOT_BUILDING -2
#define SLOT_UNREACHABLE -4
#define SLOT_BUILDING 1

class Field
{
protected:
	int dimentions[2];
   std::unique_ptr<std::list<Slot> > slots;

public:
   Field(const int& dim_x,const int& dim_y, const Slot& s = SLOT_EMPTY);
	virtual ~Field();

	int GetWidth() { return dimentions[0]; }
	int GetHeith() { return dimentions[1]; }

	int& operator()(const int& posx, const int& posy);
};