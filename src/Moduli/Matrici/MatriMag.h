#ifndef MODULI_MATRIMAG_H_
#define MODULI_MATRIMAG_H_

#include <stdlib.h>
#include <stdio.h>

#include "BaseMatrici.h"
#include "OperazioniMatrici.h"

void genioCella(Matrix matrice);
void magiaColonne(Matrix matrice, int obiettivoMagico);
void magiaRighe(Matrix matrice, int obiettivoMagico);
void magiaDiagonale(Matrix matrice, int obiettivoMagico);

#endif /* MODULI_MATRIMAG_H_ */
