#include "CursesFiles.h"

void printFile(int y, int x, FILE* file)
{
	int i = 0;
	char* tempStr = malloc(255 * sizeof(char));
	while( fgets(tempStr, 255, file) )
	{
		move(y + i, x);
		addstr(tempStr);
		i = i + 1;
	}
}

void highlightElement(SVector svector, int elem)
{
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	int len = getXSVettore(svector);
	int i = 0;
	while( i < len )
	{
		if( i == elem - 1 )
		{
			attron(A_BOLD);
			attron(COLOR_PAIR(1));
			addstr(leggiSVettore(svector, i));
			attroff(COLOR_PAIR(1));
			attroff(A_BOLD);
		}
		else
		{
			addstr(leggiSVettore(svector, i));
		}

		i = i + 1;
	}
}

void printCornice(int height, int width)
{
	attron(A_ALTCHARSET);

	int y, x;
	int i = 0;
	while( i < width + 2 )
	{
		getyx(stdscr,y,x);

		if( i == 0 )
		{
			addch(ACS_ULCORNER);
			move(y + height + 1, x);
			addch(ACS_LLCORNER);

			move(y + 1, x);
			int k = 1;
			while( k <= height )
			{
				addch(ACS_VLINE);
				k = k + 1;
				move(y + k, x);
			}

		}
		else if( i == width + 1 )
		{
			addch(ACS_URCORNER);
			move(y + height + 1, x);
			addch(ACS_LRCORNER);

			move(y + 1, x);
			int k = 1;
			while( k <= height )
			{
				addch(ACS_VLINE);
				k = k + 1;
				move(y + k, x);
			}
		}
		else
		{
			addch(ACS_HLINE);
			move(y + height + 1, x);
			addch(ACS_HLINE);
		}

		i = i + 1;
		move(y, x + 1);
	}

	attroff(A_ALTCHARSET);
}
