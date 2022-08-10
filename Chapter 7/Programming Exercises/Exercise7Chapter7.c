// Podatki - Exercise7Chapter7.c
// v1.0
#include <stdio.h>
#define PODSTAWA 40			// 40 zl/godz
#define NADGODZINY 60		// 60 zl/godz
#define PROG1 1200
#define PROG2 1800
#define PODATEK1 0.15
#define PODATEK2 0.20
#define PODATEK3 0.25
#define DNI 5				// 5 roboczych dni w tygodniu
#define GODZIN 8			// 8 godzin dziennie

int main(void)
{
	float godziny_w_t, pensja_netto, podatek;	
	
	puts("Podaj liczbe przepracowanych godzin w tygodniu:");
	scanf("%f", &godziny_w_t);

	if (godziny_w_t <= DNI * GODZIN)
		pensja_netto = 	godziny_w_t * PODSTAWA;
	else
		pensja_netto = DNI * GODZIN * PODSTAWA + (godziny_w_t - DNI * GODZIN) * NADGODZINY;

	if (pensja_netto <= PROG1)
		podatek = PODATEK1 * pensja_netto;
	else if (pensja_netto <= PROG2)
		podatek = PROG1 * PODATEK1 + (pensja_netto - PROG1) * PODATEK2;
	else
		podatek = PROG1 * PODATEK1 + (PROG2 - PROG1)* PODATEK2 + (pensja_netto - PROG2) * PODATEK3;

	printf("Wynagrodzenie brutto = %.2f zl\n", pensja_netto);
	printf("Podatek = %.2f zl\n", podatek);
	printf("Wynagrodzenie netto = %.2f zl\n", pensja_netto - podatek);

	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;

	return 0;
}
