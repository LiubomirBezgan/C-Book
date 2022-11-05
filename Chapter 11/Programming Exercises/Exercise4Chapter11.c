//  test funkcji zapisz_pierwsze_slowo_n() - Exercise4Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <ctype.h>
#include <stdbool.h>
#define ROZMIAR 81
void zapisz_pierwsze_slowo_n(char * do_tablicy, unsigned int n);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char tablica[ROZMIAR];
	unsigned int ile_znakow;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje, ktora zapisuje pierwsze n znakow pierwszego slowa\ndo tablicy przekazanej przez adres argumentem wywolania funkcji.\n");

/*  Code ----------------------------------------------------------------------*/
	puts("Ile znakow chcesz zapisac do tablicy?");
	scanf("%u", &ile_znakow);
	while (getchar() != '\n')
	{
		continue;
	}
	puts("Wpisz slowo:");
	zapisz_pierwsze_slowo_n(tablica, ile_znakow);
	puts("Oto wynik:");
	puts(tablica);
/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

void zapisz_pierwsze_slowo_n(char * do_tablicy, unsigned int n)
{
	bool w_slowie = false;
	char aktualny;
	unsigned int licznik = 0;
	while (((aktualny = getchar()) != EOF) && (licznik < n))
	{
		if (w_slowie)				// jesli jestesmy w slowie
		{
			if (!isspace(aktualny))
			{
				*do_tablicy++ = aktualny;
				licznik++;
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
				licznik++;
			}
		}
	}
	*do_tablicy = '\0';
}