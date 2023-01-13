// sortuje zbior liczb za pomoca funkcji qsort()
#include <stdio.h>
#include <stdlib.h>

#define NUM 40

void wypelnij_tab(double tab[], int n);
void pokaz_tab(const double tab[], int n);
int porownaj(const void * w1, const void * w2);


int main(void)
{
	double wart[NUM];
	wypelnij_tab(wart, NUM);
	puts("Lista losowa:");
	pokaz_tab(wart, NUM);
	qsort(wart, NUM, sizeof(double), porownaj);
	puts("\nLista uporzadkowana:");
	pokaz_tab(wart, NUM);
	return 0;
}

void wypelnij_tab(double tab[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		tab[i] = (double)rand() / ( (double)rand() + 0.1 );
	}
}

void pokaz_tab(const double tab[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%9.4f ", tab[i]);
		if (5 == i % 6)
		{
			putchar('\n');
		}
	}
		if (0 != i % 6)
	{
		putchar('\n');
	}
}

int porownaj(const void * w1, const void * w2)
{
	// do odczytania wartosci potrzebne sa wskazniki do double
	const double * a1 = (const double *) w1;
	const double * a2 = (const double *) w2;

	if (*a1 < *a2)
	{
		return -1;
	}
	else if (*a1 == *a2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}