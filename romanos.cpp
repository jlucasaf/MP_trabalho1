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

  int equalsChars = 1;
  char previousChar = '\0';
  char currentChar = '\0';

  while ((currentChar = num_romano[index++]) != '\0')
  {
    // verificacao se algarismo esta na tabela de valores
    if (algarismoEhInvalido(currentChar))
      return -1;

    if (repeticaoEhInvalida(currentChar, previousChar, equalsChars))
      return -1;

    if (num_romano[index] != '\0' && !algarismoEhInvalido(num_romano[index]))
    {

      if (valores_romanos[currentChar] < valores_romanos[num_romano[index]])
        resultado -= valores_romanos[currentChar];
      else
        resultado += valores_romanos[currentChar];
    }
    else
    {
      resultado += valores_romanos[currentChar];
    }

    previousChar = currentChar;
  }
  return resultado;
}

bool algarismoEhInvalido(char num_romano)
{
  return valores_romanos.find(num_romano) == valores_romanos.end();
}

bool repeticaoEhInvalida(char currentChar, char previousChar, int &equalsChars)
{
  if (currentChar == previousChar)
  {
    equalsChars++;
    // Verifica se 'V', 'L', ou 'D' estão sendo repetidos
    if ((currentChar == 'V' || currentChar == 'L' || currentChar == 'D'))
    {

      // Repetição inválida encontrada
      equalsChars = 0;
      return true;
    }
    else if (equalsChars >= 3)
    {

      equalsChars = 0;
      return true;
    }
  }
  else
  {

    equalsChars = 0;
  }
  return false;
}
