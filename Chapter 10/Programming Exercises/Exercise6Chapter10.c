//  Tablice. Odwrócenie kolejnosci elementow tablicy - Exercise6Chapter10.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void changeling(double * tab, int rozmiar);
void scanArray_dbl(double * array, int length);
void printArray(const double * array, int length);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int rozmiar;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program pobiera wartosci i wyswietla je w owdrotnej kolejnosci.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Ile liczb planujesz wprowadzic?");
	scanf("%d", &rozmiar);
	double tab[rozmiar];
	scanArray_dbl(tab, rozmiar);
	
	printf("\nPierwotna tablica: ");
	printArray(tab, rozmiar);

	changeling(tab, rozmiar);
	printf("\n    Po odwroceniu: ");
	printArray(tab, rozmiar);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void changeling(double * tab, int rozmiar)
{
	int i;
	double temp;
	for (i = 0; i < rozmiar / 2; i++)
	{
		temp = tab[i];
		tab[i] = tab[rozmiar - i - 1];
		tab[rozmiar - i - 1] = temp;;
	}
}

void scanArray_dbl(double * array, int length)
{
	int i;
	puts("Podaj wartosci:");
	for (i = 0; i < length; i++)
	{
		scanf(" %lf", &array[i]);									// notacja tablicowa
	}
}

void printArray(const double * array, int length)
{
	int j;
	for (j = 0; j < length; j++)
	{
		printf("%f ", array[j]);									// notacja tablicowa
	}
}