// "Elektr" - Listing_7_4.c
// v1.0
#include <stdio.h>
#define STAWKA1 0.2401															// stawka dla pierwszych 360 kWh
#define STAWKA2 0.2881															// stawka dla nastepnych 108 kWh
#define STAWKA3 0.3457															// stawka dla nastepnych 252 kWh
#define STAWKA4 0.3877															// stawka powyzej 720 kWh
#define PROG1 360.0																// pierwszy prog
#define PROG2 468.0																// drugi prog
#define PROG3 720.0																// trzeci prog
#define PODSTAWA1 (STAWKA1 * PROG1)												// cena pierwszych 360 kWh
#define PODSTAWA2 (PODSTAWA1 + (STAWKA2 * (PROG2 - PROG1)))						// cena pierwszych 468 kWh
#define PODSTAWA3 (PODSTAWA1 + PODSTAWA2 + (STAWKA3 * (PROG3 - PROG2)))			// cena pierwszych 720 kWh

int main(void)
{
	double kwh;																	// liczba zuzytych kilowatogodzin
	double oplata;																// ich cena

	puts("Podaj liczbe zuzytych kWh.");
	scanf("%lf", &kwh);															// %lf - typ double
	if (kwh <= PROG1)
		oplata = STAWKA1 * kwh;
	else if (kwh <= PROG2)
		oplata = PODSTAWA1 + (STAWKA2 * (kwh - PROG1));
	else if (kwh <= PROG3)
		oplata = PODSTAWA2 + (STAWKA3 * (kwh - PROG2));
	else
		oplata = PODSTAWA3 + (STAWKA4 * (kwh - PROG3));
	printf("Oplata za %.1f kWh wynosi %1.2f zl.\n", kwh, oplata);

	getchar();
	getchar();
	return 0;
}