//  Wyswietla wszystkie liczby pierwsze mniejsze lub rowne podanej przez uzytkownika - Exercise9Chapter7.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int liczba_biezaca, liczba_pobrana, odczyt;
	int i;											// uzywana jest w petli wewnetrznej
	unsigned int licznik_dzielnikow = 0;
	char ch;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program wyswietla wszystkie liczby pierwsze mniejsze lub rowne podanej przez uzytkownika.");
	
/*  Code ----------------------------------------------------------------------*/
	// pobranie liczby
	puts("Prosze podac dodatnia liczbe calkowita:");
	odczyt = scanf("%d", &liczba_pobrana);
	while (0 == odczyt || liczba_pobrana < 0)
	{
		while ((ch = getchar()) != '\n')
			continue;								// czyszczenie bufora
		puts("Podana zla wartosc");
		puts("\nProsze podac dodatnia liczbe calkowita:");
		odczyt = scanf("%d", &liczba_pobrana);
	}
	printf("Przyjeto: %d\n", liczba_pobrana);

	// obliczenia i wyswietlenie wynikow
	if (liczba_pobrana > 2)
	{
		printf("Liczby pierwsze: 2");
		for (liczba_biezaca = 3; liczba_biezaca <= liczba_pobrana; liczba_biezaca++, licznik_dzielnikow = 0)
		{
			for (i = 1; i <= liczba_biezaca; i++)
			{
				if (liczba_biezaca % i == 0)
					licznik_dzielnikow++;
				if (licznik_dzielnikow > 2)
					break;
			}
			if (licznik_dzielnikow == 2)
				printf(", %d", liczba_biezaca);
		}
	}
	else if (liczba_pobrana < 2)
		printf("Nie ma liczb pierwszych mniejszych od 2.");
	else
		printf("Liczba pierwsza: 2");

/*  Ending --------------------------------------------------------------------*/
	puts("\n\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}