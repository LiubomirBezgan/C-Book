// przelicza wspolrzedne kartezjanskie na biegunowe
#include <stdio.h>
#include <math.h>

#define RAD_NA_ST (180/(4 * atan(1)))

typedef struct biegun {
	double dlugosc;
	double kat;
} Biegun;

typedef struct kartez {
	double x;
	double y;
} Kartez;

Biegun kart_na_bieg(Kartez);

int main(void)
{
	Kartez wejscie;
	Biegun wynik;
	puts("Podaj wspolrzedne x i y; wpisanie q konczy program:");
	while (2 == scanf("%lf %lf", &wejscie.x, &wejscie.y))
	{
		wynik = kart_na_bieg(wejscie);
		printf("dlugosc = %0.2f, kat = %0.2f\n", wynik.dlugosc, wynik.kat);
	}
	puts("Gotowe.");
	return 0;
}

Biegun kart_na_bieg(Kartez k)
{
	Biegun b;
	b.dlugosc = sqrt(k.x * k.x + k.y * k.y);
	if (0 == b.dlugosc)
	{
		b.kat = 0;
	}
	else
	{
		b.kat = RAD_NA_ST * atan2(k.y, k.x);
	}
	return b;
}