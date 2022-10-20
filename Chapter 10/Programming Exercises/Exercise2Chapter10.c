//  opis - Exercise2Chapter10.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void kopiuj_tab(const double tab_out[], double tab_in[], int rozmiar);
void kopiuj_wsk(const double * tab_out, double * tab_in, int rozmiar);
void kopiuj_wsk2(const double * tab_out_poczatek, double * tab_in, double * tab_out_koniec);
void pokaz_tab(const double * tab, int rozmiar);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double zrodlo[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double cel1[5];
	double cel2[5];
	double cel3[5];

	
/*  Description ---------------------------------------------------------------*/
	puts("Program inicjalizuje tablice, a nastepnie kopiuje jej zawartosc do dwoch innych tablic.\n");
	
/*  Code ----------------------------------------------------------------------*/
	
	puts("Przed:");
	pokaz_tab(cel1, 5);
	pokaz_tab(cel2, 5);
	pokaz_tab(cel3, 5);
	kopiuj_tab(zrodlo, cel1, 5);
	kopiuj_wsk(zrodlo, cel2, 5);
	kopiuj_wsk2(zrodlo, cel3, zrodlo + 5);
	puts("Po:");
	pokaz_tab(cel1, 5);
	pokaz_tab(cel2, 5);
	pokaz_tab(cel3, 5);

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
		tab_in[i] = tab_out[i];
	}
}

void kopiuj_wsk(const double * tab_out, double * tab_in, int rozmiar)
{
	int i;
	for (i = 0; i < rozmiar; i++)
	{
		*(tab_in + i) = *(tab_out + i);
	}
}

void kopiuj_wsk2(const double * tab_out_poczatek, double * tab_in, double * tab_out_koniec)
{
	int i;
	for (i = 0; i < (tab_out_koniec - tab_out_poczatek); i++)
	{
		*(tab_in + i) = *(tab_out_poczatek + i);
	}
}

void pokaz_tab(const double * tab, int rozmiar)
{
	int j;
	for (j = 0; j < rozmiar; j++)
	{
		printf("%.1f ", tab[j]);									// notacja tablicowa
	}
	putchar('\n');
}