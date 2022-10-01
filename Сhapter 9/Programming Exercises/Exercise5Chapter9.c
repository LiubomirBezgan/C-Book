//  funkcja wieksze_od(a, b) - Exercise5Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void wieksze_od(double * a, double * b);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double x, y;	
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje wieksze_od(&a, &b)");
	
/*  Code ----------------------------------------------------------------------*/
	printf("Podaj pierwsza liczbe: ");
	scanf("%lf", &x);
	printf("Podaj druga liczbe: ");
	scanf("%lf", &y);
	wieksze_od(&x, &y);
	printf("Teraz x = %lf, a y = %lf.", x, y);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void wieksze_od(double * a, double * b)
{
	if (*a > *b)
		*b = *a;
	else
		*a = *b;
}