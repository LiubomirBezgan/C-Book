//  sprawdzenie funkcji pobierz_pierwszy() z listingu 8.8 - Exercise6Chapter8.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int ch;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program wyswietla pierwszy napotkany znak drukowany.");
	
/*  Code ----------------------------------------------------------------------*/
	while (!isgraph(ch = getchar()))		// pobranie pierwszego znaku drukowanego
		continue;
	while (getchar() != '\n')
		continue;							// czyszczenie bufora
	printf("Pierwszy napotkany znak drukowany to %c\n", ch);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}