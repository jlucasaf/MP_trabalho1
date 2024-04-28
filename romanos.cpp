#include "romanos.hpp"
#include <map>

int romanos_para_decimal(char const *num_romano)
{
  std::map<char, int> valores_romanos = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}};

  // verificacao se algarismo esta na tabela de valores
  if (valores_romanos.find(num_romano[0]) == valores_romanos.end())
    return -1;

  return valores_romanos[num_romano[0]];
}
