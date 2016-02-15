#include "Field.h"

Field::Field(const int& dim_x, const int& dim_y, const Slot& s)
{
   dimentions[0] = dim_x;
   dimentions[1] = dim_y;
   slots.reset(new std::list<Slot>(dimentions[0] * dimentions[1]));
}

Field::~Field()
{
   if (slots)
      slots->clear();
}

int& Field::operator()(const int& posx, const int& posy)
{
   return &((*slots)[(*slots).begin + posy * dimentions[1] + posx]);
}
