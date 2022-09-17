// funkcje dla zarzadzajacych hotelami - Listing_9_10.c
#include <stdio.h>
#include "hotel.h"

int menu(void)
{
	int kod, stan;
	printf("\n%s%s\n", GWIAZDKI, GWIAZDKI);
	puts("Podaj numer hotelu:");
	puts("1) Marek Antoniusz          2) Olimpijski");
	puts("3) U Marynarza              4) Savoy");
	puts("5) koniec");
	printf("%s%s\n", GWIAZDKI, GWIAZDKI);
	while ((stan = scanf("%d", &kod)) != 1 || (kod < 1 || kod > 5))
	{
		if (stan != 1)
		{
			scanf("%*s");		// odrzucamy wejscie nieliczbowe
		}
		puts("Podaj liczbe z przedzialu od 1 do 5.");
	}
	return kod;
}

int pobierz_noce(void)
{
	int noce;
	printf("Ile nocy bedzie potrzebne? ");
	while (scanf("%d", &noce) != 1)
	{
		scanf("%*s");			// odrzucamy wejscie nieliczbowe
		puts("Podaj liczbe calkowita, np. 2.");
	}
	return noce;
}

void pokaz_cene(double hotel, int noce)
{
	int n;
	double suma = 0.0;
	double przelicznik = 1.0;
	for (n = 1; n <= noce; n++, przelicznik *= RABAT)
	{
		suma += hotel * przelicznik;
	}
	printf("Calkowity koszt pobytu wyniesie %0.2f $\n", suma);
}