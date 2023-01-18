// korzystanie z tablicy struktur
#include <stdio.h>
#include <string.h>
#define ROZT 45
#define FMAX 5
struct film {
	char tytul[ROZT];
	int ocena;
};
char * wczytaj(char * z, int ile);
int main(void)
{
	struct film filmy[FMAX];				// mozna rozwiazac problem nieelastycznosci, uzywajac funkcji malloc()
	int i = 0;
	int j;
	puts("Podaj pierwszy tytul filmu:");
	while (i < FMAX && wczytaj(filmy[i].tytul, ROZT) != NULL && filmy[i].tytul[0] != '\0')
	{
		puts("Podaj Twoja ocene <0-10>:");
		scanf("%d", &filmy[i++].ocena);
		while('\n' != getchar())
		{
			continue;
		}
		puts("Podaj nastepny tytul filmu (pusty wiersz konczy program):");
	}
	if (0 == i)
	{
		printf("Nie wpisano zadnych danych. ");
	}
	else
	{
		printf("Oto lista filmow:\n");
	}
	for (j = 0; j < i; j++)
	{
		printf("Film: %s  Ocena: %d\n", filmy[j].tytul, filmy[j].ocena);
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