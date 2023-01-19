// korzystanie z listy laczonej (linked list) struktur
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROZT 45

struct film {
	char tytul[ROZT];
	int ocena;
	struct film * nast;			// wskazuje na nastepna strukture w liscie
};
char * wczytaj(char * z, int ile);
int main(void)
{
	struct film * glowny = NULL;
	struct film * poprz, * biezacy;
	char wejscie[ROZT];

	// pobieranie i zapisywanie informacji
	puts("Podaj pierwszy tytul filmu:");
	while (wczytaj(wejscie, ROZT) != NULL && wejscie[0] != '\0')
	{
		biezacy = (struct film *) malloc(sizeof(struct film));
		if (NULL == glowny)
		{
			glowny = biezacy;			// pierwsza struktura
		}
		else
		{
			poprz->nast = biezacy;		// kolejne struktury
		}
		biezacy->nast = NULL;
		strcpy(biezacy->tytul, wejscie);

		puts("Podaj Twoja ocene <0-10>:");
		scanf("%d", &biezacy->ocena);
		while('\n' != getchar())
		{
			continue;
		}
		puts("Podaj nastepny tytul filmu (pusty wiersz konczy program):");
		poprz = biezacy;
	}
	if (NULL == glowny)
	{
		printf("Nie wpisano zadnych danych. ");
	}
	else
	{
		printf("Oto lista filmow:\n");
	}
	biezacy = glowny;
	while (NULL != biezacy)
	{
		printf("Film: %s  Ocena: %d\n", biezacy->tytul, biezacy->ocena);
		biezacy = biezacy->nast;
	}

	// przebieg programu zakonczony, zwlniamy przydzielona pamiec
	biezacy = glowny;
	while (NULL != biezacy)
	{
		poprz = biezacy;
		biezacy = poprz->nast;
		free(poprz);
	}

	printf("Do widzenia!\n");
	return 0;
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