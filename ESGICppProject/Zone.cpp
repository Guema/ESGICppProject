#include "Zone.h"

Zone::Zone(const int& x, const int& y)
{
   this->x = x;
   this->y = y;
   width = height = 0;
   id = ZONE_ID_UNDEFINED;
}

Zone::~Zone()
{

}

bool Zone::isEmpty()
{
   if (ZONE_ID_UNDEFINED == id)
   {
      return true;
   }
   return false;
}