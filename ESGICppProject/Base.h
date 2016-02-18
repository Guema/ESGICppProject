#pragma once
#include <string>
#include <iostream>
#include <math.h>
using namespace::std;

class Base
{
public:
	Base();
	Base(Base& ba);
	void Add(Building build, int x, int y);
	~Base();

private:
	int **base;
	int gold;
	const static int taille = 20;

};