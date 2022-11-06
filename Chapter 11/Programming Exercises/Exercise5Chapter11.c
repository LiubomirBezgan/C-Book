//  test funkcji wyszukaj_znak() - Exercise5Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#define ROZMIAR 81
char * wyszukaj_znak(const char * w_tablicy, char znak);
char pobierz_znak(void);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char tablica[ROZMIAR];
	char znak;
	char * wsk;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje, ktora wyszukuje w lancuchu pierwsze wystapienie znaku.\n");

/*  Code ----------------------------------------------------------------------*/
	puts("Wpisz pusty wiersz, aby zakonczyc.");
	znak = pobierz_znak();
	while (znak != '\n')
	{
		puts("Podaj tekst:");
		wczytaj(tablica, ROZMIAR);
		wsk = wyszukaj_znak(tablica, znak);
		if (wsk == NULL)
		{
			puts("NULL");
		}
		else
		{
			puts(wsk);
		}
		putchar('\n');
		znak = pobierz_znak();
	}

/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

char * wyszukaj_znak(const char * w_tablicy, char znak)
{
	while (*w_tablicy != znak)
	{
		if (*w_tablicy == '\0')
		{
			return NULL;
		}	
		w_tablicy++;
	}
	return (char *) w_tablicy;			// odrzucenie const
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