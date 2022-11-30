//  wyswietla zawartosc pliku w odwrotnej kolejnosci - Listing_13_4.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#define DLAN 81
#define CTRL_Z '\032'

int main(void)
{
	FILE *wp;
	char plik[DLAN];
	char ch;
	long licznik, koniec;
	puts("Podaj nazwe pliku:");
	scanf("%80s", plik);

	if ( (wp = fopen(plik, "rb")) == NULL) // tryb tylko do odczytu
	{
		printf("Nie moge otworzyc %s.\n", plik);
		exit(EXIT_FAILURE);
	}
	fseek(wp, 0L, SEEK_END);				// przejdz do konca pliku
	koniec = ftell(wp);

	for (licznik = 1L; licznik <= koniec; licznik++)
	{
		fseek (wp, -licznik, SEEK_END);		// idz do tylu
		ch = getc(wp);
		if (ch != CTRL_Z && ch != '\r')
		{
			putchar(ch);
		}
	}

	putchar('\n');
	fclose(wp);
	return 0;
}