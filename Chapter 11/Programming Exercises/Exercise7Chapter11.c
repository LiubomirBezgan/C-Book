//  test funkcji mystrncpy() - Exercise7Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <string.h>
#include <stdbool.h>
#define ROZMIAR 81
char * mystrncpy(char * do_tablicy, const char * z_tablicy, unsigned int n);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char tablica1[ROZMIAR];
	char tablica2[ROZMIAR];
	unsigned int ile_znakow;

/*  Description ---------------------------------------------------------------*/
	puts("Program testuje odpowiednik funkcji strncpy().\n");

/*  Code ----------------------------------------------------------------------*/
	puts("Podaj tekst do pierwszej tablicy:");
	wczytaj(tablica1, ROZMIAR);
	puts("Podaj tekst do drugiej tablicy:");
	wczytaj(tablica2, ROZMIAR);
	printf("Tablica 1 to: %s\n", tablica1);
	printf("Tablica 2 to: %s\n", tablica2);

	puts("Ile znakow chcesz zapisac do pierwszej tablicy?");
	scanf("%u", &ile_znakow);
	while (getchar() != '\n')
	{
		continue;
	}
	//puts("Wynik strncpy():");
	//puts(strncpy(tablica1, tablica2, ile_znakow));
	puts("Wynik mystrncpy():");
	puts(mystrncpy(tablica1, tablica2, ile_znakow));
	printf("Tablica 1 to: %s\n", tablica1);

/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

char * mystrncpy(char * do_tablicy, const char * z_tablicy, unsigned int n)
{
	bool poza_lancuchem = false;
	int licznik = 0;
	char * wsk = do_tablicy;
	while (licznik++ < n && !poza_lancuchem)
	{
		if (*z_tablicy == '\0')
		{
			poza_lancuchem = false;
		}
			*wsk++ = *z_tablicy++;
	}
	while (licznik++ < n && poza_lancuchem)
	{
		*wsk++ = '\0';
	}
	return do_tablicy;
}