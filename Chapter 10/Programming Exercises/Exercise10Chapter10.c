//  Suma elementow dwoch tablic - Exercise10Chapter10.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#define ROZMIAR 7
void suma_dbl_tab(const double * tab1, const double * tab2, double * tab_sum, int rozmiarX);
void pokaz_tab(const double * tab, int rozmiarX);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double tabA[ROZMIAR] = {2.31, 3.42, 4.53, 5.64, 6.75, 0.06, 8.97};
	double tabB[ROZMIAR] = {-1, 0, 1, 1, -1, 0, 1};
	double tabC[ROZMIAR];
	
/*  Description ---------------------------------------------------------------*/
	puts("Program zapisuje do tablicy sume elementow dwoch tablic.");
	
/*  Code ----------------------------------------------------------------------*/
	puts("\nPrzed");
	pokaz_tab(tabC, ROZMIAR);

	suma_dbl_tab(tabA, tabB, tabC, ROZMIAR);
	puts("\nPo:");
	pokaz_tab(tabC, ROZMIAR);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void suma_dbl_tab(const double * tab1, const double * tab2, double * tab_sum, int rozmiarX)
{
	int i;
	for (i = 0; i < rozmiarX; i++)
	{
		*(tab_sum + i) = *(tab2 + i) + *(tab1 + i);
	}
}

void pokaz_tab(const double * tab, int rozmiarX)
{
	int j;
	for (j = 0; j < rozmiarX; j++)
	{
		printf("%.2f ", tab[j]);									// notacja tablicowa
	}
	putchar('\n');
}