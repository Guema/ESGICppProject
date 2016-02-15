#include "Field.h"

Field::Field(const int& dim_x, const int& dim_y, const Slot& s)
{
   width = dim_x;
   height = dim_y;
   slots.reset(new std::vector<Slot>(width * height));
}

Field::~Field()
{
   if (slots)
      slots->clear();
}

int& Field::operator()(const int& posx, const int& posy)
{
   return (*slots)[posy * height + posx];
}

bool Field::isEmpty(const Zone& z)
{
   for (int y = z.getY; y != z.getH; y++)
   {
      for (int x = z.getX; x != z.getW; x++)
      {
         if ((*this)(x, y) != SLOT_EMPTY)
            return false;
      }
   }
   return true;
}

Zone Field::findEmptyZone(const int& width, const int& height)
{

}