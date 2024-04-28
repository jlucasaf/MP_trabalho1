#include "romanos.hpp"
#include <map>

std::map<char, int> valores_romanos = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};

int romanos_para_decimal(char const *num_romano)
{
  int resultado = 0;
  int index = 0;

  while (num_romano[index++] != '\0')
  {
    // verificacao se algarismo esta na tabela de valores
    if (algarismoEhValido(num_romano))
      return -1;
    resultado += valores_romanos[num_romano[0]];
  }
    return resultado;
}

bool algarismoEhValido(char const *num_romano)
{
  return valores_romanos.find(num_romano[0]) == valores_romanos.end();
}
