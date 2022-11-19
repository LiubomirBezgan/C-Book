// pe12-3a.c
// kompilowac z pe12-3b.c
#include <stdio.h>
#include <mylib.h>
#include "pe12-3a.h"

int wybierz_tryb(int tryb, int poprzedni_tryb)
{
	if (tryb > 1)
	{
		printf("Podano nieprawidlowa wartosc. Wybrano system %d ", poprzedni_tryb);
		if (0 == poprzedni_tryb)
		{
			printf("(metryczny)\n");
		}
		else
		{
			printf("(US)\n");			
		}
		return poprzedni_tryb;
	}
	else
	{
		return tryb;
	}
}

void pobierz_dane(int system, float * wsk_dystans, float * wsk_zuzyte_paliwo)
{
	if (0 == system)
	{
		printf("Wprowadz przebyta odleglosc w kilometrach: ");
		scanf("%f", wsk_dystans);
		czysty_bufor();
		printf("Wprowadz zuzyte paliwo w litrach: ");
		scanf("%f", wsk_zuzyte_paliwo);
		czysty_bufor();
	}
	else
	{
		printf("Wprowadz przebyta odleglosc w milach: ");
		scanf("%f", wsk_dystans);
		czysty_bufor();
		printf("Wprowadz zuzyte paliwo w galonach: ");
		scanf("%f", wsk_zuzyte_paliwo);
		czysty_bufor();
	}
}

void wyswietl_dane(int system, float * wsk_dystans, float * wsk_zuzyte_paliwo)
{
	if (0 == system)
	{
		printf("Zuzycie paliwa wynioslo %.2f litrow na 100 km.\n", (100 * (*wsk_zuzyte_paliwo) / *wsk_dystans ));

	}
	else
	{
		printf("Zuzycie paliwa wynioslo %.1f mil na galon.\n", *wsk_dystans / *wsk_zuzyte_paliwo );

	}
}