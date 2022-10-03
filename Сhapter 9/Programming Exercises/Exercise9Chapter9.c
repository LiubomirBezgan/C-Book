//  Funkcja zwracajaca potege liczby. Rekurencja - Exercise9Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
double potega(double liczba, int do_potegi);		// prototyp ANSI

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	double x;
	int y;	
	
/*  Description ---------------------------------------------------------------*/
	puts("Program sluzy do testu rozbudowanej funkcji potega(liczba, do_potegi).\n");
	
/*  Code ----------------------------------------------------------------------*/
	printf("Podaj liczbe do podniesienia: ");
	scanf("%lf", &x);
	printf("Podaj potege: ");
	scanf("%d", &y);
	printf("%lf do potegi %d wynosi %lf.\n", x, y, potega(x, y));

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
	{
		continue;
	}
	return 0;
}


double potega(double liczba, int do_potegi)			// definicja funkcji
{
	double pot = 1;

	if (0 == liczba)
	{
		if (do_potegi <= 0)
		{
			printf("Nie zadziala!\n");
		}
		else
		{
			pot = 0;
		}
	}
	else 
	{
		if (do_potegi > 0)
		{
			pot = liczba * potega(liczba, do_potegi - 1);
		}
		else if (do_potegi < 0)
		{
			pot = (1 / liczba) * potega(liczba, do_potegi + 1);
		}
	}
	return pot;										// zwrot wartosci pot
}