//  test funkcji zawiera_lan() - Exercise8Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <stdbool.h>
#define ROZMIAR 81
char * zawiera_lan(const char * w_lancuchu, const char * szukany_lan); 
char pobierz_znak(void);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char tablica1[ROZMIAR];
	char tablica2[ROZMIAR];
	char * wsk;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje zawiera_lan(), ktora sprawdza,\nczy w pierwszym lancuchu wystapuje drugi lancuch.\n");

/*  Code ----------------------------------------------------------------------*/
	puts("Podaj pierwszy lancuch:");
	wczytaj(tablica1, ROZMIAR);
	puts("Podaj drugi lancuch:");
	wczytaj(tablica2, ROZMIAR);
	printf("Lancuch 1 to: %s\n", tablica1);
	printf("Lancuch 2 to: %s\n", tablica2);

	wsk = zawiera_lan(tablica1, tablica2);
	puts("Sprawdzenie:");
	if (wsk == NULL)
	{
		puts("NULL");
	}
	else
	{
		puts(wsk);
	}

/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

char * zawiera_lan(const char * w_lancuchu, const char * szukany_lan)
{
	char * wsk;
	while (*w_lancuchu != *szukany_lan)
	{
		if (*w_lancuchu == '\0')
		{
			return NULL;
		}	
		w_lancuchu++;
	}
	wsk = (char *) w_lancuchu;
	while (*szukany_lan != '\0')
	{
		if (*szukany_lan != *w_lancuchu)
		{
			return NULL;
		}
		else
		{
			szukany_lan++;
			w_lancuchu++;
		}
	}

	return wsk;
}
