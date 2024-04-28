#include "romanos.hpp"
int romanos_para_decimal(char const *num_romano)
{
  if (num_romano[0] == 'I')
  {
    return 1;
  }
  else if (num_romano[0] == 'V')
  {
    return 5;
  }
  else if (num_romano[0] == 'X')
  {
    return 10;
  }
  else if (num_romano[0] == 'L')
  {
    return 50;
  }

  else if (num_romano[0] == 'C')
    return 100;

  else if (num_romano[0] == 'D')
    return 500;
    
  else if (num_romano[0] == 'M')
    return 1000;

  return -1;
}
