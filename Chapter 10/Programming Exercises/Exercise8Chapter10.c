//  kopiowanie okreslonych elementow tablicy - Exercise8Chapter10.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void pokaz_tab(const double * tab, int rozmiar);
void kopiuj_tab(const double tab_out[], double tab_in[], int rozmiar);	// notacja tablicowa
void kopiuj_wsk(const double * tab_out, double * tab_in, int rozmiar);	// notacja wskaznikowa

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double zrodlo[7] = {1.38, 2.28, 3.14, 4.04, 5.05, 6.66, 7.77};
	double cel1[3], cel2[3];	
	
/*  Description ---------------------------------------------------------------*/
	puts("Program inicjalizuje siedmioelementowa tablice i kopiuje 3., 4. i 5. elementy do trzyelementowej tablicy\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Przed:");
	pokaz_tab(cel1, 3);
	pokaz_tab(cel2, 3);
	kopiuj_tab(&zrodlo[2], cel1, 3);									// notacja tablicowa
	kopiuj_wsk(zrodlo + 2, cel2, 3);									// notacja wskaznikowa
	puts("Po:");
	printf("  Notacja tablicowa: ");
	pokaz_tab(cel1, 3);
	printf("Notacja wskaznikowa: ");
	pokaz_tab(cel2, 3);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void kopiuj_tab(const double tab_out[], double tab_in[], int rozmiar)
{
	int i;
	for (i = 0; i < rozmiar; i++)
	{
		tab_in[i] = tab_out[i];											// notacja tablicowa
	}
}

void kopiuj_wsk(const double * tab_out, double * tab_in, int rozmiar)
{
	int i;
	for (i = 0; i < rozmiar; i++)
	{
		*(tab_in + i) = *(tab_out + i);									// notacja wskaznikowa
	}
}

void pokaz_tab(const double * tab, int rozmiar)
{
	int j;
	for (j = 0; j < rozmiar; j++)
	{
		printf("%.2f ", tab[j]);										// notacja tablicowa
	}
	putchar('\n');
}