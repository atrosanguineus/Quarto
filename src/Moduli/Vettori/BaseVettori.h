#ifndef BASEVETTORI_H_
#define BASEVETTORI_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct
{
	int x;
	int *valori;
}Vector;

typedef struct
{
	int x;
	float *valori;
}FVector;

typedef struct
{
	int x;
	char **valori;
}SVector;

Vector creaVettore(int x);
void setXVettore(Vector *vettore, int valore);
int getXVettore(Vector vettore);
void liberaVettore(Vector *vettore);
int leggiVettore(Vector vettore, int x);
void scriviVettore(Vector *vettore, int x, int valore);
void printaVettore(Vector vettore, int spaziTraElementi);

FVector creaFVettore(int x);
void setXFVettore(FVector *vettore, int valore);
int getXFVettore(FVector vettore);
void liberaFVettore(FVector *vettore);
float leggiFVettore(FVector vettore, int x);
void scriviFVettore(FVector *vettore, int x, float valore);
void printaFVettore(FVector vettore, int spaziTraElementi);

SVector creaSVettore(int x);
void setXSVettore(SVector *vettore, int valore);
int getXSVettore(SVector vettore);
void liberaSVettore(SVector *vettore);
char* leggiSVettore(SVector vettore, int x);
void scriviSVettore(SVector *vettore, int x, char* valore);
void printaSVettore(SVector vettore, char* stringaTraElementi);

#endif /* BASEVETTORI_H_ */
