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
   static const Zone zero;
   Zone(const int& x = 0, 
        const int& y = 0,
        const int& width = 0,
        const int& height = 0);
   virtual ~Zone();
   
   void setX(int x){ this->x = x; }
   void setY(int y){ this->y = y; }
   void setW(int width){ this->width = width; }
   void setH(int height){ this->height = height; }
   void setId(int id){ this->id = id; }
   int getX(){ return x; }
   int getY(){ return y; }
   int getW(){ return width; }
   int getH(){ return height; }
   int getId() { return id; }
   bool isEmpty();
};

const Zone Zone::zero = Zone(0, 0, 0, 0);