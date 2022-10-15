//  sumuje elementy tablicy (poczatek i rozmiar) - Listing_10_10.c
//  v1.0
#include <stdio.h>
#define ROZMIAR 10
long sumuj(int tab[], int n);

int main(void)
{
	int kulki[ROZMIAR] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
	long wynik;
	wynik = sumuj(kulki, ROZMIAR);
	printf("Calkowita liczba kulek wynosi %ld.\n", wynik);
	printf("Rozmiar tablicy kulki wynosi %d bajtow.\n", sizeof kulki);
	return 0;
}

long sumuj(int tab[], int n)		 									// notacja tablicowa
// jak duza jest tablica?
{
	int i;
	int suma = 0;
	for (i = 0; i <n; i++)
	{
		suma += tab[i];													// notacja tablicowa

	}
	printf("Rozmiar tablicy tab wynosi %zd bajtow.\n", sizeof tab);		// notacja tablicowa
	return suma;
}