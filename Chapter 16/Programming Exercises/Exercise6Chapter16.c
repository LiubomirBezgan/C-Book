//  Sortowanie struktur (wedlug nazwiska i imienia) - Exercise6Chapter16.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 40
#define FAMILY 6

typedef struct osoba {
	char imie[NUM];
	char nazwisko[NUM];
} osoba_t;

void pokaz_tab(const osoba_t * tab, int n);
int porown(const void * w1, const void * w2);

int main(void)
{
	//double wart[NUM];
	osoba_t jjba[FAMILY] = {
		{"Joseph", "Joestar"},
		{"Jotaro", "Kujo"},
		{"Josuke", "Higashikata"},
		{"Jonathan", "Joestar"},
		{"Giorno", "Giovanna"},
		{"Jolyne", "Cujoh"}
	};
	puts("Lista losowa:");
	pokaz_tab(jjba, FAMILY);
	qsort(jjba, FAMILY, sizeof(osoba_t), porown);
	puts("\nLista uporzadkowana:");
	pokaz_tab(jjba, FAMILY);
	return 0;
}


void pokaz_tab(const osoba_t * tab, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%-10s %-12s\n", tab[i].imie, tab[i].nazwisko);
	}
}

int porown(const void * w1, const void * w2)
{
	// do odczytania wartosci potrzebne sa wskazniki do wlasciwego typu
	const osoba_t * ws1 = (const osoba_t *) w1;
	const osoba_t * ws2 = (const osoba_t *) w2;
	int wynik;

	wynik = strcmp(ws1->nazwisko, ws2->nazwisko);		// porownuje nazwiska

	if (wynik != 0)
	{
		return wynik;
	}
	else					// jesli nazwiska sa identyczne
	{
		return strcmp(ws1->imie, ws2->imie);
	}
}