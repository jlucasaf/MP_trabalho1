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

  return -1;
}
