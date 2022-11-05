//  test funkcji zapisz_znaki_do_tablicy() - Exercise1Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#define ROZMIAR 81
void zapisz_znaki_do_tablicy(unsigned int liczba_znakow, char * do_tablicy);


/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	unsigned int ile_znakow;
	char tablica[ROZMIAR];
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje, ktora pobiera z klawiatury najblizsze n znakow\ni zapisuje wynik do tablicy przekazanej przez adres argumentem wywolania funkcji.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Ile znakow chcesz zapisac do tablicy?");
	scanf("%u", &ile_znakow);
	while (getchar() != '\n')
	{
		continue;
	}
	zapisz_znaki_do_tablicy(ile_znakow, tablica);
	puts("Oto wynik:");
	puts(tablica);
/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

void zapisz_znaki_do_tablicy(unsigned int liczba_znakow, char * do_tablicy)
{
	int i = 0;
	while (i++ < liczba_znakow && (*do_tablicy++ = getchar()) != EOF)
	{
		continue;
	}
	*do_tablicy = '\0';
}