#ifndef BASEMATRICI_H_
#define BASEMATRICI_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <curses.h>

typedef struct
{
	int y;
	int x;
	int **valori;
}Matrix;

typedef struct
{
	int y;
	int x;
	float **valori;
}FMatrix;

typedef struct
{
	int y;
	int x;
	char **valori;
}CMatrix;

Matrix creaMatrice(int y, int x);
void setYMatrice(Matrix *matrice, int valore);
void setXMatrice(Matrix *matrice, int valore);
int getYMatrice(Matrix matrice);
int getXMatrice(Matrix matrice);
void liberaMatrice(Matrix *matrice);
int leggiMatrice(Matrix matrice, int y, int x);
void scriviMatrice(Matrix *matrice, int y, int x, int valore);
void printaMatrice(Matrix matrice, int spaces);
void printaCURSMatrice(Matrix matrice, int spaces);

FMatrix creaFMatrice(int y, int x);
void setYFMatrice(FMatrix *matrice, int valore);
void setXFMatrice(FMatrix *matrice, int valore);
int getYFMatrice(FMatrix matrice);
int getXFMatrice(FMatrix matrice);
void liberaFMatrice(FMatrix *matrice);
float leggiFMatrice(FMatrix matrice, int y, int x);
void scriviFMatrice(FMatrix *matrice, int y, int x, float valore);
void printaFMatrice(FMatrix matrice, int spaces);
void printaCURSFMatrice(FMatrix matrice, int spaces);

CMatrix creaCMatrice(int y, int x);
void setYCMatrice(CMatrix *matrice, int valore);
void setXCMatrice(CMatrix *matrice, int valore);
int getYCMatrice(CMatrix matrice);
int getXCMatrice(CMatrix matrice);
void liberaCMatrice(CMatrix *matrice);
char leggiCMatrice(CMatrix matrice, int y, int x);
void scriviCMatrice(CMatrix *matrice, int y, int x, char valore);
void printaCMatrice(CMatrix matrice, int spaces);
void printaCURSCMatrice(CMatrix matrice, int spaces, int enableSpace);


#endif /* BASEMATRICI_H_ */
