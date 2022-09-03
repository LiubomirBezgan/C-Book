//  liczenie znakow - Exercise1Chapter8.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int liczba_znakow = 0;
/*  Description ---------------------------------------------------------------*/
	puts("Program sluzy do zliczania znakow wpisywanych lub pobieranych z pliku.");
	puts("W celu zakonczenia zliczania nalezy zasymulowac EOF (Ctrl+Z).");
/*  Code ----------------------------------------------------------------------*/
	while (getchar() != EOF)
		liczba_znakow++;
	printf("Liczba znakow wynosi %d", liczba_znakow);
	return 0;
}