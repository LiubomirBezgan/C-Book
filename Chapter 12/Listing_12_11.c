// rzutkosc.c - symulacja rzutu koscmi - Listing_12_11.c
// kompilowac razem z wielrzut.c (Listing_12_13.c)
#include "rzutkosc.h"
#include <stdio.h>
#include <stdlib.h>
int liczba_rzutow = 0;

static int rzucaj(int scianki)
{
	int oczka;
	oczka = rand() % scianki + 1;
	++liczba_rzutow;				// zlicza wywolania funkcji
	return oczka;
}

int rzucaj_n_razy(int rzuty, int scianki)
{
	int k;
	int suma = 0;
	if (scianki < 2)
	{
		puts("Wymagane sa co najmniej 2 scianki.");
		return -2;
	}
	if (rzuty < 1)
	{
		puts("Wymagany co najmniej 1 rzut.");
		return -1;
	}
	for (k = 0; k < rzuty; k++)
	{
		suma += rzucaj(scianki);
	}
	return suma;
}