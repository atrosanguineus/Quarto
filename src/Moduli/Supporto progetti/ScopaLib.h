#ifndef MODULI_SUPPORTO_PROGETTI_SCOPALIB_H_
#define MODULI_SUPPORTO_PROGETTI_SCOPALIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "../Punti/BasePunti.h"
#include "../Matrici/BaseMatrici.h"
#include "../Matrici/OperazioniMatrici.h"

#define CARD_HEIGHT 6
#define CARD_WIDTH 7

/* 	         _____
	        |K  WW|
	        |   {)|
	        | S °▒|
	        | |▒▒▒|
	        |_▒▒▒▒|
 */

typedef struct
{
	char seme;
	int valore;
	Point coordinate;
	CMatrix baseCard;
	CMatrix insideCard;
}Carta;

Carta creaCarta(char seme, int valore);
CMatrix baseCard();
CMatrix buildInside(Carta carta);
void setSeme(Carta* carta, char seme);
void setValore(Carta* carta, int valore);
void setCoordinate(Carta* carta, Point coordinate);
void setBase(Carta* carta, CMatrix aspetto);
void setInside(Carta* carta, CMatrix aspetto);
char getSeme(Carta carta);
int getValore(Carta carta);
Point getCoordinate(Carta carta);
CMatrix getBase(Carta carta);
CMatrix getInside(Carta carta);

//void printaCURSCMatrice(CMatrix matrice, int spaces, int enableSpace);
void visualizzaCarta(Carta carta);
void nascondiCarta(Carta carta);

#endif /* MODULI_SUPPORTO_PROGETTI_SCOPALIB_H_ */
