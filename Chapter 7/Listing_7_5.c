// uzycie zagniezdzonych struktur if do znalezienia dzielnikow liczby - Listing_7_5.c
// v1.0
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	unsigned long num;
	unsigned long dziel;
	bool pierwsza;
	printf("Podaj dodatnia liczbe calkowita do zanalizowania; ");
	puts("Wpisz 'q', aby zakonczyc.");
	while (scanf("%lu", &num) == 1)
	{
		for (dziel = 2, pierwsza = true; (dziel * dziel) <= num; dziel++)
		{
			if (num % dziel == 0)
			{
				if ((dziel * dziel) != num)
					printf("%ld dzieli sie przez %ld i %ld.\n", num, dziel, num/dziel);
				else
					printf("%ld dzieli sie przez %ld.\n", num, dziel);
				pierwsza = false;										// liczba nie jest liczba pierwsza 
			}
		}
		if (pierwsza)
			printf("%ld jest liczba pierwsza.\n", num);
		printf("\nPodaj nastepna liczbe do zanalizowania; ");
		puts("Wpisz 'q', aby zakonczyc.");
	}

	puts("Gotowe.");
	getchar();
	getchar();
	getchar();
	return 0;
}