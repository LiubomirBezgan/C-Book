//  mniejsza z dwoch wartosci - Exercise1Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
double min(double x, double y);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double x, y;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje min(x, y).");
	
/*  Code ----------------------------------------------------------------------*/
	printf("\nPodaj pierwsza liczbe: ");
	scanf("%lf", &x);
	printf("\nPodaj druga liczbe: ");
	scanf("%lf", &y);
	printf("Najmniejsza liczba to %lf.\n", min(x, y));

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

double min(double x, double y)
{
	if (x > y)
		return y;
	else
		return x;
}