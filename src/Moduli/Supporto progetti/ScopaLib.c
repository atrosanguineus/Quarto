#include "ScopaLib.h"

Carta creaCarta(char seme, int valore)
{
	Carta cartaTemp;

	setSeme(&cartaTemp, seme);
	setValore(&cartaTemp, valore);

	CMatrix outsideCard = baseCard();
	setBase(&cartaTemp, outsideCard);

	CMatrix insideCard = buildInside(cartaTemp);
	setInside(&cartaTemp, insideCard);

	Point defaultPoint = creaPunto(-1, -1);
	setCoordinate(&cartaTemp, defaultPoint);

	return cartaTemp;
}

CMatrix baseCard()
{
	int y = CARD_HEIGHT;
	int x = CARD_WIDTH;

	CMatrix baseGraphics = creaCMatrice(y, x);
	char currentFiller = ' ';


    int i = 0;
    while( i <  y )
    {
    	int j = 0;
    	while( j < x )
    	{
    		if( (j == 0 && i == 0) || (j == x - 1 && i == 0) )
    		{
    			scriviCMatrice( &baseGraphics, i, j, ' ' );
    		}

    		else
    		{
    			if( (i == y - 1 && j == 0) || (i == y - 1 && j == x - 1) )
    			{
    				scriviCMatrice( &baseGraphics, i, j, '|' );
    			}

        		else
        		{
        			if( i == 0 || i == y - 1 )
        			{
        				currentFiller = '_';
        			}

        			else if ( j == 0 || j == x - 1 )
        			{
        				currentFiller = '|';
        			}

        			else
        			{
        				currentFiller = ' ';
        			}

        			scriviCMatrice( &baseGraphics, i, j, currentFiller );
        		}
    		}

    	j = j + 1;
    	}

    	i = i + 1;
    }

    return baseGraphics;
}

CMatrix buildInside(Carta carta)
{
	CMatrix advancedGraphics = creaCMatrice( CARD_HEIGHT, CARD_WIDTH );
	fillBlank(&advancedGraphics);

	int cardValue = getValore(carta);
	char seme = getSeme(carta);

	if( cardValue  == 10 )
	{
		scriviCMatrice( &advancedGraphics, 1, 1, 'K' );
	}
	else if( cardValue  == 9 || cardValue == 8 )
	{
		scriviCMatrice( &advancedGraphics, 1, 1, 48 + cardValue );
	}
	else
	{
		scriviCMatrice( &advancedGraphics, 1, 1, 48 + cardValue );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 1, CARD_WIDTH - 2, 48 + cardValue );
	}


	if( cardValue  ==  1 )
	{
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2, CARD_WIDTH/2, seme );
	}

	if( cardValue  ==  2 )
	{
		int interval = CARD_HEIGHT/3;
		scriviCMatrice( &advancedGraphics, interval, CARD_WIDTH/2, seme );
		interval = interval + interval;
		scriviCMatrice( &advancedGraphics, interval, CARD_WIDTH/2, seme );
	}

	if( cardValue  ==  3 )
	{
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 - 1, CARD_WIDTH/2, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2, CARD_WIDTH/2, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 + 1, CARD_WIDTH/2, seme );
	}

	if( cardValue  ==  4 )
	{
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 - 1, CARD_WIDTH/2 -1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 - 1, CARD_WIDTH/2 + 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 + 1, CARD_WIDTH/2 - 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 + 1, CARD_WIDTH/2 + 1, seme );
	}

	if( cardValue  ==  5 )
	{
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 - 1, CARD_WIDTH/2 -1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 - 1, CARD_WIDTH/2 + 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 + 1, CARD_WIDTH/2 - 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 + 1, CARD_WIDTH/2 + 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2, CARD_WIDTH/2, seme );
	}

	if( cardValue  ==  6 )
	{
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 - 1, CARD_WIDTH/2 -1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 - 1, CARD_WIDTH/2 + 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 + 1, CARD_WIDTH/2 - 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 + 1, CARD_WIDTH/2 + 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2, CARD_WIDTH/2 - 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2, CARD_WIDTH/2 + 1, seme );
	}

	if( cardValue  ==  7 )
	{
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 - 1, CARD_WIDTH/2 -1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 - 1, CARD_WIDTH/2 + 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 + 1, CARD_WIDTH/2 - 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2 + 1, CARD_WIDTH/2 + 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2, CARD_WIDTH/2 - 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2, CARD_WIDTH/2 + 1, seme );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT/2, CARD_WIDTH/2, seme );
	}

	if( cardValue  ==  8 )
	{

	}

	if( cardValue  ==  9 )
	{

	}

	if( cardValue  ==  10 )
	{
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 1, CARD_WIDTH -2, 177 );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 1, CARD_WIDTH -3, 177 );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 1, CARD_WIDTH -4, 177 );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 1, CARD_WIDTH -5, 177 );

		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 2, CARD_WIDTH -2, 177 );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 2, CARD_WIDTH -3, 177 );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 2, CARD_WIDTH -4, 177 );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 2, CARD_WIDTH -5, '|' );

		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 3, CARD_WIDTH -2, 177 );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 3, CARD_WIDTH -3, 167 );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 3, CARD_WIDTH -5, seme );

		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 4, CARD_WIDTH -2, '(' );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 4, CARD_WIDTH -3, '{' );

		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 5, CARD_WIDTH -2, 'W' );
		scriviCMatrice( &advancedGraphics, CARD_HEIGHT - 5, CARD_WIDTH -3, 'W' );
	}

	return advancedGraphics;
}

void setSeme(Carta* carta, char seme)
{
	carta->seme = seme;
}

void setValore(Carta* carta, int valore)
{
	carta->valore = valore;
}

void setCoordinate(Carta* carta, Point coordinate)
{
	carta->coordinate = coordinate;
}

void setBase(Carta* carta, CMatrix base)
{
	carta->baseCard = base;
}

void setInside(Carta* carta, CMatrix inside)
{
	carta->insideCard = inside;
}

char getSeme(Carta carta)
{
	return carta.seme;
}

int getValore(Carta carta)
{
	return carta.valore;
}

Point getCoordinate(Carta carta)
{
	return carta.coordinate;
}

CMatrix getBase(Carta carta)
{
	return carta.baseCard;
}

CMatrix getInside(Carta carta)
{
	return carta.insideCard;
}


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

//void printaCURSCMatrice(CMatrix matrice, int spaces, int enableSpace)
//{
//	int y;
//	int x;
//	getyx(stdscr, y, x);
//
//	int i = 0;
//	while(i < getYCMatrice(matrice) )
//	{
//		int j = 0;
//		while( j < getXCMatrice(matrice) )
//		{
//			char tempCh = leggiCMatrice(matrice, i, j);
//			if( tempCh != ' ' || (tempCh == ' ' && enableSpace != 0) )
//			{
//				addch(leggiCMatrice(matrice, i, j));
//			}
//			else
//			{
//				int y2;
//				int x2;
//				getyx(stdscr, y2, x2);
//				move(y2, x2 + 1);
//			}
//
//			int k = 0;
//			while( k < spaces )
//			{
//				addch(' ');
//				k = k + 1;
//			}
//
//			j = j + 1;
//		}
//
//		i = i + 1;
//		y = y + 1;
//		move(y, x);
//	}
//}

void visualizzaCarta(Carta carta)
{
	Point posizione = getCoordinate(carta);

	int y = getYPunto(posizione);
	int x = getXPunto(posizione);


	char seme = getSeme(carta);

	if( y != -1 && x != -1 )
	{
		move(y, x);
		if( seme == 'C' )
		{
			init_pair(1, COLOR_RED, COLOR_BLACK);
		}
		else if( seme == 'D' )
		{
			init_pair(1, COLOR_YELLOW, COLOR_BLACK);
		}
		else if( seme == 'S' )
		{
			init_pair(1, COLOR_BLUE, COLOR_BLACK);
		}
		else if( seme == 'B' )
		{
			init_pair(1, COLOR_GREEN, COLOR_BLACK);
		}

		attron(COLOR_PAIR(1));
		attron(A_BOLD);
//		printaCURSCMatrice(outside, 0, 1);
		attroff(A_BOLD);
		attroff(COLOR_PAIR(1));

		move(y, x);
//		printaCURSCMatrice(inside, 0, 0);

		refresh();

	}

}

void nascondiCarta(Carta carta)
{
	//TODO
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

