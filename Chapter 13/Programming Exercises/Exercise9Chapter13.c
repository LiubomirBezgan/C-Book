//  korzysta z fprintf(), fscanf(), i rewind(), ale z numeracja - Exercise9Chapter13.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>				// prototyp funkcji exit()
#include <string.h>	
#define MAX 41

int main(void)
{
	FILE *wp;
	char slowa[MAX];
	int liczba_slow = 0;

	if ( (wp = fopen("slowka.txt", "a+")) == NULL)
	{
		fprintf(stdin, "Nie moge otworzyc pliku \"slowka.txt\".\n");
		exit(EXIT_FAILURE);
	}

	puts("Podaj slowa, ktore maja zostac dodane do pliku;");
	puts("Aby zakonczyc, wpisz #.");

	while ( (1 == fscanf(stdin, "%40s", slowa)) && (slowa[0] != '#') )
	{
		fprintf(wp, "%s ", slowa);
	}

	puts("Zawartosc pilku:");
	rewind(wp);
	while (1 == fscanf(wp, "%s", slowa))
	{
		fprintf(stdout, "%d - %s\n", ++liczba_slow, slowa);
	}
	puts("Gotowe!\n");
	if (fclose(wp) != 0)
	{
		fprintf(stderr, "Blad przy zamykaniu pliku.\n");
	}
	return 0;
}