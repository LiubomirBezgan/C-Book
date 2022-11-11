//  funkcja main() z argumentami (potegowanie) - Exercise14Chapter11.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
double potega(double liczba, int do_potegi);

int main(int argc, char *argv[])
{
	double liczba;
	int do_potegi;

	liczba = strtod(argv[1], NULL);
	do_potegi = atoi(argv[2]);


	printf("%g do potegi %d = %g\n", liczba, do_potegi, potega(liczba, do_potegi));

	return 0;
}

double potega(double liczba, int do_potegi)
{
	double wynik = 1;
	int i;
	if (do_potegi > 0)
	{
		for (i = 0; i < do_potegi; i++)
		{
			wynik *= liczba;
		}
	}
	else if (do_potegi < 0)
	{
		for (i = 0; i < (do_potegi * -1); i++)
		{
			wynik /= liczba;
		}
	}
	return wynik;
}