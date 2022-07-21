// Zenon z Elei - Listing_6_14.c
// uzycie w jednym wyrazeniu wiecej niz jednego operatora ","
// v1.0
#include <stdio.h>

int main(void)
{
	int licznik, granica;
	double czas, potega_2;

	puts("Ile wyrazow chcesz zsumowac?");
	scanf("%d", &granica);

	for (czas=0, potega_2=1, licznik=1; licznik <= granica; licznik++,
		potega_2 *= 2.0)
	{
		czas += 1.0/potega_2;
		printf("czas = %f, gdy licznik = %d.\n", czas, licznik);
	}

	getchar();
	getchar();
	return 0;
}