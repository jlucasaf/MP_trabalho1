#include "romanos.hpp"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

map<char, int> valores_romanos = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};

// Lista de subtrações válidas
vector<string> valid_subtractions = {
    "IV", "IX", "XL", "XC", "CD", "CM"};

int romanos_para_decimal(char const *num_romano)
{
  int resultado = 0;
  int index = 0;

  int equalsChars = 1;
  char previousChar = '\0';
  char currentChar = '\0';
  char nextChar = '\0';
  try
  {
    while ((currentChar = num_romano[index++]) != '\0')
    {
      nextChar = num_romano[index];

      // verificacao se algarismo esta na tabela de valores
      if (algarismoEhInvalido(currentChar))
        return -1;

      if (repeticaoEhInvalida(currentChar, previousChar, equalsChars))
        return -1;

      if (!proxEhFimDaString(nextChar) && !proxAlgarismoEhInvalido(nextChar))
      {
        resultado += calculaResultadoParcial(currentChar, nextChar);
      }
      else
      {

        resultado += valores_romanos[currentChar];
      }
      previousChar = currentChar;
    }
    return resultado;
  }
  catch (...)
  {
    return -1;
  }
}

int calculaResultadoParcial(char currentChar, char nextChar)
{
  if (proxEhMaior(currentChar, nextChar))
  {
    if (subtracaoEhInvalida(currentChar, nextChar))
      throw runtime_error("Subtracao invalida.");
    return (valores_romanos[currentChar] * (-1));
  }
  else
    return valores_romanos[currentChar];
}

bool subtracaoEhInvalida(char currentChar, char nextChar)
{
  // Verifique se a subtração é válida
  string subtracao = string(1, currentChar) + nextChar;
  for (const string &valid_sub : valid_subtractions)
  {
    if (subtracao == valid_sub)
    {
      return false;
    }
  }
  return true;
}

bool proxEhMaior(char current, char next)
{
  return valores_romanos[current] < valores_romanos[next];
}

bool proxEhFimDaString(char nextChar)
{
  return fimDaString(nextChar);
}

bool fimDaString(char current)
{
  return current == '\0';
}

bool proxAlgarismoEhInvalido(char nextChar)
{
  return algarismoEhInvalido(nextChar);
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
