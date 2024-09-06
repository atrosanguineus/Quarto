#ifndef UTILITY_H_
#define UTILITY_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <curses.h>

int acquisisciNumero(char* messaggio, int valoreMinimo, int valoreMassimo);
int acquisisciSeStesseCifre(int obiettivo);
void acquisisciIntervallo(int *valMin, int *valMax);
int sceltaYN(char* messaggio);
int numCifre(int numero);

#endif /* UTILITY_H_ */
