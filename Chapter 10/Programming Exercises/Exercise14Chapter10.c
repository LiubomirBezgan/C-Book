// Program sluzy do sprawdzenia funkcji pobierania danych do VLA 3x5,
// obliczen na VLA 3x5 oraz wyswietlania wynikow - Exercise14Chapter10.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <float.h>
#define WIERSZE 3
#define KOLUMNY 5
void scanArray_dbl_2D_VLA(int dimY, int dimX, double array[dimY][dimX]);
void pokaz_tab_2D_VLA(int rozmiarY, int rozmiarX, double tab[rozmiarY][rozmiarX]);
double srednia_z_tab_1D_VLA(int kolumny, double tab[kolumny]);
double srednia_z_tab_2D_VLA(int wiersze, int kolumny, double tab[wiersze][kolumny]);
double najwieksza_z_tab_2D_VLA(int wiersze, int kolumny, double tab[wiersze][kolumny]);


/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double tab[WIERSZE][KOLUMNY];
	int i;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program pobiera od uzytkownika dane do tablicy 3x5,\noblicza srednia dla kazdego zbioru z osobna,\noblicza srednia dla wszystkich wartosci,\nznajduje najwieksza sposrod 15 wartosci\noraz wyswietla wyniki.\n");

/*  Code ----------------------------------------------------------------------*/
	scanArray_dbl_2D_VLA(WIERSZE, KOLUMNY, tab);
	puts("\nDla tablicy");
	pokaz_tab_2D_VLA(WIERSZE, KOLUMNY, tab);
	puts("wyniki obliczen sa nastepujace:");

	for (i = 0; i < WIERSZE; i++)
	{
		printf("Dla %d. zbioru srednia arytmetyczna wynosi %g\n", i + 1, srednia_z_tab_1D_VLA(KOLUMNY, *(tab + i)));
	}
	printf("Srednia dla wszystkich wartosci: %f\n", srednia_z_tab_2D_VLA(WIERSZE, KOLUMNY, tab));
	printf("Najwieksza sposrod 15 wartosci: %f\n", najwieksza_z_tab_2D_VLA(WIERSZE, KOLUMNY, tab));	
/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void scanArray_dbl_2D_VLA(int dimY, int dimX, double array[dimY][dimX])
{
	puts("Tablica uzupelnia sie od lewej do prawej i od gory do dolu.");
	puts("Prosze podac 15 wartosci:");
	int y, x;
	for (y = 0; y < dimY; y++)
	{
		for (x = 0; x < dimX; x++)
		{
			scanf(" %lf", (*(array + y) + x) );
		}
	}
}

void pokaz_tab_2D_VLA(int rozmiarY, int rozmiarX, double tab[rozmiarY][rozmiarX])
{
	int y, x;
	for (y = 0; y < rozmiarY; y++)
	{
		printf("%d. zbior:", y + 1);
		for (x = 0; x < rozmiarX; x++)
		{
			printf("%5.1f ", *(*(tab + y) + x) );
		}
		putchar('\n');
	}
}

double srednia_z_tab_1D_VLA(int kolumny, double tab[kolumny])
{
	int k;
	double podsuma;
	for (k = 0, podsuma = 0.0; k < kolumny; k++)
	{
		podsuma += tab[k];
	}
	return podsuma/kolumny;
}

double srednia_z_tab_2D_VLA(int wiersze, int kolumny, double tab[wiersze][kolumny])
{
	int k, w;
	double suma = 0.0;
	for (w = 0; w < wiersze; w++)
	{
		for (k = 0; k < kolumny; k++)
		{
			suma += *(*(tab + w) + k);
		}
	}
	return suma / (wiersze * KOLUMNY);
}

double najwieksza_z_tab_2D_VLA(int wiersze, int kolumny, double tab[wiersze][kolumny])
{
	int k, w;
	double max = (-1 * DBL_MAX);
	for (w = 0; w < wiersze; w++)
	{
		for (k = 0; k < kolumny; k++)
		{
			if (*(*(tab + w) + k) > max)
			{
				max = *(*(tab + w) + k);
			}
		}
	}
	return max;
}