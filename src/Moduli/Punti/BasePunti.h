#ifndef MODULI_PUNTI_BASEPUNTI_H_
#define MODULI_PUNTI_BASEPUNTI_H_

typedef struct
{
	int y;
	int x;
}Point;


Point creaPunto(int y, int x);
void setXPunto(Point* punto, int x);
void setYPunto(Point* punto, int y);
int getXPunto(Point punto);
int getYPunto(Point punto);

#endif /* MODULI_PUNTI_BASEPUNTI_H_ */
