// stosowanie funkcji memcpy() i memmove()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 10

void pokaz_tablice(const int tab[], int n);

_Static_assert(sizeof(double) == 2 * sizeof(int), "double nie jest 2-krotnie wiekszy niz int");

int main(void)
{
	int zrodlo[ROZMIAR] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int cel[ROZMIAR];
	double ciekawostka[ROZMIAR / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 2.0e30};

	puts("uzyto memcpy():");
	puts("zrodlo (dane oryginalne):");
	pokaz_tablice(zrodlo, ROZMIAR);
	memcpy(cel, zrodlo, ROZMIAR * sizeof(int));
	puts("cel (kopiowanie zrodla):");
	pokaz_tablice(cel, ROZMIAR);
	puts("\nUzycie funkcji memmove() z nakladajacymi sie obszarami:");
	memmove(zrodlo + 2, zrodlo, 5 * sizeof(int));
	puts("zrodlo -- elementy 0-5 kopiowanie do 2-7:");
	pokaz_tablice(zrodlo, ROZMIAR);

	puts("\nUzycie memcpy() do skopiowania double do int:");
	memcpy(cel, ciekawostka, (ROZMIAR / 2) * sizeof(double));
	puts("cel -- 5 double do 10 int:");
	pokaz_tablice(cel, ROZMIAR);
	pokaz_tablice(cel + 5, ROZMIAR / 2);	

	return 0;
}

void pokaz_tablice(const int tab[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", tab[i]);
	}
	putchar('\n');
}