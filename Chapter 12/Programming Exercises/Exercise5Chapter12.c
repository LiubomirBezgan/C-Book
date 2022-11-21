//  sortowanie (w porzadku malejacym) 100 losowych liczb z przedzialu od 1 do 10 - Exercise5Chapter12.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <stdlib.h>
#include <time.h>
#define ROZMIAR 100
void wyswietl_tablice_kolumnami(int * tablica, int rozmiar, unsigned int kolumny);


/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int losowe_liczby[ROZMIAR];
	int i, j;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program generuje liste 100 losowych liczb\nz przedzialu od 1 do 10 w porzadku malejacym.\n");
	
/*  Code ----------------------------------------------------------------------*/
	srand((unsigned int) time(0));				// losowe ziarno
	for (i = 0; i < ROZMIAR; i++)
	{
		losowe_liczby[i] = (rand() % 10) + 1;
	}
	puts("Pierwotna lista:");
	wyswietl_tablice_kolumnami(losowe_liczby, ROZMIAR, 10);

	for (i = 0; i < ROZMIAR - 1; i++)
	{
		for (j = 1; j < ROZMIAR; j++)
		{
			if (losowe_liczby[j] > losowe_liczby[j-1])
			{
				int temp;
				temp = losowe_liczby[j];
				losowe_liczby[j] = losowe_liczby[j - 1];
				losowe_liczby [j - 1] = temp;
			}
		}
	}

	puts("Lista po sortowaniu:");
	wyswietl_tablice_kolumnami(losowe_liczby, ROZMIAR, 10);

/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

void wyswietl_tablice_kolumnami(int * tablica, int rozmiar, unsigned int kolumny)
{
	int i;
	for (i = 0; i < rozmiar; i++)
	{
		printf("%4d", tablica[i]);
		if (0 == (i + 1) % kolumny)
		{
			putchar('\n');
		}
	}
}