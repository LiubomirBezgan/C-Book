// Exercise2Chapter17-Program.c - korzystanie z listy laczonej zgodnie z ATD
// kompilowac z plikiem Exercise2Chapter17-Implementation.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Exercise2Chapter17.h"
void pokazfilm(Pozycja pozycja);
char * wczytaj(char * z, int ile);

int main(void)
{
	Lista filmy;
	Pozycja tymcz;

	// inicjalizacja
	InicjujListe(&filmy);
	if (PelnaLista(&filmy))
	{
		fprintf(stderr, "Brak pamieci! Do widzenia!\n");
		exit(1);
	}

	// wczytywanie i zapis danych
	puts("Podaj pierwszy tytul filmu");
	while (NULL != wczytaj(tymcz.tytul, ROZT) && '\0' != tymcz.tytul[0])
	{
		puts("Podaj twoja ocene <0-10>:");
		scanf("%d", &tymcz.ocena);
		while('\n' != getchar())
		{
			continue;
		}
		if (false == DodajPozycje(tymcz, &filmy))
		{
			fprintf(stderr, "Blad alokacji pamieci\n");
			break;			
		}
		if (PelnaLista(&filmy))
		{
			puts("Lista jest juz pelna.");
			break;
		}
		puts("Podaj nastepny tytul filmu (pusty wiersz konczy wpisywanie):");
	}

	// wpisywanie zawartosci listy
	if (PustaLista(&filmy))
	{
		puts("Nie wpisano zadnych danych.");
	}
	else
	{
		puts("Oto lista filmow:");
		Przejdz(&filmy, pokazfilm);
		puts("\nA teraz w odwrotnej kolejnosci:");
		OdKonca(&filmy, pokazfilm);		
	}
	printf("\nWpisales %d filmow.\n", LiczbaPozycji(&filmy));

	// porzadki
	CzyscListe(&filmy);
	puts("Do widzenia!");
	return 0;
}

void pokazfilm(Pozycja pozycja)
{
	printf("Film: %s  Ocena: %d\n", pozycja.tytul, pozycja.ocena);
}

char * wczytaj(char * z, int ile)
{
	char * wynik;
	char * tutaj;
	wynik = fgets(z, ile, stdin);
	if (wynik)
	{
		tutaj = strchr(z, '\n');
		if (tutaj)
		{

			*tutaj = '\0';
		}
		else
		{
			while('\n' != getchar())
			{
				continue;
			}
		}
	}
	return wynik;
}