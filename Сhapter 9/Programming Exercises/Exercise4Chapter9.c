//  funkcja srednia_harmoniczna(a, b) - Exercise4Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
double srednia_harmoniczna(double a, double b);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double x, y;	
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje srednia_harmoniczna(a, b)");
	
/*  Code ----------------------------------------------------------------------*/
	printf("Podaj pierwsza liczbe: ");
	scanf("%lf", &x);
	printf("Podaj druga liczbe: ");
	scanf("%lf", &y);
	printf("Najmniejsza liczba to %lf.\n", srednia_harmoniczna(x, y));

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

double srednia_harmoniczna(double a, double b)
{
	return 2 / ((1 / a) + (1 / b));
}