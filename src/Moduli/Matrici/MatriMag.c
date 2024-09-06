#include "MatriMag.h"

void genioCella(Matrix matrice)
{
	if( getXMatrice(matrice) == 1 )
	{
		printf("\nGenio! Una sola cella e' sempre magica!\n");
		system("PAUSE");
		exit(0);
	}
}
void magiaColonne(Matrix matrice, int obiettivoMagico)
{
	int i = 1;
	do
	{
		if( obiettivoMagico != sommaColonna(matrice, i) )
		{
			printf("\nLa matrice non e' magica! \n");
			system("PAUSE");
			exit(0);
		}

		i = i + 1;

	}
	while( i < getXMatrice(matrice) );
}
void magiaRighe(Matrix matrice, int obiettivoMagico)
{
	int i = 0;
	do
	{
		if( obiettivoMagico != sommaRiga(matrice, i) )
		{
			printf("\nLa matrice non e' magica! \n");
			system("PAUSE");
			exit(0);
		}

		i = i + 1;

	}while( i < getYMatrice(matrice) );
}
void magiaDiagonale(Matrix matrice, int obiettivoMagico)
{
	if( obiettivoMagico == sommaDiagonale(matrice, 0) )
	{
		if(obiettivoMagico != sommaDiagonale(matrice, 1) )
		{
			printf("\nLa matrice non e' magica! \n");
			system("PAUSE");
			exit(0);
		}
	}
	else
	{
		printf("\nLa matrice non e' magica! \n");
		system("PAUSE");
		exit(0);
	}
}
