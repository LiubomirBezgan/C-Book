//  wyswietlenie zawartosci plikow, podanych w wierszu polecen - Exercise4Chapter13.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>				// prototyp funkcji exit()

int main(int argc, char * argv[])
{
	FILE *wp_zro;			// wskazniki plikowe
	char ch;
	int i;

	if (argc == 1)
	{
		printf("Sposob uzycia: %s.exe nazwa_pliku_1 nazwa_pliku_2 ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++)
	{
		fprintf(stdout, "\nTekst z pliku %s:\n", argv[i]);
		if ( (wp_zro = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Nie mozna otworzyc %s do odczytu\n", argv[i]);
			continue;
		}
		while ( (ch = getc(wp_zro)) != EOF)
		{
			putc(ch, stdout);
		}
		putc('\n', stdout);
	} 
	fclose(wp_zro);

	return 0;
}