//  dzialania arytmetyczne - Exercise8Chapter8.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
char wybor_znaku(void);
float pobranie_liczby(void);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char ch;
	float a, b, wynik;					// wynik = a ? b, gdzie '?' - wybrane dzialanie arytmetyczne (ch)
	
/*  Description ---------------------------------------------------------------*/
	puts("Program dokonuje jedno z czterech podstawowych dzialan\narytmetycznych na podanych przez uzytkownika liczbach.");
	
/*  Code ----------------------------------------------------------------------*/
	ch = wybor_znaku();
	while (ch != 'k')
	{
		printf("Podaj pierwsza liczbe: ");
		a = pobranie_liczby();
		printf("Podaj druga liczbe: ");
		b = pobranie_liczby();
		switch (ch)
		{
			case 'a' :
				wynik = a + b;
				printf("%g + %g = %g\n", a, b, wynik);
				break;
			case 'b' :
				wynik = a - b;
				printf("%g - %g = %g\n", a, b, wynik);
				break;
			case 'c' :
				wynik = a * b;
				printf("%g * %g = %g\n", a, b, wynik);
				break;
			case 'd' :
				while (b == 0)
				{
					printf("Podaj liczbe inna niz 0: ");
					b = pobranie_liczby();
				}	
				wynik = a / b;
				printf("%g / %g = %g\n", a, b, wynik);
				break;
		}
		ch = wybor_znaku();
	}
/*  Ending --------------------------------------------------------------------*/
	puts("Koniec.");
	return 0;
}

char wybor_znaku(void)
{	
	char znak;

	puts("\nWybierz jedno z dzialan:");
	puts("a. dodawanie      b. odejmowanie");
	puts("c. mnozenie       d. dzielenie");
	puts("k. koniec");

	while ((znak = getchar()) != 'k')
	{
		if (znak >= 'a' && znak <= 'd')
			break;
		else
		{
			puts("Zly symbol.\nPodaj litere a, b, c, d albo k.");
			while ((getchar()) != '\n')
				continue;								// czyszczenie bufora
		}
	}
	return znak;
}

float pobranie_liczby(void)
{
	float liczba;
	char symbol;

	while (scanf("%f", &liczba) != 1)
	{
		while ((symbol = getchar()) != '\n')
			putchar(symbol);							// oproznienie bufora za pomoca wyswietlania znakow
		printf(" nie jest liczba.\n");
		printf("Podaj liczbe, np. 2.5, -178E8 czy 3: ");
	}
	while ((getchar()) != '\n')
		continue;								// czyszczenie bufora	
	return liczba;
}