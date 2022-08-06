// Program wykorzystuje continue do pominiecia czesci petli - Listing_7_9.c
// v1.1
#include <stdio.h>

int main(void)
{
	const float MIN = 0.0f;
	const float MAX = 100.0f;

	float wynik;
	float suma = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;

	puts("Podaj pierwszy wynik (albo 'q' zeby zakonczyc):");
	while (scanf("%f", &wynik) == 1)
	{
		if (wynik < MIN || wynik > MAX)
		{
			printf("%0.1f jest nieprawidlowa wartoscia.\n\n", wynik);
			continue;				// skok do warunku wykonania petli
		}
		printf("Przyjeto: %0.1f\n", wynik);
		min = (wynik < min)? wynik : min;
		max = (wynik > max)? wynik : max;
		suma += wynik;
		n++;
		puts("\nPodaj kolejny wynik (albo 'q' zeby zakonczyc):");
	}
	
	if (n>0)
	{
		printf("\nSrednia z %d wynikow wynosi %0.1f.\n", n, suma/n);
		printf("Najnizszy = %0.1f, najwyzszy = %0.1f.\n", min, max);
	}
	else
		puts("Nie podano zadnych prawidlowych wynikow.");

	getchar();
	getchar();
	getchar();
	return 0;
}