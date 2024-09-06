
#include "BaseMatrici.h"

Matrix creaMatrice(int y, int x)
{
	Matrix temp;

	temp.valori = calloc(y, sizeof( *temp.valori ));
	if( !temp.valori )
	{
		printf("Memoria non allocata.\n");
		system("PAUSE");
	}

	int i = 0;
	while(i < y)
	{
		temp.valori[i] = calloc(x, sizeof(**temp.valori));
		if( !temp.valori[i] )
		{
			printf("Memoria non allocata.\n");
			system("PAUSE");
		}
		i = i + 1;
	}
	setYMatrice(&temp, y);
	setXMatrice(&temp, x);

	return temp;
}
void setYMatrice(Matrix *matrice, int valore)
{
	matrice->y = valore;
}
void setXMatrice(Matrix *matrice, int valore)
{
	matrice->x = valore;
}
int getYMatrice(Matrix matrice)
{
	return matrice.y;
}
int getXMatrice(Matrix matrice)
{
	return matrice.x;
}
void liberaMatrice(Matrix *matrice)
{
	int i = 0;
	while( i < getXMatrice(*matrice) )
	{
		 free( matrice->valori[i] );

		 i = i + 1;
	}
	free( matrice->valori );
}
int leggiMatrice(Matrix matrice, int y, int x)
{
	return matrice.valori[y][x];
}
void scriviMatrice(Matrix *matrice, int y, int x, int valore)
{
	matrice->valori[y][x] = valore;
}
void printaMatrice(Matrix matrice, int spaces)
{
	int i = 0;
	while(i < getYMatrice(matrice) )
	{
		int j = 0;
		while( j < getXMatrice(matrice) )
		{
			printf("%d", leggiMatrice(matrice, i, j));

			int k = 0;
			while( k < spaces )
			{
				printf(" ");
				k = k + 1;
			}

			j = j + 1;
		}
		printf("\n");
		i = i + 1;
	}
}

void printaCURSMatrice(Matrix matrice, int spaces)
{
	int i = 0;
	while(i < getYMatrice(matrice) )
	{
		int j = 0;
		while( j < getXMatrice(matrice) )
		{
			printw("%d", leggiMatrice(matrice, i, j));

			int k = 0;
			while( k < spaces )
			{
				printw(" ");
				k = k + 1;
			}

			j = j + 1;
		}
		printw("\n");
		i = i + 1;
	}
}

////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

FMatrix creaFMatrice(int y, int x)
{
	FMatrix temp;

	temp.valori = calloc(y, sizeof( *temp.valori ));
	if( !temp.valori )
	{
		printf("Memoria non allocata.\n");
		system("PAUSE");
	}

	int i = 0;
	while(i < y)
	{
		temp.valori[i] = calloc(x, sizeof(**temp.valori));
		if( !temp.valori[i] )
		{
			printf("Memoria non allocata.\n");
			system("PAUSE");
		}
		i = i + 1;
	}
	setYFMatrice(&temp, y);
	setXFMatrice(&temp, x);

	return temp;
}
void setYFMatrice(FMatrix *matrice, int valore)
{
	matrice->y = valore;
}
void setXFMatrice(FMatrix *matrice, int valore)
{
	matrice->x = valore;
}
int getYFMatrice(FMatrix matrice)
{
	return matrice.y;
}
int getXFMatrice(FMatrix matrice)
{
	return matrice.x;
}
void liberaFMatrice(FMatrix *matrice)
{
	int i = 0;
	while( i < getXFMatrice(*matrice) )
	{
		 free( matrice->valori[i] );

		 i = i + 1;
	}
	free( matrice->valori );
}
float leggiFMatrice(FMatrix matrice, int y, int x)
{
	return matrice.valori[y][x];
}
void scriviFMatrice(FMatrix *matrice, int y, int x, float valore)
{
	matrice->valori[y][x] = valore;
}
void printaFMatrice(FMatrix matrice, int spaces)
{
	int i = 0;
	while(i < getYFMatrice(matrice) )
	{
		int j = 0;
		while( j < getXFMatrice(matrice) )
		{
			printf("%f", leggiFMatrice(matrice, i, j));

			int k = 0;
			while( k < spaces )
			{
				printf(" ");
				k = k + 1;
			}


			j = j + 1;
		}
		printf("\n");
		i = i + 1;
	}
}

void printaCURSFMatrice(FMatrix matrice, int spaces)
{
	int i = 0;
	while(i < getYFMatrice(matrice) )
	{
		int j = 0;
		while( j < getXFMatrice(matrice) )
		{
			printw("%f", leggiFMatrice(matrice, i, j));

			int k = 0;
			while( k < spaces )
			{
				printw(" ");
				k = k + 1;
			}


			j = j + 1;
		}
		printw("\n");
		i = i + 1;
	}
}

////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

CMatrix creaCMatrice(int y, int x)
{
	CMatrix temp;

	temp.valori = calloc(y, sizeof( *temp.valori ));
	if( !temp.valori )
	{
		printf("Memoria non allocata.\n");
		system("PAUSE");
	}

	int i = 0;
	while(i < y)
	{
		temp.valori[i] = calloc(x, sizeof(**temp.valori));
		if( !temp.valori[i] )
		{
			printf("Memoria non allocata.\n");
			system("PAUSE");
		}
		i = i + 1;
	}
	setYCMatrice(&temp, y);
	setXCMatrice(&temp, x);

	return temp;
}
void setYCMatrice(CMatrix *matrice, int valore)
{
	matrice->y = valore;
}
void setXCMatrice(CMatrix *matrice, int valore)
{
	matrice->x = valore;
}
int getYCMatrice(CMatrix matrice)
{
	return matrice.y;
}
int getXCMatrice(CMatrix matrice)
{
	return matrice.x;
}
void liberaCMatrice(CMatrix *matrice)
{
	int i = 0;
	while( i < getXCMatrice(*matrice) )
	{
		 free( matrice->valori[i] );

		 i = i + 1;
	}
	free( matrice->valori );
}
char leggiCMatrice(CMatrix matrice, int y, int x)
{
	return matrice.valori[y][x];
}
void scriviCMatrice(CMatrix *matrice, int y, int x, char valore)
{
	matrice->valori[y][x] = valore;
}
void printaCMatrice(CMatrix matrice, int spaces)
{
	int i = 0;
	while(i < getYCMatrice(matrice) )
	{
		int j = 0;
		while( j < getXCMatrice(matrice) )
		{
			printf("%c", leggiCMatrice(matrice, i, j));

			int k = 0;
			while( k < spaces )
			{
				printf(" ");
				k = k + 1;
			}


			j = j + 1;
		}
		printf("\n");
		i = i + 1;
	}
}

void printaCURSCMatrice(CMatrix matrice, int spaces, int enableSpace)
{
	int y;
	int x;
	getyx(stdscr, y, x);

	int i = 0;
	while(i < getYCMatrice(matrice) )
	{
		int j = 0;
		while( j < getXCMatrice(matrice) )
		{
			char tempCh = leggiCMatrice(matrice, i, j);
			if( tempCh != ' ' || (tempCh == ' ' && enableSpace != 0) )
			{
				addch(leggiCMatrice(matrice, i, j));
			}
			else
			{
				int y2;
				int x2;
				getyx(stdscr, y2, x2);
				move(y2, x2 + 1);
			}

			int k = 0;
			while( k < spaces )
			{
				addch(' ');
				k = k + 1;
			}

			j = j + 1;
		}

		i = i + 1;
		y = y + 1;
		move(y, x);
	}
}
