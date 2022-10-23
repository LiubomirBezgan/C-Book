//  VLA do kopiowania i wyswietlania tablic dwuwymiarowych - Exercise9Chapter10.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#define WIERSZE 3
#define KOLUMNY 5
#include <stdio.h>
void kopiuj_tab_2D_VLA(int rozmiarY, int rozmiarX, double tab_out[rozmiarY][rozmiarX], double tab_in[rozmiarY][rozmiarX]);
void pokaz_tab_2D_VLA(int rozmiarY, int rozmiarX, double tab[rozmiarY][rozmiarX]);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double zrodlo[WIERSZE][KOLUMNY] = 
	{
		{1.1, 2.2, 3.3, 4.4, 5.5},
		{6.6, 7.7, 8.8, 9.9, 1.2},
		{2.3, 3.4, 4.5, 5.6, 6.7}
	};
	double cel[WIERSZE][KOLUMNY];
	
/*  Description ---------------------------------------------------------------*/
	puts("Program korzysta z funkcji uzywajacych VLA do kopiowania i wyswietlania tablic dwuwymiarowych.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("zrodlo:");
	pokaz_tab_2D_VLA(WIERSZE, KOLUMNY, zrodlo);
	puts("cel:");
	pokaz_tab_2D_VLA(WIERSZE, KOLUMNY, cel);

	puts("\nPo kopiowaniu:");
	kopiuj_tab_2D_VLA(WIERSZE, KOLUMNY, zrodlo, cel);

	puts("zrodlo:");
	pokaz_tab_2D_VLA(WIERSZE, KOLUMNY, zrodlo);
	puts("cel:");
	pokaz_tab_2D_VLA(WIERSZE, KOLUMNY, cel);
/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void pokaz_tab_2D_VLA(int rozmiarY, int rozmiarX, double tab[rozmiarY][rozmiarX])
{
	int y, x;
	for (y = 0; y < rozmiarY; y++)
	{
		for (x = 0; x < rozmiarX; x++)
		{
			printf("%.1f ", tab[y][x]);
		}
		putchar('\n');
	}
}

void kopiuj_tab_2D_VLA(int rozmiarY, int rozmiarX, double tab_out[rozmiarY][rozmiarX], double tab_in[rozmiarY][rozmiarX])
{
	int y, x;
	for (y = 0; y < rozmiarY; y++)
	{
		for (x = 0; x < rozmiarX; x++)
		{
			tab_in[y][x] = tab_out[y][x];
		}
	}
}