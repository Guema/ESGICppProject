#pragma once

typedef int Case;

#define CASE_EMPTY -1
#define CASE_BUILDING -2
#define CASE_UNREACHABLE -4


class Field
{
protected:
	int dimentions[2];


public:
	Field(int dim_x, int dim_y);
	virtual ~Field();

	int GetWidth() { return dimentions[0]; }
	int GetHeith() { return dimentions[1]; }

	int operator()(int posx, int posy);

};