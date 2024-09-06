#include "OperazioniVettori.h"

int occorrenzeInVettore(Vector vettore, int valore)
{
	int occorrenze = 0;

	int i = 0;
	while( i < getXVettore(vettore) )
	{
		if( valore == leggiVettore(vettore, i) )
			occorrenze = occorrenze + 1;

		i = i + 1;
	}

	return occorrenze;
}
int presenteInVettore(Vector vettore, int valore)
{
	int i = 0;
	while( i < getXVettore(vettore) )
	{
		if(valore == leggiVettore(vettore, i))
		{
			return 1;
		}
		i = i + 1;
	}
	return 0;
}
int presenteInVettorePOS(Vector vettore, int valore, int *pos)
{
	int i = 0;
	while( i < getXVettore(vettore) )
	{
		if(valore == leggiVettore(vettore, i))
		{
			*pos = i;
			return 1;
		}
		i = i + 1;
	}
	return 0;
}
void vettoreScriviPrimaOccorrenza(Vector vettore, int valore, int daScrivere)
{
	int i = 0;
	while( i < getXVettore(vettore) )
	{
		if(valore == leggiVettore(vettore, i))
		{
			scriviVettore(&vettore, i, daScrivere);
			return ;
		}
		i = i + 1;
	}
	return ;
}
int minoreDiInVettore(Vector vettore, int limite)
{
	int i = 0;
	while( i < getXVettore(vettore) )
	{
		if(leggiVettore(vettore, i) < limite)
		{
			return 1;
		}
		i = i + 1;
	}
	return 0;
}
int maggioreDiInVettore(Vector vettore, int limite)
{
	int i = 0;
	while( i < getXVettore(vettore) )
	{
		if(leggiVettore(vettore, i) > limite)
		{
			return 1;
		}
		i = i + 1;
	}
	return 0;
}
int minInVettore(Vector vettore)
{
	int valoreMin = leggiVettore(vettore, 0);
	int prossimoElemento;

	int i = 1;
	while( i < getXVettore(vettore) )
	{
		prossimoElemento = leggiVettore(vettore, i);

		if(valoreMin > prossimoElemento)
			valoreMin = prossimoElemento;

		i = i + 1;
	}
	return valoreMin;
}
int maxInVettore(Vector vettore)
{
	int valoreMax = leggiVettore(vettore, 0);
	int prossimoElemento;

	int i = 1;
	while( i < getXVettore(vettore) )
	{
		prossimoElemento = leggiVettore(vettore, i);

		if(valoreMax < prossimoElemento)
			valoreMax = prossimoElemento;

		i = i + 1;
	}
	return valoreMax;
}
int sonoUguali(Vector vettore1, Vector vettore2)
{
	if( getXVettore(vettore1) != getXVettore(vettore2) )
		return 0;

	int limite = getXVettore(vettore1);
	int i = 0;
	while( i < limite )
	{
		if( !(leggiVettore(vettore1, i) == leggiVettore(vettore2, i)) )
			return 0;

		i = i + 1;
	}
	return 1;
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
Vector interoToVettore(int numero)
{
	int cifreNumero = 0;
	if (numero < 0) numero = -numero;
	else if (numero <         10) cifreNumero = 1;
	else if (numero <        100) cifreNumero = 2;
	else if (numero <       1000) cifreNumero = 3;
	else if (numero <      10000) cifreNumero = 4;
	else if (numero <     100000) cifreNumero = 5;
	else if (numero <    1000000) cifreNumero = 6;
	else if (numero <   10000000) cifreNumero = 7;
	else if (numero <  100000000) cifreNumero = 8;
	else if (numero < 1000000000) cifreNumero = 9;
	else cifreNumero = 10;

	Vector temp = creaVettore(cifreNumero);

	int i = cifreNumero - 1;
	while(i > -1)
	{
	    scriviVettore(&temp, i, numero % 10);
	    numero = numero / 10;

	    i = i - 1;
	}

	return temp;
}
Vector stringToVettore(char *stringa)
{
	Vector temp = creaVettore(strlen(stringa));

	int i = 0;
	while( i < strlen(stringa) )
	{
		scriviVettore(&temp, i, stringa[i] - '0');

		i = i + 1;
	}
	return temp;
}
Vector copiaVettore(Vector vettore)
{
	Vector temp = creaVettore(getXVettore(vettore));

	int i = 0;
	while( i < getXVettore(vettore) )
	{
		scriviVettore(&temp, i, leggiVettore(vettore, i));
		i = i + 1;
	}
	return temp;
}

char* vettoreToString(Vector vettore)
{
	char* daRitornare = calloc(256, sizeof(char));

	int i = 0;
	while( i < getXVettore(vettore) )
	{
		char* tempString = calloc(3, sizeof(char));
		itoa( leggiVettore(vettore, i), tempString, 10 );
		strcat(daRitornare, tempString);

		i = i + 1;
	}
	daRitornare[strlen(daRitornare)] = '\0';

	return daRitornare;
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void scambioInVettore(Vector *vettore, int pos1, int pos2)
{
	int c;

	c = leggiVettore(*vettore, pos1);
	scriviVettore(vettore, pos1, leggiVettore(*vettore, pos2) );
	scriviVettore(vettore, pos2, c);
}

Vector sottoVettore(Vector vettore, int limiteMin, int limiteMax)
{
	Vector daRitornare = creaVettore(limiteMax - limiteMin);
	int k = 0;

	int i = limiteMin;
	while( i < limiteMax )
	{
		scriviVettore(&daRitornare, k, leggiVettore(vettore, i) );

		k = k + 1;
		i = i + 1;
	}

	return daRitornare;
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void riempiManualeVettore(Vector *vettore)
{
	int i = 0;
	int scan = 0;
	while( i < getXVettore(*vettore) )
	{
		printf("Inserire il %do valore: ", i + 1);
		scanf("%d", &scan);
		scriviVettore(vettore, i, scan);

		i = i + 1;
	}
}
void riempiRandVettore(Vector *vettore, int minVal, int maxVal)
{
	int i = 0;
	while( i < getXVettore(*vettore) )
	{
		int tempRand = rand() % (maxVal - minVal + 1)  + minVal;
		scriviVettore(vettore, i, tempRand);

		i = i + 1;
	}
}
void riempiRandVettoreNoDup(Vector *vettore, int minVal, int maxVal)
{
	Vector usati = creaVettore( getXVettore(*vettore) );
	int tempRand;

	int i = 0;
	while( i < getXVettore(*vettore) )
	{
		tempRand = rand() % (maxVal - minVal + 1)  + minVal;
		while( presenteInVettore(usati, tempRand) )
		{
			tempRand = rand() % (maxVal - minVal + 1)  + minVal;
		}

		scriviVettore(&usati, i, tempRand);
		scriviVettore(vettore, i, tempRand);

		i = i + 1;
	}
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
Vector ordinaNumeri(Vector vettore, int decrescente)
{
	Vector temp;
	return temp;
}
