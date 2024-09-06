#ifndef MODULI_OPERAZIONISTRINGHE_H_
#define MODULI_OPERAZIONISTRINGHE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "..\Utility\Utility.h"

void replaceSpazi(char* stringa, char nuovo);
int isSeparatore(char carattere);
int contieneSeparatore(char* stringa);
int stringaContiene(char* stringa, char carattere);
void pulisciStringa(char* stringa);

char* estraiNome(char* stringa, char limite);
char* sottoStringa(char* stringa, int limiteMin, int limiteMax);
int primaOccorrenza(char* stringa, char limite);
char* concatenaStringa(char* str1, char* str2);
void  appendSemicolon(char* str, char* str2);
char* cropToSeparator(char* source, int* pos, char separator);

char* intWithZeroes(int num, int numZeroes);

#endif /* MODULI_OPERAZIONISTRINGHE_H_ */
