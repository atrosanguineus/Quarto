#ifndef OPERAZIONIMATRICI_H_
#define OPERAZIONIMATRICI_H_

#include "BaseMatrici.h"

void riempiRandomMatrice(Matrix *matrice, int minVal, int maxVal);
int sommaColonna(Matrix matrice, int colonna);
int sommaRiga(Matrix matrice, int riga);
int sommaDiagonale(Matrix matrice, int diagonale);

void fillBlank(CMatrix* matrice);

void scambiaColonna(Matrix *matrice, int colonna1, int colonna2);
void scambiaRiga(Matrix *matrice, int riga1, int riga2);

Matrix copiaMatrice(Matrix from);

Matrix sommaMatrici(Matrix matrice1, Matrix matrice2);
Matrix scalareMatrice(Matrix matrice1, int scalare);
Matrix trasposizioneMatrice(Matrix matrice1);
Matrix prodottoMatrici(Matrix matrice1, Matrix matrice2);

#endif /* OPERAZIONIMATRICI_H_ */
