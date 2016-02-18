#include "Zone.h"

Zone::Zone(const int& x, const int& y, const int& width, const int& height)
{
   this->x = x;
   this->y = y;
   this->width = width;
   this->height = height;
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