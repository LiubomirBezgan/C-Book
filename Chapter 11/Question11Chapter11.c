// Question11Chapter11.c
#include <stdio.h>
#include <string.h>
#define DLUGOSC 10
char * wczytaj(char *z, int ile);

int main(void)
{
	char slowa[DLUGOSC];

	puts("Prosze wprowadzic lancuch (pusty wiersz zakonczy program):");
	
	while (wczytaj(slowa, DLUGOSC) != NULL && slowa[0] != '\0')
	{
		puts(slowa);
	}
	puts("Gotowe.");
	return 0;
}

char * wczytaj(char *z, int ile)
{
	char * wynik;
	char * koniec;
	wynik = fgets(z, ile, stdin);
	if (wynik)							// wynik rozny od NULL
	{
		if ((koniec = strchr(wynik, '\n')))
		{
			*koniec = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return wynik;
}