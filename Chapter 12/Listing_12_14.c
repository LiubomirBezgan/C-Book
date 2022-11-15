//  dynamiczne konstruowanie tablic - Listing_12_14.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double * wsk;
	int max = 0;
	int liczba;
	int i = 0;

	puts("Podaj maksymalna liczbe elementow (typu double):");
	if (scanf("%d", &max) != 1)
	{
		puts("Niepoprawna liczba, do widzenia.");
		exit(EXIT_FAILURE);
	}
	wsk = (double *) malloc(max * sizeof(double)); // rzutowanie ulatwia przeniesienie kodu z C do C++
	if (wsk == NULL)
	{
		puts("Przydzial pamieci nie powiodl sie.");
		exit(EXIT_FAILURE);
	}

		puts("Podaj elementy (k to koniec):");
		while (i < max && scanf("%lf", &wsk[i]) == 1)
		{
			++i;
		}
		printf("Oto %d wprowadzonych elementow:\n", liczba = i);
		for (i = 0; i < liczba; i++)
		{
			printf("%7.2f ", wsk[i]);
			if (i % 7 == 6)
			{
				putchar('\n');
			}
		}
		if (i % 7 != 0)
		{
			putchar('\n');			
		}
		puts("Koniec.");
		free(wsk);
	return 0;
}