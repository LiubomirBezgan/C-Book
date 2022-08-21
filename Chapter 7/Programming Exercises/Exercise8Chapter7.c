// Podatki z menu - Exercise8Chapter7.c
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
	puts("Podaj liczbe odpowiadajaca zadanej stawce wynagrodzenia lub opcji:");
	puts("1) 35 zl/godz.				2) 37 zl/godz.");
	puts("3) 40 zl/godz.				4) 45 zl/godz.");
	puts("5) wyjscie");
	puts("******************************************************************");	
	while (!symbol)
	{
		switch (ch = getchar())
		{
			case '1' : {
				podstawa = 35;
				symbol = true;
				break;
			}
			case '2' : {
				podstawa = 37;
				symbol = true;
				break;
			}
			case '3' : {
				podstawa = 40;
				symbol = true;
				break;
			}
			case '4' : {
				podstawa = 45;
				symbol = true;
				break;
			}
			case '5' : {
				podstawa = 0;
				symbol = true;
				break;
			}
			default :
				puts("Zly symbol.\nPodaj liczbe od 1 do 5");
				symbol = false;
				while ((getchar()) != '\n')
					continue;								// czyszczenie bufora
		}
	}
	if (podstawa == 0)				// 5) wyjscie
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
		printf("\nWynagrodzenie brutto = %7.2f zl\n", pensja_netto);
		printf("Podatek odprowadzony = %7.2f zl\n", podatek);
		printf("Wynagrodzenie  netto = %7.2f zl\n", pensja_netto - podatek);
	}

	// zamykanie programu
	puts("\nWpisz '#', aby zamknac program:");
	while (getchar() != '#')
		continue;

	return 0;
}
