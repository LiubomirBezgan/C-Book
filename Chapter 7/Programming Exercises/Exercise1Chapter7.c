// opis - Exercise1Chapter7.c
// v1.0
#include <stdio.h>

int main(void)
{
	char ch;
	int space = 0;
	int new_line = 0;
	int other = 0;  

	puts("Wpisz jakis tekst; '#' konczy program.");
	while ((ch = getchar()) != '#')
	{
		if (ch == ' ')
			space++;
		else if (ch == '\n')
			new_line++;
		else
			other++;
	}
	printf("Liczba odstepow:           %4d\n", space);
	printf("Liczba znakow nowej linii: %4d\n", new_line);
	printf("Liczba innych znakow:      %4d\n", other);

	getchar();
	getchar();
	return 0;
}