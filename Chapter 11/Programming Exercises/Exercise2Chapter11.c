//  test funkcji zapisz_znaki_do_tablicy_bez_sapcji() - Exercise2Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <ctype.h>
#define ROZMIAR 81
void zapisz_znaki_do_tablicy_bez_sapcji(unsigned int liczba_znakow, char * do_tablicy);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	unsigned int ile_znakow;
	char tablica[ROZMIAR];
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje, ktora pobiera z klawiatury najblizsze n znakow\ni zapisuje wynik do tablicy przekazanej przez adres argumentem wywolania funkcji.");
	puts("Program zatrzymuje zapisywanie, gdy napotka znak bialy.\n");

/*  Code ----------------------------------------------------------------------*/
	puts("Ile znakow chcesz zapisac do tablicy?");
	scanf("%u", &ile_znakow);
	while (getchar() != '\n')
	{
		continue;
	}
	zapisz_znaki_do_tablicy_bez_sapcji(ile_znakow, tablica);
	puts("Oto wynik:");
	puts(tablica);
/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

void zapisz_znaki_do_tablicy_bez_sapcji(unsigned int liczba_znakow, char * do_tablicy)
{
	int i = 0;
	while (i++ < liczba_znakow && ((*do_tablicy = getchar()) != EOF) && (!isspace(*do_tablicy++)))
	{
		continue;
	}
	*do_tablicy = '\0';
}