//  test funkcji nowa_tablica(), wykorzystujacej zmienna liczbe argumentow - Exercise7Chapter16.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void pokaz_tablice(const double tab[], int n);
double * nowa_tablica(int n, ...);

int main (void)
{
	double * w1;
	double * w2;
	w1 = nowa_tablica(5, 1.2, 2.3, 3.4, 4.5, 5.6);
	w2 = nowa_tablica(4, 100.0, 20.00, 8.08, -1890.0);
	pokaz_tablice(w1, 5);
	pokaz_tablice(w2, 4);
	free(w1);
	free(w2);
	return 0;
}

void pokaz_tablice(const double tab[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%8.2f    ", tab[i]);
	}
	putchar('\n');
}

double * nowa_tablica(int n, ...)
{
	va_list ap;									// deklaracja obiektu przechowujacego argumenty
	int i;
	double * pt_array;
	pt_array = (double *) malloc(n * sizeof(double));
	va_start(ap, n);							// zainicjalizowanie ap lista argumentow
	for (i = 0; i < n; i++)
	{
		*(pt_array + i) = va_arg(ap, double);	// dostep do kazdego elementu w liscie argumentow
	}
	va_end(ap);									// czyszczenie
	return pt_array;
}