#pragma once

enum Case
{
	Case_Empty,
	Case_Building,
	Case_Landing,
	Case_Unreachable
};

class Field
{
protected:
	int dimentions[2];
	Case cases[];

public:
	Field(int dimx, int dimy);
	virtual ~Field();

	int GetWidth() { return dimentions[0]; }
	int GetHeith() { return dimentions[1]; }

	int operator()(int posx, int posy);

};