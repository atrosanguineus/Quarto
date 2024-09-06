#include "OperazioniStringhe.h"

void replaceSpazi(char* stringa, char nuovo)
{
	int i = 0;
	while( i < strlen(stringa) )
	{
		if ( isspace( (int) stringa[i]) )
			stringa[i] = nuovo;

		i = i + 1;
	}
}

int isSeparatore(char carattere)
{
	if( carattere == '\\')
		return 1;

	if( carattere == '/')
		return 1;

	if( carattere == ':')
		return 1;

	if( carattere == '*')
		return 1;

	if( carattere == '?')
		return 1;

	if( carattere == '\"')
		return 1;

	if( carattere == '<')
		return 1;

	if( carattere == '>')
		return 1;

	if( carattere == '|')
		return 1;

	if( carattere == '^')
		return 1;

	if( carattere == '[')
		return 1;

	if( carattere ==']')
		return 1;

	if( carattere == '{')
		return 1;

	if( carattere == '}')
		return 1;

	if( carattere == ' ')
		return 1;

	if( carattere == '\t')
		return 1;

	if( carattere == '\n')
		return 1;

	if( (int) carattere == 13)
		return 1;

	if( (int) carattere == 8)
		return 1;

	return 0;
}

int contieneSeparatore(char* stringa)
{
	int i = 0;
	while(i < strlen(stringa) )
	{
		if( isSeparatore(stringa[i]) )
			return 1;

		i = i + 1;
	}
	return 0;
}

int stringaContiene(char* stringa, char carattere)
{
	int i = 0;
	while( i < strlen(stringa) )
	{
		if( stringa[i] == carattere )
			return 1;

		i = i + 1;
	}
	return 0;
}

void pulisciStringa(char* stringa)
{
	int i = 0;
	int lun = strlen(stringa);

	while(i < lun)
	{
		stringa[i] = '\0';
		i = i + 1;
	}
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

char* estraiNome(char* stringa, char limite)
{
	char* nome = calloc(2048, sizeof(char) );

	int lunStringa = strlen(stringa);
	int i = lunStringa;
	int k = 0;

	while( stringa[i] != limite )
		i = i - 1;

	i = i + 1;
	while( i  < lunStringa-1 )
	{
		nome[k] = stringa[i];
		k = k + 1;
		i = i + 1;
	}

	nome[i] = '\0';
	return nome;
}

char* sottoStringa(char* stringa, int limiteMin, int limiteMax)
{
	int lunStrInput = strlen(stringa);
	char* strRitorno = calloc(lunStrInput, sizeof(char) );

	int k = 0;
	int i = limiteMin;
	while( i <= limiteMax )
	{
		strRitorno[k] = stringa[i];
		i = i + 1;
		k = k + 1;
	}
	strRitorno[i] = '\0';
	return strRitorno;
}

int primaOccorrenza(char* stringa, char limite)
{
	int i = 0;
	while( stringa[i] != limite )
		i++;

	return i;
}

char* concatenaStringa(char* str1, char* str2)
{
	char* daRitornare = calloc( 255, sizeof(char) );

	int i = 0;
	while( i < strlen(str1) )
	{
		daRitornare[i] = str1[i];
		i = i + 1;
	}

	int k = 0;
	while( k < strlen(str2) )
	{
		daRitornare[i] = str2[k];
		k = k + 1;
		i = i + 1;
	}

	daRitornare[i] = '\0';
	return daRitornare;
}

void  appendSemicolon(char* str, char* str2)
{
	strcat(str, str2);
	strcat(str, ";");
	strcat(str, "\0");
}

char* cropToSeparator(char* source, int* pos, char separator)
{
	char incomingChar;
	int found = 0;
	int localAug = 0;
	char* cropped = calloc(31, sizeof(char) );

	while( !found )
	{
		incomingChar = source[*pos];
		if( incomingChar != separator )
		{
			cropped[localAug] = incomingChar;
		}
		else
		{
			found = 1;
		}

		*pos = *pos + 1;
		localAug = localAug + 1;
	}

	cropped[localAug] = '\0';
	return cropped;
}

///////////////////////////////////////
//////////////////////////////////////

char* intWithZeroes(int num, int numZeroes)
{
	char* toReturn = malloc(255 * sizeof(char));
	char* numStr = malloc(255 * sizeof(char));
	itoa(num, numStr, 10);

	if( numCifre(num) >= numZeroes )
	{
		itoa(num, toReturn, 10);
		return toReturn;
	}
	else
	{
		int i = 0;
		while( i < numZeroes)
		{
			toReturn[i] = '0';
			i = i + 1;
		}
		toReturn[i] = '\0';

		i = numZeroes - 1;
		int j = strlen(numStr);
		while( j > 0 )
		{
			toReturn[i] = numStr[j-1];
			i = i - 1;
			j = j - 1;
		}

		return toReturn;
	}

}
