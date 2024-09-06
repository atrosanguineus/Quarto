#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#include "Moduli/Supporto Progetti/QuartoGame.h"

int main(int argc, char** argv)
{
	srand(time(NULL));
	initCurse();
	localizeExe(argv);
	enterMenu();
	return 0;
}
