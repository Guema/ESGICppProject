#include "Field.h"

const Zone Zone::zero = Zone(0, 0, 0, 0);

Field::Field(const int& dim_x, const int& dim_y, const Tile& s)
{
   width = dim_x;
   height = dim_y;
   slots = std::vector<Tile>(width * height, s);
}

Field::~Field()
{
   slots.clear();
}

int& Field::operator()(const int& posx, const int& posy)
{
   return slots.operator[](posy * width + posx);
}

int Field::getTile(const int& posx, const int& posy) const
{
   return slots.at(posy * width + posx);
}

bool Field::isEmpty(Zone& z) const
{
   int left = z.getX();
   int top = z.getY();
   int right = z.getX() + z.getW();
   int bot = z.getY() + z.getH();
   if (left < 0 || top < 0 || right > width || bot > height)
      return false;
   for (int y = top; y < bot; y++)
   {
      for (int x = left; x < right; x++)
      {
         if (getTile(x, y) != TILE_EMPTY)
            return false;
      }
   }
   return true;
}

Zone Field::findEmptyZone(const int& width, const int& height) const
{
   Zone z(0, 0, width, height);
   for (int y = 0; y < this->height; y++)
   {
      z.setY(y);
      for (int x = 0; x < this->width; x++)
      {
         z.setX(x);
         if (isEmpty(z))
         {
            return z;
         }
      }
   }
   return Zone(0, 0, 0, 0);
}

bool Field::build(Zone& z)
{
   int left = z.getX();
   int top = z.getY();
   int right = z.getX() + z.getW();
   int bot = z.getY() + z.getH();
   if (isEmpty(z))
   {
      for (int y = top; y < bot; y++)
      {
         for (int x = left; x < right; x++)
         {
            this->operator()(x, y) = z.getId();
         }
      }
      return true;
   }
   return false;
}

void Field::erase(Zone& z)
{
   int left = z.getX();
   int top = z.getY();
   int right = z.getX() + z.getW();
   int bot = z.getY() + z.getH();
   if (left < 0 || top < 0 || right > width || bot > height)
      return;
   for (int y = top; y < bot; y++)
   {
      for (int x = left; x < right; x++)
      {
         this->operator()(x, y) = TILE_EMPTY;
      }
   }
}


std::ostream& operator<<(std::ostream& os, Field& field)
{
   os << "W: " << field.getW() << " H: " << field.getH() << std::endl;
   for (int i = 0; i < field.height; i++)
   {
      for (int j = 0; j < field.width; j++)
      {
         os << (field(j, i) > 0 && field(j,i) < 10 ? " " : "")
            << field(j, i)
            << " ";
      }
      os << std::endl;
   }
   return os;
}

std::istream& operator>>(std::istream& is, Field& field)
{
   is >> field.width >> field.height;
   for (int i = 0; i < field.width * field.height; i++)
   {
      is >> field.slots[i];
   }
   return is;
}