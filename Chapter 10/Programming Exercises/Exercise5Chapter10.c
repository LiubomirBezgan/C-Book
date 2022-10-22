//  Tablice. Roznica miedzy najwieksza i najmniejsza wartosciami wynosi - Exercise5Chapter10.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <float.h>
float roznica(int rozmiar, float tab[rozmiar]);
void scanArray_flt(int length, float array[length]);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int rozmiar;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program pobiera wartosci i wyswietla roznice miedzy najwieksza i najmniejsza.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Ile liczb planujesz wprowadzic?");
	scanf("%d", &rozmiar);
	float tab[rozmiar];
	scanArray_flt(rozmiar, tab);
	printf("Roznica miedzy najwieksza i najmniejsza wartosciami wynosi %f", roznica(rozmiar, tab));

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void scanArray_flt(int length, float array[length])
{
	int i;
	puts("Podaj wartosci:");
	for (i = 0; i < length; i++)
	{
		scanf(" %f", &array[i]);									// notacja tablicowa
	}
}

float roznica(int rozmiar, float tab[rozmiar])
{
	int i;
	float max = (-1 * FLT_MAX);				// najmniejsza ujemna liczba zmiennoprzecinkowa
	float min = FLT_MAX;
	for (i = 0; i < rozmiar; i++)
	{
		if (tab[i] > max)
		{
			max = tab[i];
		}
		if (tab[i] < min)
		{
			min = tab[i];
		}
	}
	return max - min;
}