#include "OperazioniMatrici.h"

void riempiRandomMatrice(Matrix *matrice, int minVal, int maxVal)
{
	int tempRand = 0;
	int i = 0;
	while( i < getYMatrice(*matrice) )
	{
		int j = 0;
		while( j < getXMatrice(*matrice) )
		{
			tempRand = rand() % (maxVal - minVal + 1)  + minVal;
			scriviMatrice(matrice, i, j, tempRand);

			j = j + 1;
		}

		i = i + 1;
	}
}
int sommaColonna(Matrix matrice, int colonna)
{
	int somma = 0;
	int i = 0;
	while( i < getYMatrice(matrice) )
	{
		somma = somma + leggiMatrice(matrice, i, colonna);

		i = i + 1;
	}
	return somma;
}
int sommaRiga(Matrix matrice, int riga)
{
	int somma = 0;
	int i = 0;
	while( i < getXMatrice(matrice) )
	{
		somma = somma + leggiMatrice(matrice, riga, i);

		i = i + 1;
	}
	return somma;
}
int sommaDiagonale(Matrix matrice, int diagonale)
{
	int somma = 0;

	if( !diagonale )
	{
		int i = 0;
		while( i < getXMatrice(matrice) )
		{
			somma = somma + leggiMatrice(matrice, i, i);

			i = i + 1;
		}
		return somma;
	}
	else if( diagonale )
	{
		int i = 0;
		int j = getXMatrice(matrice) - 1;
		while( i < getYMatrice(matrice) )
		{
			somma = somma + leggiMatrice(matrice, i, j);

			i = i + 1;
			j = j - 1;
		}
		return somma;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void fillBlank(CMatrix* matrice)
{
	int i = 0;
	while( i < getYCMatrice(*matrice) )
	{
		int j = 0;
		while( j < getXCMatrice(*matrice) )
		{
			scriviCMatrice(matrice, i, j, ' ');
			j = j + 1;
		}

		i = i + 1;
	}
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void scambiaColonna(Matrix *matrice, int colonna1, int colonna2)
{
	int c;
	colonna1 = colonna1 - 1;
	colonna2 = colonna2 - 1;

	int i = 0;
	while( i < getYMatrice(*matrice) )
	{
		c = leggiMatrice(*matrice, i, colonna1);
		scriviMatrice(matrice, i, colonna1, leggiMatrice(*matrice, i, colonna2) );
		scriviMatrice(matrice, i, colonna2, c);

		i = i + 1;
	}
}

void scambiaRiga(Matrix *matrice, int riga1, int riga2)
{
	int c;
	riga1 = riga1 - 1;
	riga2 = riga2 - 1;

	int i = 0;
	while( i < getXMatrice(*matrice) )
	{
		c = leggiMatrice(*matrice, riga1, i);
		scriviMatrice(matrice, riga1, i, leggiMatrice(*matrice, riga2, i) );
		scriviMatrice(matrice, riga2, i, c);

		i = i + 1;
	}
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

Matrix copiaMatrice(Matrix from)
{
	int y = getYMatrice(from);
	int x = getXMatrice(from);
	Matrix mat = creaMatrice(y,x);

	int i = 0;
	while( i < y )
	{
		int j = 0;
		while( j < x )
		{
			scriviMatrice(&mat, i, j, leggiMatrice(from, i, j));
			j = j + 1;
		}
		i = i + 1;
	}

	return mat;
}

Matrix sommaMatrici(Matrix matrice1, Matrix matrice2)
{
	Matrix matriceSO = creaMatrice( getYMatrice(matrice1), getXMatrice(matrice1) );

	int somma = 0;
	int i = 0;
	while( i < getYMatrice(matrice1) )
	{
		int j = 0;
		while( j < getXMatrice(matrice1) )
		{
			somma = leggiMatrice(matrice1, i, j) + leggiMatrice(matrice2, i, j);
			scriviMatrice(&matriceSO, i, j, somma);

			j = j + 1;
		}
		i = i + 1;
	}

	return matriceSO;
}
Matrix scalareMatrice(Matrix matrice1, int scalare)
{
	Matrix matriceSCO = creaMatrice( getYMatrice(matrice1), getXMatrice(matrice1) );

	int i = 0;
	while( i < getYMatrice(matrice1) )
	{
		int j = 0;
		while( j < getXMatrice(matrice1) )
		{
			int temp = scalare * leggiMatrice(matrice1, i, j);
			scriviMatrice(&matriceSCO, i, j, temp);

			j = j + 1;
		}

		i = i + 1;
	}

	return matriceSCO;
}
Matrix trasposizioneMatrice(Matrix matrice1)
{
	Matrix matriceTO = creaMatrice( getXMatrice(matrice1), getYMatrice(matrice1) );

	int i = 0;
	while( i < getYMatrice(matrice1) )
	{
		int j = 0;
		while( j < getXMatrice(matrice1) )
		{
			int temp = leggiMatrice(matrice1, i, j);
			scriviMatrice(&matriceTO, j, i, temp);

			j = j + 1;
		}

		i = i + 1;
	}

	return matriceTO;
}
Matrix prodottoMatrici(Matrix matrice1, Matrix matrice2)
{
	//TODO
	Matrix temp;
	return temp;
}
