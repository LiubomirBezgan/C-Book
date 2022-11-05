//  test funkcji zapisz_pierwsze_slowo() - Exercise3Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <ctype.h>
#include <stdbool.h>
#define ROZMIAR 81
void zapisz_pierwsze_slowo(char * do_tablicy);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char tablica[ROZMIAR];
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje, ktora zapisuje pierwsze slowo do tablicy\nprzekazanej przez adres argumentem wywolania funkcji.");

/*  Code ----------------------------------------------------------------------*/
	puts("Wpisz slowo:");
	zapisz_pierwsze_slowo(tablica);
	puts("Oto wynik:");
	puts(tablica);
/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

void zapisz_pierwsze_slowo(char * do_tablicy)
{
	bool w_slowie = false;
	char aktualny;
	while ((aktualny = getchar()) != EOF)
	{
		if (w_slowie)				// jesli jestesmy w slowie
		{
			if (!isspace(aktualny))
			{
				*do_tablicy++ = aktualny;
			}
			else
			{
				break;
			}

		}
		else						// jesli nie jestesmy w slowie
		{
			if (!isspace(aktualny))
			{
				w_slowie = true;
				*do_tablicy++ = aktualny;
			}
		}
	}
	*do_tablicy = '\0';
}