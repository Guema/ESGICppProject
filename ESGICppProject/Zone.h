#pragma once

#define ZONE_ID_UNDEFINED -1
#define ZONE_ID_BUILDING_NAME1 1
#define ZONE_ID_BUILDING_NAME2 2
#define ZONE_ID_BUILDING_NAME3 3

class Zone
{
protected:
   int id;
   int x;
   int y;
   int width;
   int height;

public:
   Zone(const int& x = 0, const int& y = 0);
   virtual ~Zone();

   int getX(){ return x; }
   int getY(){ return y; }
   int getW(){ return width; }
   int getH(){ return height; }
   bool isEmpty();
};
