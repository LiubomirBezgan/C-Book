// Podatki z menu - Exercise7Chapter8.c
// v1.0
#include <stdio.h>
#include <stdbool.h>
#define NADGODZINY 1.5				// 150% podstawowej stawki
#define PROG1 1200
#define PROG2 1800
#define PODATEK1 0.15				// 15% dla pierwszych 1200 zl
#define PODATEK2 0.20				// 20% dla kolejnych 600 zl 
#define PODATEK3 0.25				// 25% dla reszty wynagrodzenia
#define DNI 5						// 5 roboczych dni w tygodniu
#define GODZIN 8					// 8 godzin dziennie
#define STAWKA1 35					// 35 zl/godz
#define STAWKA2 37					// 37 zl/godz
#define STAWKA3 40					// 40 zl/godz
#define STAWKA4 45					// 45 zl/godz

int main(void)
{
	// zmienne
	signed char ch;
	int podstawa;					// stawka wynagrodzenia
	float godziny_w_t;				// liczba przepracowanych godzin w tygodniu
	float pensja_netto, podatek;
	bool symbol = false;			// flaga: czy zostal wprowadzony wlasciwy symbol

	// wybor stawki wynagrodzenia
	puts("******************************************************************");
	puts("Podaj litere odpowiadajaca zadanej stawce wynagrodzenia lub opcji:");
	printf("a) %d zl/godz.				b) %d zl/godz.\n", STAWKA1, STAWKA2);
	printf("c) %d zl/godz.				d) %d zl/godz.\n", STAWKA3, STAWKA4);
	puts("q) wyjscie");
	puts("******************************************************************");	
	while (!symbol)
	{
		switch (ch = getchar())
		{
			case 'a' : {
				podstawa = STAWKA1;
				symbol = true;
				break;
			}
			case 'b' : {
				podstawa = STAWKA2;
				symbol = true;
				break;
			}
			case 'c' : {
				podstawa = STAWKA3;
				symbol = true;
				break;
			}
			case 'd' : {
				podstawa = STAWKA4;
				symbol = true;
				break;
			}
			case 'q' : {
				podstawa = 0;
				symbol = true;
				break;
			}
			default :
				puts("Zly symbol.\nPodaj litere a, b, c, d albo q.");
				symbol = false;
				while ((getchar()) != '\n')
					continue;								// czyszczenie bufora
		}
	}
	if (podstawa == 0)										// q) wyjscie
		puts("Milego dnia!");
	else
	{
		// obliczenie wynagrodzenia netto
		puts("Podaj liczbe przepracowanych godzin w tygodniu:");	
		scanf("%f", &godziny_w_t);
		if (godziny_w_t <= DNI * GODZIN)
			pensja_netto = 	godziny_w_t * podstawa;
		else
			pensja_netto = DNI * GODZIN * podstawa + (godziny_w_t - DNI * GODZIN) * podstawa * NADGODZINY;
		
		// obliczenie podatku
		if (pensja_netto <= PROG1)
			podatek = PODATEK1 * pensja_netto;
		else if (pensja_netto <= PROG2)
			podatek = PROG1 * PODATEK1 + (pensja_netto - PROG1) * PODATEK2;
		else
			podatek = PROG1 * PODATEK1 + (PROG2 - PROG1)* PODATEK2 + (pensja_netto - PROG2) * PODATEK3;	

		// wyswietlanie wyniku
		printf("\nDla stawki wynagrodzenia %d zl/godz. i %.1f przepracowanych godzin w tygodniu:\n", podstawa, godziny_w_t);
		printf("Wynagrodzenie brutto = %7.2f zl\n", pensja_netto);
		printf("Podatek odprowadzony = %7.2f zl\n", podatek);
		printf("Wynagrodzenie  netto = %7.2f zl\n", pensja_netto - podatek);
	}

	// zamykanie programu
	puts("\nWpisz '#', aby zamknac program:");
	while (getchar() != '#')
		continue;

	return 0;
}
