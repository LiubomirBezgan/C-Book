// potega - Listing_6_20.c
// v1.0
#include <stdio.h>
double potega(double a, int b);		// prototyp ANSI

int main(void)
{
	double x, xpot;
	int n;

	puts("Podaj liczbe oraz potege naturalna, do ktorej podniesiona");
	puts("zostanie liczba. Wpisz \"q\", aby zakonczyc program.");

	while (scanf("%lf%d", &x, &n) == 2)
	{
		xpot = potega(x,n);			// wywolanie funkcji
		printf("%.3g do potegi %d to %.5g\n\n", x, n, xpot);
		puts("Podaj kolejna pare liczb lub wpisz \"q\", aby zakonczyc.");
	}

	puts("Zycze milego dnia!");

	getchar();
	getchar();
	getchar();
	return 0;
}

double potega(double a, int b)		// definicja funkcji
{
	double pot = 1;
	int i;

	for (i = 1; i <= b; i++)
		pot *= a;
	return pot;						// zwrot wartosci pot
}