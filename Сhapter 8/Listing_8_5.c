//  pokaz_zn - Exercise?Chapter?.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void wyswietl(char c, int wysokosc, int szerokosc);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int ch;
	int rzedy, kolumny;
	
/*  Code ----------------------------------------------------------------------*/
	printf("Podaj znak i dwie liczby calkowite:\n");
	while ((ch = getchar()) != EOF)
	{
		if (scanf("%d %d", &rzedy, &kolumny) != 2)
			break;
		wyswietl(ch, rzedy, kolumny);
		printf("Podaj kolejny znak i dwie liczby calkowite:\n");
		printf("Aby zakonczyc, zasymuluj EOF.\n");
	}
	printf("Do widzenia!\n");

/*  Ending --------------------------------------------------------------------*/
	return 0;
}

void wyswietl(char c, int wysokosc, int szerokosc)
{
	int rzad, kol;

	for (rzad = 1; rzad <= wysokosc; rzad++)
	{
		for (kol = 1; kol <= szerokosc; kol++)
			putchar(c);
		putchar('\n');
	}
}