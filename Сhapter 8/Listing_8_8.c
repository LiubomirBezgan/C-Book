//  techniki realizacji menu - Listing_8_8.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>

/*  Functions -----------------------------------------------------------------*/
char pobierz_wybor(void);
char pobierz_pierwszy(void);
int pobierz_int(void);
void liczenie(void);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int wybor;

/*  Code ----------------------------------------------------------------------*/
	while ( (wybor = pobierz_wybor()) != 'q')
	{
		switch (wybor)
		{
			case 'a' : puts("Kup po niskiej cenie, sprzedaj po wysokiej.");
						break;
			case 'b' : putchar('\a');			// ANSI
						break;
			case 'c' : liczenie();
						break;
			default : puts("Blad program!");
						break;
		}
	}

/*  Ending --------------------------------------------------------------------*/
	puts("Do widzenia.");
	return 0;
}

void liczenie(void)
{
	int n, i;
	puts("Jak dlugo liczyc? Podaj liczbe calkowita:");
	n = pobierz_int();
	for (i = 1; i <= n; i++)
		printf("%d\n", i);
	/* while (getchar() != '\n')
		continue; */
}

char pobierz_wybor(void)
{
	char ch;

	puts("Wpisz wybrana litere:");
	puts("a. porada         b. alarm");
	puts("c. liczenie       q. koniec");
	ch = pobierz_pierwszy();
	while ( (ch < 'a' || ch > 'c') && ch != 'q')
	{
		puts("Wpisz a, b, c lub q.");
		ch = pobierz_pierwszy();
	}
	return ch;
}

char pobierz_pierwszy(void)
{
	int ch;

	ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}

int pobierz_int(void)
{
	int we;
	char ch;

	while (scanf("%d", &we) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);					// pomija bledne dane wejsciowe
		puts(" nie jest liczba calkowita.\nProsze podac wartosc calkowita, np. 25, -178 czy 3: "); //???????????
	}
	return we;
}