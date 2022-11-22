//  opis - Exercise6Chapter12.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <stdlib.h>
#include <time.h>
#define ZAKRES 10
#define ROZMIAR 1000

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	unsigned int ile_razy[ZAKRES] = {0};					// inicjalizuje wszystkie wartości na zero
	int numer_ziarna;
	int i;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program sprawdza losowosc generatora liczb losowych z biblioteki stdlib.h.\n\nIle razy dana liczba (od 1 do 10) zostala wybrana (po wygenerowaniu 1000 losowych liczb).");
	
/*  Code ----------------------------------------------------------------------*/
	for (numer_ziarna = 0; numer_ziarna < 10; numer_ziarna++)
	{
		
		srand( ( (unsigned int) time(0) ) +  numer_ziarna);				// losowe ziarno
		for (i = 0; i < ROZMIAR; i++)
		{
			ile_razy[(rand() % 10)]++;

		}
		
		printf("Dla %2d. ziarna:\n", numer_ziarna + 1);
		for (i = 1; i <= 10; i++)
		{
			printf("%2d - %4u,   ", i, ile_razy[i - 1]);
		}
		putchar('\n');

		for (i = 0; i < ZAKRES; i++)
		{
			ile_razy[i] = 0;

		}
	}

/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}