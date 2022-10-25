// Program sluzy do sprawdzenia funkcji pobierania danych do tablicy 3x5,
// obliczen na tablicy 3x5 oraz wyswietlania wynikow - Exercise13Chapter10.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <float.h>
#define WIERSZE 3
#define KOLUMNY 5
void scanArray_dbl_2D(double (*array)[KOLUMNY], int dimY);
void pokaz_tab_2D(double (*tab)[KOLUMNY], int rozmiarY);
double srednia_z_tab_1D(const double * tab, int kolumny);
double srednia_z_tab_2D(double (*tab)[KOLUMNY], int wiersze);
double najwieksza_z_tab_2D(double (*tab)[KOLUMNY], int wiersze);


/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double tab[WIERSZE][KOLUMNY];
	int i;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program pobiera od uzytkownika dane do tablicy 3x5,\noblicza srednia dla kazdego zbioru z osobna,\noblicza srednia dla wszystkich wartosci,\nznajduje najwieksza sposrod 15 wartosci\noraz wyswietla wyniki.\n");

/*  Code ----------------------------------------------------------------------*/
	scanArray_dbl_2D(tab,WIERSZE);
	puts("\nDla tablicy");
	pokaz_tab_2D(tab,WIERSZE);
	puts("wyniki obliczen sa nastepujace:");

	for (i = 0; i < WIERSZE; i++)
	{
		printf("Dla %d. zbioru srednia arytmetyczna wynosi %g\n", i + 1, srednia_z_tab_1D(*(tab + i), KOLUMNY));
	}
	printf("Srednia dla wszystkich wartosci: %f\n", srednia_z_tab_2D(tab, WIERSZE));
	printf("Najwieksza sposrod 15 wartosci: %f\n", najwieksza_z_tab_2D(tab, WIERSZE));	
/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void scanArray_dbl_2D(double (*array)[KOLUMNY], int dimY)
{
	puts("Tablica uzupelnia sie od lewej do prawej i od gory do dolu.");
	puts("Prosze podac 15 wartosci:");
	int y, x;
	for (y = 0; y < dimY; y++)
	{
		for (x = 0; x < KOLUMNY; x++)
		{
			scanf(" %lf", (*(array + y) + x) );
		}
	}
}

void pokaz_tab_2D(double (*tab)[KOLUMNY], int rozmiarY)
{
	int y, x;
	for (y = 0; y < rozmiarY; y++)
	{
		printf("%d. zbior:", y + 1);
		for (x = 0; x < KOLUMNY; x++)
		{
			printf("%5.1f ", *(*(tab + y) + x) );
		}
		putchar('\n');
	}
}

double srednia_z_tab_1D(const double * tab, int kolumny)
{
	int k;
	double podsuma;
	for (k = 0, podsuma = 0.0; k < kolumny; k++)
	{
		podsuma += tab[k];
	}
	return podsuma/kolumny;
}

double srednia_z_tab_2D(double (*tab)[KOLUMNY], int wiersze)
{
	int k, w;
	double suma = 0.0;
	for (w = 0; w < wiersze; w++)
	{
		for (k = 0; k < KOLUMNY; k++)
		{
			suma += *(*(tab + w) + k);
		}
	}
	return suma / (wiersze * KOLUMNY);
}

double najwieksza_z_tab_2D(double (*tab)[KOLUMNY], int wiersze)
{
	int k, w;
	double max = (-1 * DBL_MAX);
	for (w = 0; w < wiersze; w++)
	{
		for (k = 0; k < KOLUMNY; k++)
		{
			if (*(*(tab + w) + k) > max)
			{
				max = *(*(tab + w) + k);
			}
		}
	}
	return max;
}