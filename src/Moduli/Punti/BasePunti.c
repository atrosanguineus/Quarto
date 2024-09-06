#include "BasePunti.h"

Point creaPunto(int y, int x)
{
	Point daRitornare;
	daRitornare.y = y;
	daRitornare.x = x;

	return daRitornare;
}

void setXPunto(Point* punto, int x)
{
	punto->x = x;
}

void setYPunto(Point* punto, int y)
{
	punto->y = y;
}

int getXPunto(Point punto)
{
	return punto.x;
}

int getYPunto(Point punto)
{
	return punto.y;
}
