// wielrzut.c - wielokrotny rzut koscmi - Exercise7Chapter12.c
// kompilowac z rzutkosc.c (Listing_12_11.c)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rzutkosc.h"

int main(void)
{
	int rzuty, wynik;
	int scianki, status;
	int liczba_kolejek;
	int i;

	srand((unsigned int) time(0));		// losowe ziarno
	puts("Wprowadz liczbe kolejek; wybierz q, aby zakonczyc.");// puts("Podaj liczbe scianek, 0 oznacza koniec.");
	while (scanf("%d", &liczba_kolejek) == 1 && liczba_kolejek > 0) //while (scanf("%d", &scianki) == 1 && scianki > 0)
	{
		puts("Ile scian i ile kosci?");
		if ((status = scanf("%d %d", &scianki, &rzuty)) != 2)
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
		printf("Oto %d kolejek rzutow %d %d-sciennymi kostkami:\n", liczba_kolejek, rzuty, scianki);
		for (i = 1; i <= liczba_kolejek; i++)
		{
			wynik = rzucaj_n_razy(rzuty, scianki);
			printf("%3d ", wynik);
			if (0 == i % 15)
			{
				putchar('\n');
			}
		}
		puts("\nWprowadz liczbe kolejek; wybierz q, aby zakonczyc.");
	}
	return 0;
}