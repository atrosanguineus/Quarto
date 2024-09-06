#include "BaseMenu.h"

Entrate creaEntrate( SVector nomi, void (**funzioni)() )
{
	Entrate daRitornare;
	daRitornare.nomi = nomi;
	daRitornare.funzioni = funzioni;

	return daRitornare;
}

SVector getNomi( Entrate lista )
{
	return lista.nomi;
}

void (**getFunzioni(Entrate lista))()
{
	return lista.funzioni;
}

void setNomi( Entrate* lista, SVector nomi )
{
	lista->nomi = nomi;
}

void setFunzioni( Entrate* lista, void (**funzioni)() )
{
	lista->funzioni = funzioni;
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

void attivaAttributi(Vector vettore)
{
	int i = 0;
	while( i < getXVettore(vettore) )
	{
		int tempAttr = leggiVettore(vettore, i) ;
		attron( tempAttr );
		i = i + 1;
	}
}

void disattivaAttributi(Vector vettore)
{
	int i = 0;
	while( i < getXVettore(vettore) )
	{
		int tempAttr = leggiVettore(vettore, i) ;
		attroff( tempAttr );
		i = i + 1;
	}
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

void chiamaFunzione(Entrate lista, int n)
{
	lista.funzioni[n]();
}

void refreshMenu( Menu menu )
{

	int elementoCorrente = getPosizione(menu);
	SVector nomi = getNomi( getLista( menu ) );
	char* entrataPuntata = strdup( concatenaStringa( getSelettore(menu), leggiSVettore(nomi, elementoCorrente)) );

	int posY = getYPunto( getPunto(menu) );
	int posX = getXPunto( getPunto(menu) );
	int elementiMenu = getXSVettore(nomi);

	int i = 0;
	while( i < elementiMenu )
	{
		Point inizioEntrata = creaPunto( posY + i, posX );
		move( getYPunto(inizioEntrata), getXPunto(inizioEntrata) );
		printaNSpazi( strlen(leggiSVettore( nomi, i)) + strlen( getSelettore(menu)) );
		move( getYPunto(inizioEntrata), getXPunto(inizioEntrata) );

		if( i == elementoCorrente )
		{


			attivaAttributi( getAttribSeletto(menu) );
			addstr( entrataPuntata );
			disattivaAttributi( getAttribSeletto(menu) );
		}
		else
		{
			attivaAttributi( getAttribResto(menu) );
			addstr( leggiSVettore( nomi, i));
			disattivaAttributi( getAttribResto(menu) );
		}

		i = i + 1;
	}
	refresh();
}

int gestisciInputMenu(Menu* menu, int input)
{
	int posizione = getPosizione(*menu);
	int numElementi = getElementi(*menu) - 1;

	if(input == KEY_UP)
	{
		if( isWrappato(*menu) && (posizione == 0) )
		{
			posizione = numElementi;
		}
		else if( posizione > 0 )
		{
			posizione = posizione - 1;
		}
	}
	else if(input == KEY_DOWN)
	{
		if( isWrappato(*menu) && (posizione == numElementi) )
		{
			posizione = 0;
		}
		else if( posizione < numElementi)
		{
			posizione = posizione + 1;
		}
	}
	else if(input == 13 || input == 10)
	{
		Entrate entrateMenu = getLista(*menu);
		chiamaFunzione(entrateMenu, posizione);
	}
	else if(input == 27)
	{
		return 1;
	}

	setPosizione(menu, posizione);
	refreshMenu(*menu);
	return 0;
}

void prendiControllo(Menu* menu)
{
	int sigKill = 0;
	while(sigKill != 1)
	{
		int input = getch();
		sigKill = gestisciInputMenu(menu, input);
	}
}

void printaNSpazi(int n)
{
	int i = 0;
	while( i < n )
	{
		addch(' ');
		i = i + 1;
	}
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

void printaFileCRS(FILE* file)
{
	move(0,0);
	char charNow;
	while( (charNow = fgetc(file)) != EOF )
		addch(charNow);
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

Menu creaMenu( Entrate lista, Point puntoPartenza, int posizione, char* selettore, int wrappato, Vector attribSeletto, Vector attribResto )
{
	Menu daRitornare;
	daRitornare.lista = lista;
	daRitornare.puntoPartenza = puntoPartenza;
	daRitornare.posizione = posizione;
	daRitornare.selettore = selettore;
	daRitornare.elementi = getXSVettore( getNomi(lista) );
	daRitornare.wrappato = wrappato;
	daRitornare.attribSeletto = attribSeletto;
	daRitornare.attribResto = attribResto;

	return daRitornare;
}

void setPosizione(Menu* menu, int valore)
{
	menu->posizione = valore;
}

Entrate getLista( Menu menu )
{
	return menu.lista;
}

Point getPunto(Menu menu)
{
	return menu.puntoPartenza;
}

int getPosizione(Menu menu)
{
	return menu.posizione;
}

char* getSelettore(Menu menu)
{
	return menu.selettore;
}

int getElementi(Menu menu)
{
	return menu.elementi;
}

int isWrappato(Menu menu)
{
	return menu.wrappato;
}

Vector getAttribSeletto(Menu menu)
{
	return menu.attribSeletto;
}

Vector getAttribResto(Menu menu)
{
	return menu.attribResto;
}



