
#ifndef ROMANOS_H_
#define ROMANOS_H_

int romanos_para_decimal(char const *num_romano);
bool algarismoEhInvalido(char num_romano);
bool repeticaoEhInvalida(char currentChar, char previousChar, int &equalsChars);
bool fimDaString(char currentChar);
bool proxEhMaior(char current, char next);
bool proxAlgarismoEhInvalido(char nextChar);
int calculaResultadoParcial(char currentChar, char nextChar);
bool proxEhFimDaString(char nextChar);
bool subtracaoEhInvalida(char currentChar, char nextChar);

#endif  // ROMANOS_H_