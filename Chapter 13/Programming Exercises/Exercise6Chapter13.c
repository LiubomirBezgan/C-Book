//  zmniejsza rozmiar Twoich plikow o dwie trzecie - Exercise6Chapter13.c
//  v1.1
#include <stdio.h>
#include <stdlib.h>				// prototyp funkcji exit()
#include <string.h>
#include <mylib.h>	
#define DLAN 40

int main(void)
{
	int ch;
	FILE *we, *wy;									// wskazniki plikowe
	char nazwa_we[DLAN], nazwa_wy[DLAN];			// miejsca na nazwy plikow
	int licznik = 0;

	// plik wejsciowy
	puts("Podaj nazwe pliku zrodlowego:");
	wczytaj(nazwa_we, DLAN);
	if ( (we = fopen(nazwa_we, "r")) == NULL)
	{
		fprintf(stderr, "Nie moglem otworzyc pliku \"%s\"\n", nazwa_we);
		exit(EXIT_FAILURE);
	}

	// przygotowanie pliku wynikowego
	strncpy(nazwa_wy, nazwa_we, DLAN - 5);
	nazwa_wy[strlen(nazwa_wy) - 4] = '\0';
	strcat(nazwa_wy, ".red");
	if ( (wy = fopen(nazwa_wy, "w")) == NULL )
	{
		fprintf(stderr, "Nie mozna utworzyc pliku wyjsciowego.\n");
		exit(EXIT_FAILURE);
	} 

	// kopiowanie danych	
	while ( (ch = getc(we)) != EOF)
	{
		if (0 == licznik++ % 3)			// co trzeci znak
		{
			putc(ch, wy);				// wyslac do pliku wynikowego
		}
	}

	// sprzatanie
	if (fclose(we) != 0 || fclose(wy) != 0)
	{
		fprintf(stderr, "Blad przy zamykaniu plikow.\n");
	}
	return 0;
}