// pe12-2a.c
// kompilowac z pe12-2b.c
#include <stdio.h>
#include <mylib.h>
#include "pe12-2a.h"
static int system;
static float dystans;
static float zuzyte_paliwo;

void wybierz_tryb(int tryb)
{
	if (tryb > 1)
	{
		printf("Podano nieprawidlowa wartosc. Wybrano system %d ", system);
		if (0 == system)
		{
			printf("(metryczny)\n");
		}
		else
		{
			printf("(US)\n");			
		}
	}
	else
	{
		system = tryb;
	}
}

void pobierz_dane(void)
{
	if (0 == system)
	{
		printf("Wprowadz przebyta odleglosc w kilometrach: ");
		scanf("%f", &dystans);
		czysty_bufor();
		printf("Wprowadz zuzyte paliwo w litrach: ");
		scanf("%f", &zuzyte_paliwo);
		czysty_bufor();
	}
	else
	{
		printf("Wprowadz przebyta odleglosc w milach: ");
		scanf("%f", &dystans);
		czysty_bufor();
		printf("Wprowadz zuzyte paliwo w galonach: ");
		scanf("%f", &zuzyte_paliwo);
		czysty_bufor();
	}
}

void wyswietl_dane(void)
{
	if (0 == system)
	{
		printf("Zuzycie paliwa wynioslo %.2f litrow na 100 km.\n", (100 * zuzyte_paliwo) / dystans );

	}
	else
	{
		printf("Zuzycie paliwa wynioslo %.1f mil na galon.\n", dystans / zuzyte_paliwo );

	}
}