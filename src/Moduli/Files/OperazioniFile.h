#ifndef MODULI_OPERAZIONIFILE_H_
#define MODULI_OPERAZIONIFILE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "../Vettori/BaseVettori.h"
#include "../Stringhe/OperazioniStringhe.h"

char* salvaConData(char* cartella);
char* salvaConNome(char* cartella, char* nome);
int copiaFile(char* destinazione, char* sorgente);
void eliminaCartella(char* percorso);

char* getWorkingDirectory();
char* getParentCartella(char* argomentoMain);

void printaFile(char *indirizzo);
int contaParole(char *indirizzo);
void contaCharLineeParole(char *indirizzo, int *contaChar, int *contaLinee, int *contaParole);
void contaParoleFreq(char *indirizzo, int *contaParole, Vector *frequenzier);

int lungLinea(FILE *file, int linea);
char* getLinea(FILE *file, int linea);
void replaceLine(char* indirizzo, int linea, char* newLine);
int getNumLinee(FILE *file);
void vaiALinea(FILE *file, int linea);
SVector dumpaFileInVettore(char* indirizzo);



#endif /* MODULI_OPERAZIONIFILE_H_ */
