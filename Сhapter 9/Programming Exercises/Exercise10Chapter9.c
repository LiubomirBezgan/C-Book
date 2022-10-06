//  opis - Exercise10Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void do_podst_n(unsigned long liczba, int n);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	unsigned long liczba;
	int podstawa;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program sluzy do testu funkcji do_podst_n(liczba, n).\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Podaj liczbe calkowita w dziesietnym systemie liczbowym:");
	scanf("%lu", &liczba);
	puts("Podaj podstawe (system liczbowy od 2 do 10):");
	scanf("%d", &podstawa);
	printf("%lu w systemie liczbowym z podstawa %d wynosi ", liczba, podstawa);
	do_podst_n(liczba, podstawa);

/*  Ending --------------------------------------------------------------------*/
	puts("\n\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void do_podst_n(unsigned long liczba, int n)
{
	int r;
	if (n >= 2 && n <= 10)
	{
		r = liczba % n;
		if (liczba >= n)
		{
			do_podst_n(liczba / n, n);
		}
		printf("%d", r);
	}
	else
	{
		puts("Zle dane. Wartosc podstawy powinna sie miescic poniedzy 2 a 10 wlacznie.");
	}
	return;
}