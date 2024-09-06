#include "Utility.h"

int acquisisciNumero(char* messaggio, int valoreMinimo, int valoreMassimo)
{
	printf(messaggio);

	int x;
	do
	{
		scanf("%d", &x);

		if( x < valoreMinimo || x > valoreMassimo )
		{
			printf("Hai un range tra %d e %d! Riprovare: ", valoreMinimo, valoreMassimo);
		}
	}
	while( x < valoreMinimo || x > valoreMassimo );

	return x;
}
int acquisisciSeStesseCifre(int obiettivoCifre)
{
	int numero;

	do
	{
		scanf("%d", &numero);

		if( numCifre(numero) != obiettivoCifre )
		{
			printf("Inserire stesse cifre! ");
		}
		else
			return numero;
	}
	while( numCifre(numero) != obiettivoCifre );
	return 0;
}
void acquisisciIntervallo(int *valMin, int *valMax)
{
	int minVal;
	int maxVal;

	printf("Valore minimo dell'intervallo: ");
	scanf("%d", &minVal);
	do
	{

		printf("Valore massimo dell'intervallo: ");
		scanf("%d", &maxVal);

		if( maxVal <= minVal )
		{
			printf("No, questo non te lo posso lasciar fare. ");
		}
	}
	while( maxVal <= minVal );

	*valMin = minVal;
	*valMax = maxVal;
}
int sceltaYN(char* messaggio)
{
	printf(messaggio);

	int c;
	do
	{
		c = getch();

	}
	while( (char) c != 'y' && (char) c!= 'n' && (char) c != 'Y' && (char) c != 'N' && c != 27);

	if((char) c == 'y' || (char) c == 'Y')
		return 1;
	else
		return 0;
}
int numCifre(int numero)
{
  if (numero < 0) numero = -numero;
  if (numero <         10) return 1;
  if (numero <        100) return 2;
  if (numero <       1000) return 3;
  if (numero <      10000) return 4;
  if (numero <     100000) return 5;
  if (numero <    1000000) return 6;
  if (numero <   10000000) return 7;
  if (numero <  100000000) return 8;
  if (numero < 1000000000) return 9;
  return 10;
}

