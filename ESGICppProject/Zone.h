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
   Zone();
   Zone(const int& x,
	   const int& y,
	   const int& width,
	   const int& height);
   Zone(const int& x, 
        const int& y,
        const int& width,
        const int& height,
		const int& id);
   virtual ~Zone();
   
   void setX(int x){ this->x = x; }
   void setY(int y){ this->y = y; }
   void setW(int width){ this->width = width; }
   void setH(int height){ this->height = height; }
   void setId(int id){ this->id = id; }
   int getX() const { return x; }
   int getY() const { return y; }
   int getW() const { return width; }
   int getH() const { return height; }
   int getId() const { return id; }
   bool isEmpty();
};