#include "Zone.h"

Zone::Zone()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	id = ZONE_ID_UNDEFINED;
}

Zone::Zone(const int& x, const int& y, const int& width, const int& height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Zone::Zone(const int& x, const int& y, const int& width, const int& height, const int& id)
{
   this->x = x;
   this->y = y;
   this->width = width;
   this->height = height;
   this->id = id;
}

Zone::~Zone()
{

}

bool Zone::isEmpty()
{
   if (width == 0 || height == 0)
   {
      return true;
   }
   return false;
}