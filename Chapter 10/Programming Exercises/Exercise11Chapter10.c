//  test funkcji wyswietlania i podwajania tablic 2D - Exercise11Chapter10.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#define WIERSZE 3
#define KOLUMNY 5
void pokaz_tab_2D(double (*tab)[KOLUMNY], int rozmiarY);
void podwuj_tab_2D(double (*tab)[KOLUMNY], int rozmiarY);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double zrodlo[WIERSZE][KOLUMNY] = 
	{
		{1.1, 2.2, 3.3, 4.4, 5.5},
		{6.6, 7.7, 8.8, 9.9, 1.2},
		{2.3, 3.4, 4.5, 5.6, 6.7}
	};	
	
/*  Description ---------------------------------------------------------------*/
	puts("Program wyswietla tablice 3x5, po czym podwaja wartosci jej elementow i wyswietla nowe wartosci.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Przed:");
	pokaz_tab_2D(zrodlo, WIERSZE);

	podwuj_tab_2D(zrodlo, WIERSZE);

	puts("Po:");
	pokaz_tab_2D(zrodlo, WIERSZE);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}


void pokaz_tab_2D(double (*tab)[KOLUMNY], int rozmiarY)
{
	int y, x;
	for (y = 0; y < rozmiarY; y++)
	{
		for (x = 0; x < KOLUMNY; x++)
		{
			printf("%4.1f ", *(*(tab + y) + x));
		}
		putchar('\n');
	}
}

void podwuj_tab_2D(double (*tab)[KOLUMNY], int rozmiarY)
{
	int y, x;
	for (y = 0; y < rozmiarY; y++)
	{
		for (x = 0; x < KOLUMNY; x++)
		{
			*(*(tab + y) + x) *= 2;
		}
	}
}