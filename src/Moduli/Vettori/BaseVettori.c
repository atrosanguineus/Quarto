#include "BaseVettori.h"

Vector creaVettore(int x)
{
	Vector temp;

	setXVettore(&temp, x);
	temp.valori = calloc(x, sizeof( *temp.valori) );
	if( !temp.valori )
	{
		printf("Memoria esaurita. Ops.\n");
		system("PAUSE");
		exit(0);
	}
	return temp;
}
void setXVettore(Vector *vettore, int valore)
{
	vettore->x = valore;
}
int getXVettore(Vector vettore)
{
	return vettore.x;
}
void liberaVettore(Vector *vettore)
{
	free(vettore -> valori);
}
int leggiVettore(Vector vettore, int x)
{
	return *(vettore.valori + x);
}
void scriviVettore(Vector *vettore, int x, int valore)
{
	*(vettore->valori + x) = valore;
}
void printaVettore(Vector vettore, int spaziTraElementi)
{
	int i = 0;
	while( i < getXVettore(vettore) )
	{
		printf("%d", leggiVettore(vettore, i));

		int j = 0;
		while( j < spaziTraElementi)
		{
			printf(" ");
			j = j + 1;
		}

		i = i + 1;
	}
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

FVector creaFVettore(int x)
{
	FVector temp;

	setXFVettore(&temp, x);
	temp.valori = calloc(x, sizeof( *temp.valori) );
	if( !temp.valori )
	{
		printf("Memoria esaurita. Ops.\n");
		system("PAUSE");
	}
	return temp;
}
void setXFVettore(FVector *vettore, int valore)
{
	vettore->x = valore;
}
int getXFVettore(FVector vettore)
{
	return vettore.x;
}
void liberaFVettore(FVector *vettore)
{
	free(vettore -> valori);
}
float leggiFVettore(FVector vettore, int x)
{
	return *(vettore.valori + x);
}
void scriviFVettore(FVector *vettore, int x, float valore)
{
	*(vettore->valori + x) = valore;
}
void printaFVettore(FVector vettore, int spaziTraElementi)
{
	int i = 0;
	while( i < getXFVettore(vettore) )
	{
		printf("%f", leggiFVettore(vettore, i));

		int j = 0;
		while( j < spaziTraElementi)
		{
			printf(" ");
			j = j + 1;
		}

		i = i + 1;
	}
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

SVector creaSVettore(int x)
{
	SVector temp;

	setXSVettore(&temp, x);
	temp.valori = calloc(x, sizeof( *temp.valori) );
	if( !temp.valori )
	{
		printf("Memoria esaurita. Ops.\n");
		system("PAUSE");
		exit(0);
	}
	return temp;
}
void setXSVettore(SVector *vettore, int valore)
{
	vettore->x = valore;
}
int getXSVettore(SVector vettore)
{
	return vettore.x;
}
void liberaSVettore(SVector *vettore)
{
	free(vettore -> valori);
}
char* leggiSVettore(SVector vettore, int x)
{
	return *(vettore.valori + x);
}
void scriviSVettore(SVector *vettore, int x, char* valore)
{
	*(vettore->valori + x) = strdup(valore);
}
void printaSVettore(SVector vettore, char* stringaTraElementi)
{
	int i = 0;
	while( i < getXSVettore(vettore) )
	{
		printf(leggiSVettore(vettore, i));
		printf(stringaTraElementi);

		i = i + 1;
	}
}
