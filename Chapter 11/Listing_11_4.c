//  tablice wskaznikow, tablice lancuchow - Listing_11_4.c
//  v1.0
#include <stdio.h>
#define DLUGOSC 40
#define MAX 5

int main(void)
{
	const char *wymagania[MAX] = {
		"Dodawanie w pamieci",
		"Bezblende mnozenie",
		"Szybkie zapamietywanie",
		"Doslowne wykonywanie polecen",
		"Programowanie w C"
	};

	char umiejetnosci[MAX][DLUGOSC] = {
		"Chodzenie wzdluz linii",
		"Spanie", "Oglodanie telewizji",
		"Wysylanie poczty", "Czytanie e-maili"
	};

	int i;
	puts("Porownajmy:");
	printf("%-36s %-25s\n", "wymagania", "umiejetnosci");
	for (i = 0; i < MAX; i++)
	{
		printf("%-36s %-25s\n", wymagania[i], umiejetnosci[i]);	
	}
	printf("\nsizeof wymagania: %zd, sizeof umiejetnosci: %zd\n", sizeof(wymagania), sizeof(umiejetnosci));
	return 0;
}