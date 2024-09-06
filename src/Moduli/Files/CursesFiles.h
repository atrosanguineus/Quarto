#ifndef MODULI_FILES_CURSESFILES_H_
#define MODULI_FILES_CURSESFILES_H_

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#include "../Vettori/BaseVettori.h"
#include "../Stringhe/OperazioniStringhe.h"

#define UPMOST_ROW 0
#define CLIMB_ROW 1
#define INTERS_ROW 2
#define BOTTOM_ROW 3

void printFile(int y, int x, FILE* file);
void highlightElement(SVector svector, int elem);
void printCornice(int height, int width);

#endif /* MODULI_FILES_CURSESFILES_H_ */
