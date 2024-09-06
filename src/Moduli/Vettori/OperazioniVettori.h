#ifndef OPERAZIONIVETTORI_H_
#define OPERAZIONIVETTORI_H_

#include <string.h>

#include "BaseVettori.h"

int occorrenzeInVettore(Vector vettore, int valore);
int presenteInVettore(Vector vettore, int valore);
int presenteInVettorePOS(Vector vettore, int valore, int *pos);
void vettoreScriviPrimaOccorrenza(Vector vettore, int valore, int daScrivere);
int minoreDiInVettore(Vector vettore, int limite);
int maggioreDiInVettore(Vector vettore, int limite);
int minInVettore(Vector vettore);
int maxInVettore(Vector vettore);
int sonoUguali(Vector vettore1, Vector vettore2);

Vector interoToVettore(int valore);
Vector stringToVettore(char *stringa);
Vector copiaVettore(Vector vettore);
char* vettoreToString(Vector vettore);

void scambioInVettore(Vector *vettore, int pos1, int pos2);
Vector sottoVettore(Vector vettore, int limiteMin, int limiteMax);

void riempiManualeVettore(Vector *vettore);
void riempiRandVettore(Vector *vettore, int minVal, int maxVal);
void riempiRandVettoreNoDup(Vector *vettore, int minVal, int maxVal);

Vector ordinaNumeri(Vector vettore, int decrescente);

#endif /* OPERAZIONIVETTORI_H_ */
