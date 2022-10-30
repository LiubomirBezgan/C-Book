//  fgets() w parze z fputs() (petla) - Listing_11_8.c
//  v1.0
#include <stdio.h>
#define DLUGOSC 10

int main(void)
{
	char slowa[DLUGOSC];

	puts("Prosze wprowadzic lancuch (pusty wiersz zakonczy program):");
	while (fgets(slowa, DLUGOSC, stdin) != NULL && slowa[0] !='\n')
	{
		fputs(slowa, stdout);
	}
	puts("Gotowe.");
	return 0;
}