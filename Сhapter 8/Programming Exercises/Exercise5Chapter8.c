//  przeszukiwanie dwudzielne - Exercise5Chapter8.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#define MIN 1
#define MAX 100

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char ch;
	int proba, przedzial, dolna = MIN, gorna = MAX;
	
/*  Description ---------------------------------------------------------------*/
	printf("Wybierz liczbe od %d do %d. Sprobuje ja odgadnac.\n", MIN, MAX);
	puts("Wpisz '<', jesli szukana liczba jest mniejsza od mojej odpowiedzi.");
	puts("Wpisz '>', jesli szukana liczba jest wieksza od mojej odpowiedzi.");
	puts("Wpisz '=', jesli zgadlem.");
/*  Code ----------------------------------------------------------------------*/
	przedzial = gorna - dolna + 1;
	proba = przedzial / 2 + dolna - 1;
	printf("Hmm... czy Twoja liczba jest %d?\n", proba);
	while ((ch = getchar()) != '=')
	{
		while (getchar() != '\n')
			continue;					// pobranie pierwszego znaku
		switch (ch)
		{
			case '<' :
				gorna = proba - 1;
				break;
			case '>' :
				dolna = proba + 1;		// wiersz 'D'
				break;
			default :
				puts("Zly symbol. Wpisz '<', '>' lub '='");
		}
		przedzial = gorna - dolna + 1;
		proba = przedzial / 2 + dolna;
		if (proba > MAX)
			proba = MAX;				// ograniczenie maksymalnej wartosci z powodu dodawania (+ 1) w wierszu "D"
		printf("No dobrze, czy jest to %d?\n", proba);
		
	}
	puts("Wiedzialem, ze mi sie uda!");

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}