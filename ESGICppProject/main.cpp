#include "Field.h"
#include <iostream>

#include "Field.h"
#include "Zone.h"
#include <stdlib.h>

int main()
{
   Field field(5, 5);
   std::cin >> field;
   std::cout << field;
   system("pause");
}