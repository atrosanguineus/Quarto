#ifndef MODULI_BASEMENU_H_
#define MODULI_BASEMENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <windows.h>
#include <string.h>

#include "../Vettori/BaseVettori.h"
#include "../Stringhe/OperazioniStringhe.h"
#include "../Punti/BasePunti.h"
#include "OperazioniFile.h"

typedef struct
{
	SVector nomi;
	void (**funzioni)();
}Entrate;

typedef struct
{
	Entrate lista;
	Point puntoPartenza;
	int posizione;
	char* selettore;
	int elementi;
	int wrappato;
	Vector attribSeletto;
	Vector attribResto;
}Menu;

Entrate creaEntrate( SVector nomi, void (**funzioni)() );
SVector getNomi( Entrate lista );
void (**getFunzioni(Entrate lista))();
void setNomi( Entrate* lista, SVector nomi );
void setFunzioni( Entrate* lista, void (**funzioni)() );

void attivaAttributi(Vector vettore);
void disattivaAttributi(Vector vettore);

void chiamaFunzione(Entrate lista, int n);
void refreshMenu(Menu menu);
int gestisciInputMenu(Menu* menu, int input);
void prendiControllo(Menu* menu);
void printaNSpazi(int n);

void printaFileCRS(FILE *file);

Menu creaMenu( Entrate lista, Point puntoPartenza, int posizione, char* selettore, int wrappato, Vector attribSeletto, Vector attribResto );
void setPosizione(Menu* menu, int valore);
Entrate getLista(Menu menu);
Point getPunto(Menu menu);
int getPosizione(Menu menu);
char* getSelettore(Menu menu);
int getElementi(Menu menu);
int isWrappato(Menu menu);
Vector getAttribSeletto(Menu menu);
Vector getAttribResto(Menu menu);

#endif /* MODULI_BASEMENU_H_ */
