//  funkcja tabela(ch, x, y) - Exercise3Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void tabela(char znak, int kolumny, int wierszy);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char ch;
	int x, y;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje tabela(ch, x, y).");
	
/*  Code ----------------------------------------------------------------------*/
	printf("Podaj znak: ");
	scanf("%c", &ch);
	printf("Podaj pierwsza liczbe: ");
	scanf("%d", &x);
	printf("Podaj druga liczbe: ");
	scanf("%d", &y);
	tabela(ch, x, y);

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void tabela(char znak, int kolumny, int wierszy)
{
	int licznik_kolumny, licznik_wierszy;
	for (licznik_wierszy = 0; licznik_wierszy < wierszy; licznik_wierszy++)
	{
		for (licznik_kolumny = 0; licznik_kolumny < kolumny; licznik_kolumny++)
		{
			putchar(znak);
		}
		putchar('\n');
	}
}