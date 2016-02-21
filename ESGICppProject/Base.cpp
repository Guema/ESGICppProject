#include "Base.h"

Base::Base(int gold)
{
	field = new Field(FIELD_SIZE, FIELD_SIZE, TILE_EMPTY);
	this->gold = gold;
}

Base::Base(Field &f, int gold)
{
	*field = f;
	this->gold = gold;
}