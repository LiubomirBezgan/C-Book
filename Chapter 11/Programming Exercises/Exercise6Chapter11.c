//  test funkcji znajduje_sie_w() - Exercise6Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <stdbool.h>
#define ROZMIAR 81
bool znajduje_sie_w(char znak, const char * w_tablicy);
char pobierz_znak(void);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char tablica[ROZMIAR];
	char znak;
	bool odpowiedz;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje, ktora sprawdza czy w lancuchu wystapuje podany znak.\n");

/*  Code ----------------------------------------------------------------------*/
	puts("Wpisz pusty wiersz, aby zakonczyc.");
	znak = pobierz_znak();
	while (znak != '\n')
	{
		puts("Podaj tekst:");
		wczytaj(tablica, ROZMIAR);
		odpowiedz = znajduje_sie_w(znak, tablica);
		printf("%s\n", odpowiedz ? "true" : "false");
		putchar('\n');
		znak = pobierz_znak();
	}

/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

bool znajduje_sie_w(char znak, const char * w_tablicy)
{
	while (*w_tablicy != znak)
	{
		if (*w_tablicy == '\0')
		{
			return false;
		}	
		w_tablicy++;
	}
	return true;
}

char pobierz_znak(void)
{
	char znak;
	puts("Podaj szukany znak:");
	znak = getchar();
	while (getchar() != '\n')
	{
		continue;
	}
	return znak;
}