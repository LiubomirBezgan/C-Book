//  Funkcja zwracajaca potege liczby. Petla - Exercise8Chapter9.c
//  v1.1
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
	printf("%lf do potegi %d wynosi %le.\n", x, y, potega(x, y));

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
	int i;

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
			for (i = 1; i <= do_potegi; i++)
				{
					pot *= liczba;
				}
		}
		else if (do_potegi < 0)
		{
			for (i = 1; i <= (-1 * do_potegi); i++)
				{
					pot *= 1 / liczba;
				}
		}
	}
	return pot;										// zwrot wartosci pot
}