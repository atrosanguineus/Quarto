#include "OperazioniFile.h"

char* salvaConData(char* cartella)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	int anno = tm.tm_year + 1900;
	int mese = tm.tm_mon + 1;
	int giorno = tm.tm_mday;
	int ora = tm.tm_hour;
	int minuto = tm.tm_min;
	int secondo = tm.tm_sec;

	int base = 10;
	char* strTemp = malloc( 127 * sizeof(char) );
	char* percorsoFinale = calloc( 1023 , sizeof(char) );
	strcat(percorsoFinale, cartella);

	itoa(anno, strTemp, base);
	strcat(percorsoFinale, strTemp);

	itoa(mese, strTemp, base);
	strcat(percorsoFinale, strTemp);

	itoa(giorno, strTemp, base);
	strcat(percorsoFinale, strTemp);

	itoa(ora, strTemp, base);
	strcat(percorsoFinale, strTemp);

	itoa(minuto, strTemp, base);
	strcat(percorsoFinale, strTemp);

	itoa(secondo, strTemp, base);
	strcat(percorsoFinale, strTemp);

//	printw(percorsoFinale);
//	getch();

	return percorsoFinale;
}

char* salvaConNome(char* cartella, char* nome)
{
	char* percorsoFinale = calloc( 1023 , sizeof(char) );
	strcat(percorsoFinale, cartella);
	strcat(percorsoFinale, nome);

	return percorsoFinale;
}

int copiaFile(char *destinazione, char *sorgente) //Non partorita dalla mia mente... purtroppo.
{
    int fd_to, fd_from;
    char buf[4096];
    ssize_t nread;
    int saved_errno;

    fd_from = open(sorgente, O_RDONLY);
    if (fd_from < 0)
        return -1;

    fd_to = open(destinazione, O_WRONLY | O_CREAT | O_EXCL, 0666);
    if (fd_to < 0)
        goto out_error;

    while (nread = read(fd_from, buf, sizeof buf), nread > 0)
    {
        char *out_ptr = buf;
        ssize_t nwritten;

        do {
            nwritten = write(fd_to, out_ptr, nread);

            if (nwritten >= 0)
            {
                nread -= nwritten;
                out_ptr += nwritten;
            }
            else if (errno != EINTR)
            {
                goto out_error;
            }
        } while (nread > 0);
    }

    if (nread == 0)
    {
        if (close(fd_to) < 0)
        {
            fd_to = -1;
            goto out_error;
        }
        close(fd_from);

        /* Success! */
        return 0;
    }

    out_error:
    saved_errno = errno;

    close(fd_from);
    if (fd_to >= 0)
        close(fd_to);

    errno = saved_errno;
    return -1;
}

void eliminaCartella(char* percorso)
{
	char* stringaCompleta = calloc(256, sizeof(char));
	strcat(stringaCompleta, "rmdir " );
	strcat(stringaCompleta, percorso);
	strcat(stringaCompleta, " /q /s");

	system(stringaCompleta);
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

char* getWorkingDirectory()
{
	char* stringa = malloc( 2048 * sizeof(char) );
	getcwd(stringa, 2048);

	return stringa;
}

char* getParentCartella(char* argomentoMain)
{
	char* percorsoTot = strdup(argomentoMain);

	int i = strlen(percorsoTot) - 1;
	while( (i > 0) )
	{
		if( percorsoTot[i] == '\\' )
		{
			percorsoTot[i] = '\0';
			return percorsoTot;
		}

		i = i - 1;
	}

	return percorsoTot;
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

void printaFile(char *indirizzo)
{
	FILE *file;
	char temp[255];

	file = fopen(indirizzo, "r");
	if( file != NULL )
	{
		while( fgets(temp, 255, file) )
			printf(temp);

		fclose(file);
	}
	else
		printf("Errore nell'aprire il file!\n");
}

int contaParole(char *indirizzo)
{
	int STR_SIZE = 1024;
	char* rigaCorrente = malloc( STR_SIZE * sizeof(char) );
	int contaParole = 0;

	int letteraPresente;
	int fineTrovata;

	FILE *file;
	file = fopen(indirizzo, "r");
	if( file == NULL )
	{
		printf("File non aperto!");
		system("PAUSE");
	}

	while( fgets(rigaCorrente, STR_SIZE, file) )
	{
		letteraPresente = 0;
		fineTrovata = 0;

//		printf("%s", rigaCorrente);
		strcat(rigaCorrente, " \0");	//Obbligo uno spazio vuoto alla fine della stringa.
//		printf("%s", rigaCorrente);

		int i = 0;
		while( i < strlen(rigaCorrente) )
		{
			if( !isSeparatore(rigaCorrente[i]) )
			{
				letteraPresente = 1;
			}
			else if( letteraPresente && !isSeparatore(rigaCorrente[i-1]) )
			{
				fineTrovata = 1;
			}

			if( letteraPresente && fineTrovata )
			{
				contaParole = contaParole + 1;
				letteraPresente = 0;
				fineTrovata = 0;
			}

			i = i + 1;
		}
	}
	fclose(file);
	return contaParole;
}

void contaCharLineeParole(char *indirizzo, int *contaChar, int *contaLinee, int *contaParole)
{
	int letteraPresente = 0;
	int fineTrovata = 0;
	char charCorrente;
	char charVecchio;

	int lunghezzaLinea = 0;
	int prendiLunghezza = 1;
	int contaCharLinea = 0;

	FILE *file = fopen(indirizzo, "r");
	if( file == NULL )
	{
		printf("File non aperto!");
		system("PAUSE");
	}



	while( (charCorrente = fgetc(file)) != EOF )
	{
		if( prendiLunghezza )
		{
			lunghezzaLinea = lungLinea(file, *contaLinee);
//			printf("%d", lunghezzaLinea);
//			printf("\n");
			prendiLunghezza = 0;
		}

		*contaChar = *contaChar + 1;
		contaCharLinea = contaCharLinea + 1;

		if( charCorrente == '\n')
		{
			*contaLinee = *contaLinee + 1;
			contaCharLinea = 0;
			prendiLunghezza = 1;
		}

		if( !isSeparatore(charCorrente) && ( contaCharLinea % lunghezzaLinea == 0 ) )
		{
			letteraPresente = 1;
			fineTrovata = 1;
		}
		else if( !isSeparatore(charCorrente))
		{
			letteraPresente = 1;
		}
		else if( letteraPresente && !isSeparatore(charVecchio) )
			fineTrovata = 1;

		if( letteraPresente && fineTrovata )
		{
			*contaParole = *contaParole + 1;
			letteraPresente = 0;
			fineTrovata = 0;
		}

		charVecchio = charCorrente;
	}

	fclose(file);
}

void contaParoleFreq(char *indirizzo, int *contaParole, Vector *frequenzier)
{
	int contaLinee = 1;
	int letteraPresente = 0;
	int fineTrovata = 0;
	char charCorrente;
	char charVecchio;

	int lunghezzaLinea = 0;
	int prendiLunghezza = 1;
	int contaCharLinea = 0;

	int charInParola = 0;

	FILE *file = fopen(indirizzo, "r");
	if( file == NULL )
	{
		printf("File non aperto!");
		system("PAUSE");
	}

	while( (charCorrente = fgetc(file)) != EOF )
	{
		if( prendiLunghezza )
		{
			lunghezzaLinea = lungLinea(file, contaLinee);
//			printf("%d", lunghezzaLinea);
//			printf("\n");
			prendiLunghezza = 0;
		}

		contaCharLinea = contaCharLinea + 1;

		if( charCorrente == '\n')
		{
			contaLinee = contaLinee + 1;
			contaCharLinea = 0;
			prendiLunghezza = 1;
		}

		if( !isSeparatore(charCorrente) && ( contaCharLinea % lunghezzaLinea == 0 ) )
		{
			charInParola = charInParola + 1;
			letteraPresente = 1;
			fineTrovata = 1;
		}
		else if( !isSeparatore(charCorrente))
		{
			charInParola = charInParola + 1;
			letteraPresente = 1;
		}
		else if( letteraPresente && !isSeparatore(charVecchio) )
			fineTrovata = 1;

		if( letteraPresente && fineTrovata )
		{
			*contaParole = *contaParole + 1;
			letteraPresente = 0;
			fineTrovata = 0;
			scriviVettore(frequenzier, charInParola, leggiVettore(*frequenzier, charInParola) + 1);
			charInParola = 0;
		}

		charVecchio = charCorrente;
	}

	fclose(file);
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

int lungLinea(FILE *file, int linea)
{
	int posInFile = ftell(file);
	char* strTemp = malloc( 2048 * sizeof(char) );
	fseek(file, 0, SEEK_SET);

	int i = 1;
	while( i != linea )
	{
		fgets(strTemp, 2048, file);
		i = i + 1;
	}

	fgets(strTemp, 2048, file);
	int lunLinea = strlen(strTemp);
	fseek(file, posInFile, SEEK_SET);
	return lunLinea;
}

char* getLinea(FILE *file, int linea)
{
	int posInFile = ftell(file);
	char* strTemp = calloc( 2047, sizeof(char) );
	fseek(file, 0, SEEK_SET);

	int i = 1;
	while( i != linea )
	{
		fgets(strTemp, 2047, file);
		i = i + 1;
	}

	fgets(strTemp, 2047, file);
	fseek(file, posInFile, SEEK_SET);
	return strTemp;
}

void replaceLine(char* indirizzo, int linea, char* newLine)
{
	SVector fileBuf = dumpaFileInVettore(indirizzo);

	FILE* file = fopen(indirizzo, "w");
	char* newLineEdit = strdup(newLine);

	int i = 0;
	while( i < getXSVettore(fileBuf) )
	{
		if( i  == linea -1)
		{
			strcat(newLineEdit, "\n");
			fprintf(file, newLineEdit);
		}
		else
		{
			fprintf(file, leggiSVettore(fileBuf, i));
		}

		i = i + 1;
	}

	fclose(file);
}

int getNumLinee(FILE *file)
{
	int numLinee = 0;
	char* strTemp = malloc( 255 * sizeof(char) );

	while( fgets(strTemp, 255, file) )
		numLinee = numLinee + 1;

	return numLinee;
}

void vaiALinea(FILE *file, int linea)
{
	int numLinee = 1;
	Vector lunghezzaLinee = creaVettore(100);
	char* strTemp = calloc( 255, sizeof(char) );

	while( fgets(strTemp, 255, file) && (numLinee < linea ) )
	{
		scriviVettore(&lunghezzaLinee, numLinee, strlen(strTemp) +1);
		numLinee = numLinee + 1;
	}

	int totalSeek = 0;
	int i = 1;
	while( i < numLinee )
	{
		totalSeek = totalSeek + ( leggiVettore(lunghezzaLinee, i) );
		i = i + 1;
	}

//	printw("%d", totalSeek);
//	refresh();
//	getch();

	fseek(file, totalSeek, SEEK_SET);
}

SVector dumpaFileInVettore(char* indirizzo)
{
	FILE *file = fopen(indirizzo, "r");
	SVector vettoreLinee = creaSVettore( getNumLinee(file) );

	rewind(file);
	if( file != NULL)
	{
		int i = 0;
		char* strTemp = malloc( 2047 * sizeof(char) );
		while( fgets(strTemp, 2047, file) )
		{
			scriviSVettore(&vettoreLinee, i, strTemp);
			i = i + 1;
		}

//		printaSVettore(vettoreLinee, 1);
//		getch();

		fclose(file);
		return vettoreLinee;
	}
	else
	{
		printf("%s","Errore nell'aprire il file!");
		return vettoreLinee;
	}
}

