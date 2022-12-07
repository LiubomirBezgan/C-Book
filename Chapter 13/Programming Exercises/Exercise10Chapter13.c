//  nawigacja w pliku tekstowym - Exercise10Chapter13.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
#define MAX_LENGTH 255

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	FILE *wp;
	char nazwa[MAX_LENGTH];
	long pozycja;
	long koniec_pliku;
	char ch;

	
/*  Description ---------------------------------------------------------------*/
	puts("Program pobiera od uzytkownika pozycje w pliku tekstowym i wyswietla tekst od tego miejsca do konca wiersza.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Podaj nazwe pliku:");
	while (1 != scanf("%s", nazwa))
	{
		puts("Sprobujmy ponownie. Podaj nazwe pliku:");
	}

	if ( (wp = fopen(nazwa, "r")) == NULL)
	{
		printf("Nie mozna otworzyc %s\n", nazwa);
		exit(EXIT_FAILURE);
	}
	fseek(wp, 0L, SEEK_END);
	koniec_pliku = ftell(wp);
	puts("Podaj pozycje (litera lub ujemna wartosc konczy program):");
	while (1 == scanf("%ld", &pozycja) && pozycja >= 0)
	{
		if (koniec_pliku - pozycja < 0)
		{
			puts("To jest poza plikiem.");
			puts("\nPodaj kolejna pozycje (litera lub ujemna wartosc konczy program):");
			continue;
		}
		fseek(wp, pozycja, SEEK_SET);
		while ((ch = getc(wp)) != '\n' && EOF != ch)
		{
			putc(ch, stdout);
		}
		puts("\n\nPodaj kolejna pozycje (litera lub ujemna wartosc konczy program):");
	}

/*  Ending --------------------------------------------------------------------*/
	fclose(wp);
	koniec('#');
	return 0;
}