//  oblicza silnie za pomoca rekurencji i petli - Listing_9_7.c
//  v1.0
#include <stdio.h>
long silnia(int n);
long rsilnia(int n);

int main(void)
{
	int num;
	puts("Ten program liczy silnie.");
	puts("Podaj liczbe z przedzialu 0-12 (k - koniec):");
	while (1 == scanf("%d", &num))
	{
		if (num < 0)
		{
			puts("Prosze nie podawac liczb ujemnych.");
		}
		else if (num > 12)
		{
			puts("Prosze podac wartosc mniejsza od 13.");
		}
		else
		{
			printf("Petla:      %d silnia = %ld\n", num, silnia(num));
			printf("Rekurancja: %d silnia = %ld\n", num, rsilnia(num));
		}
		puts("Podaj liczbe z przedzialu 0-12 (k - koniec):");
	}
	puts("Gotowe.");
	return 0;
}

long silnia(int n)					// wersja oparta na petlach
{
	long wynik;
	for (wynik = 1; n > 1; n--)
	{
		wynik *= n;
	}
	return wynik;
}

long rsilnia(int n)					// wersja rekurencyjna
{
	long wynik;
	if (n > 0)
	{
		wynik = n * rsilnia(n - 1);
	}
	else
	{
		wynik = 1;
	}
	return wynik;
}