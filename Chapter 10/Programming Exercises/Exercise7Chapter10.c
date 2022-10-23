//  Kopiowanie tablic 2D - Exercise7Chapter10.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#define WIERSZE 3
#define KOLUMNY 5
void pokaz_tab(const double * tab, int rozmiarX);
void pokaz_tab_2D(double tab[][KOLUMNY], int rozmiarY);
void kopiuj_tab(const double tab_out[], double tab_in[], int rozmiarX);
void kopiuj_tab_2D(const double tab_out[][KOLUMNY], double tab_in[][KOLUMNY], int rozmiarY);
void kopiuj_wsk(const double * tab_out, double * tab_in, int rozmiarX);
void kopiuj_wsk_2D(const double (*tab_out)[KOLUMNY], double (*tab_in)[KOLUMNY], int rozmiarY);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	const double zrodlo[WIERSZE][KOLUMNY] = 
	{
		{1.1, 2.2, 3.3, 4.4, 5.5},
		{6.6, 7.7, 8.8, 9.9, 1.2},
		{2.3, 3.4, 4.5, 5.6, 6.7}
	};
	double cel1[WIERSZE][KOLUMNY];
	double cel2[WIERSZE][KOLUMNY];

/*  Description ---------------------------------------------------------------*/
	puts("Program inicjalizuje tablice dwuwymiarowa, a nastepnie kopiuje jej zawartosc do dwoch innych tablic.");
	
/*  Code ----------------------------------------------------------------------*/
	puts("\nPrzed");
	pokaz_tab_2D(cel1, WIERSZE);
	putchar('\n');
	pokaz_tab_2D(cel2, WIERSZE);

	kopiuj_tab_2D(zrodlo, cel1, WIERSZE);
	kopiuj_wsk_2D(zrodlo, cel2, WIERSZE);

	puts("\nPo");
	pokaz_tab_2D(cel1, WIERSZE);
	putchar('\n');
	pokaz_tab_2D(cel2, WIERSZE);
/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void pokaz_tab(const double * tab, int rozmiarX)
{
	int j;
	for (j = 0; j < rozmiarX; j++)
	{
		printf("%.1f ", tab[j]);									// notacja tablicowa
	}
	putchar('\n');
}

void pokaz_tab_2D(double tab[][KOLUMNY], int rozmiarY)
{
	int i;
	for (i = 0; i < rozmiarY; i++)
	{
		pokaz_tab(tab[i], KOLUMNY);
	}
}

void kopiuj_tab(const double tab_out[], double tab_in[], int rozmiarX)
{
	int i;
	for (i = 0; i < rozmiarX; i++)
	{
		tab_in[i] = tab_out[i];
	}
}

void kopiuj_tab_2D(const double tab_out[][KOLUMNY], double tab_in[][KOLUMNY], int rozmiarY)
{
	int i;
	for (i = 0; i < rozmiarY; i++)
	{
		kopiuj_tab(tab_out[i], tab_in[i], KOLUMNY);
	}
}

void kopiuj_wsk(const double * tab_out, double * tab_in, int rozmiarX)
{
	int i;
	for (i = 0; i < rozmiarX; i++)
	{
		*(tab_in + i) = *(tab_out + i);
	}
}

void kopiuj_wsk_2D(const double (*tab_out)[KOLUMNY], double (*tab_in)[KOLUMNY], int rozmiarY)
{
	int k;
	for (k = 0; k < rozmiarY; k++)
	{
		kopiuj_wsk(*(tab_out + k), *(tab_in + k), KOLUMNY);
	}
}