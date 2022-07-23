// wyniki - Listing_6_19.c
// v1.0
#include <stdio.h>
#define ROZMIAR 10
#define PAR 72

int main(void)
{
	int index, wynik[ROZMIAR];
	int suma = 0;
	float srednia;

	printf("Podaj %d wynikow gry w golfa:\n", ROZMIAR);
	for (index = 0; index < ROZMIAR; index++)
		scanf("%d", &wynik[index]);

	puts("Odczytane wyniki to:");
	for (index = 0; index < ROZMIAR; index++)
		printf("%5d", wynik[index]);
	printf("\n");

	for (index = 0; index < ROZMIAR; index++)
		suma += wynik[index];
	srednia = (float) suma / ROZMIAR;

	printf("Suma wynikow = %d, srednia = %.2f\n", suma, srednia);
	printf("Oznacza to handicap w wysokosci %.0f.\n", srednia - PAR);

	return 0;
}