//  mniejsze - Listing_9_3.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
int imin(int, int);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int zlo1, zlo2;
	
/*  Description ---------------------------------------------------------------*/
/*  Code ----------------------------------------------------------------------*/
	printf("Podaj dwie liczby calkowite (q konczy program):\n");
	while (2 == scanf("%d %d", &zlo1, &zlo2))
	{
		printf("Mniejsza liczba sposrod %d i %d jest %d.\n", zlo1, zlo2, imin(zlo1, zlo2));
		printf("Podaj dwie liczby calkowite (q konczy program):\n");
	}

/*  Ending --------------------------------------------------------------------*/
	printf("Gotowe.\n");
	return 0;
}

int imin(int n, int m)
{
	int min;
	if (n < m)
		min = n;
	else
		min = m;
	return min;			// albo inaczej return (n < m) ? n : m
}