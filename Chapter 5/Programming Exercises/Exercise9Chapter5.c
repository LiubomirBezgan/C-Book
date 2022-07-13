// Konwersja stopni Fahrenheita na stopni Celsjusza i Kelwiny
// v1.0
#include <stdio.h>
#define DEG -8

void Temperatura(double t)
{
	const float TO_KELVIN = 273.16;
	const float TO_CELSIUS_1 = 5.0/9.0;
	const float TO_CELSIUS_2 = -32.0;

	printf("%.2f %cF = %.2f %cC = %.2f K\n", t, DEG, TO_CELSIUS_1 * (t + TO_CELSIUS_2), DEG, (TO_CELSIUS_1 * (t + TO_CELSIUS_2)) + TO_KELVIN);
}

int main (void)
{
	double t_fahr;
	int z;

	puts("Program konwertuje stopni Fahrenheita na stopni Celsjusza i Kelwiny.");
	puts("Prosze podac temperature w stopniach Fahrenheita.");
	puts("Podanie litery (np. \"k\") powoduje zakonczenie programu.");
	printf("Temperatura [%cF]: ", DEG);
	z = scanf("%lf", &t_fahr);

	while (z == 1)
	{
		Temperatura(t_fahr);
	puts("\nProsze podac temperature w stopniach Fahrenheita.");
	puts("Podanie litery (np. \"k\") powoduje zakonczenie programu.");
	printf("Temperatura [%cF]: ", DEG);
		z = scanf("%lf", &t_fahr);
	}

	puts("\nKoniec.");

	getchar();
	getchar();
	getchar();
	return 0;
}