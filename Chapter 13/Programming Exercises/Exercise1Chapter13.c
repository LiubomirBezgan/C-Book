//  korzystanie ze standardowego I/O (bez wiersza polecen) - Exercise1Chapter13.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 255


int main(void)
{
	int ch;
	FILE *wp;
	unsigned long licznik = 0;
	char nazwa[MAX_LENGTH];

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
	while ( (ch = getc(wp)) != EOF)
	{
		putc(ch, stdout);
		licznik++;
	}
	fclose(wp);
	printf("\nPlik %s zawiera %lu znakow\n", nazwa, licznik);
	return 0;
}