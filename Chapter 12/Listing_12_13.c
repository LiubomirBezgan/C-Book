// wielrzut.c - wielokrotny rzut koscmi - Listing_12_13.c
// kompilowac z rzutkosc.c (Listing_12_11.c)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rzutkosc.h"

int main(void)
{
	int rzuty, wynik;
	int scianki, status;

	srand((unsigned int) time(0));		// losowe ziarno
	puts("Podaj liczbe scianek, 0 oznacza koniec.");
	while (scanf("%d", &scianki) == 1 && scianki > 0)
	{
		puts("Ile rzutow?");
		if ((status = scanf("%d", &rzuty)) != 1)
		{
			if (status == EOF)
			{
				break;
			}
			else
			{
				puts("Nalezy podac liczbe calkowita.");
				puts("Sprobujmy jeszcze raz.");
				while (getchar() != '\n')
				{
					continue;			// odrzucenie niepoprawnego wejscia
				}
				puts("Ile scianek? 0 oznacza koniec.");
				continue;				// nowy przebieg petli		
			}
		}

		wynik = rzucaj_n_razy(rzuty, scianki);
		printf("Wyrzucono razem %d uzywajac %d %d-sciennych kosci.\n", wynik, rzuty, scianki);
		puts("Podaj liczbe scianek, 0 oznacza koniec.");
	}
	printf("Funkcja rzucaj() zostala wywolana %d razy.\n", liczba_rzutow);		// zmienna zewnetrzna
	puts("ZYCZE DUZO SZCZESCIA!");

	return 0;
}