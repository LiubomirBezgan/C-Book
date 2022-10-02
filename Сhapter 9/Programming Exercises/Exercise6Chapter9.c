//  funkcja porzadek(&a, &b, &c) - Exercise6Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void porzadek(double * a, double * b, double * c);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double x, y, z;	
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje porzadek(&a, &b, &c)");
	
/*  Code ----------------------------------------------------------------------*/
	printf("Podaj 1. liczbe, ktora bedzie przechowywac sie pod adresem %p: ", &x);
	scanf("%lf", &x);
	printf("Podaj 2. liczbe, ktora bedzie przechowywac sie pod adresem %p: ", &y);
	scanf("%lf", &y);
	printf("Podaj 3. liczbe, ktora bedzie przechowywac sie pod adresem %p: ", &z);
	scanf("%lf", &z);
	porzadek(&x, &y, &z);
	printf("Teraz pod adresem %p jest przechowywana wartosc %lf.\n", &x, x);
	printf("Teraz pod adresem %p jest przechowywana wartosc %lf.\n", &y, y);
	printf("Teraz pod adresem %p jest przechowywana wartosc %lf.\n", &z, z);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void porzadek(double * a, double * b, double * c)
{
	double temp;

	if (*a > *b)
	{
		temp = *b;
		*b = *a;
		*a = temp;
	}
	if (*b > *c)
	{
		temp = *c;
		*c = *b;
		*b = temp;
	}
	if (*a > *b)
	{
		temp = *b;
		*b = *a;
		*a = temp;
	}
}