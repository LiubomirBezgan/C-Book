//  zmniejsza rozmiar Twoich plikow o dwie trzecie - Listing_13_2.c
//  v1.1
#include <stdio.h>
#include <stdlib.h>				// prototyp funkcji exit()
#include <string.h>	
#define DL 40

int main(int argc, char * argv[])
{
	int ch;
	FILE *we, *wy;			// wskazniki plikowe
	char nazwa[DL];			// miejsce na nazwy pliku wyjsciowego
	int licznik = 0;

	if (argc < 2)
	{
		printf("Sposob uzycia: %s nazwa_pliku\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// plik wejsciowy
	if ( (we = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Nie moglem otworzyc pliku \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// przygotowanie pliku wynikowego
	strncpy(nazwa, argv[1], DL-5);
	nazwa[strlen(nazwa) - 4] = '\0';
	strcat(nazwa, ".red");

	if ( (wy = fopen(nazwa, "w")) == NULL)
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