#include "Field.h"
#include <iostream>

#include "Field.h"

int main()
{
   Field field(5, 5);
   field(4, 4) = 2;
   std::cout << field;
   std::cin.get();
}