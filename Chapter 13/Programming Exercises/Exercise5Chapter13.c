//  dopisuje pliki do pliku (wiersz polecen) - Exercise5Chapter13.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROZMIAR_BUF 4096
#define DLAN 50

void dopisz(FILE * zrodlo, FILE * cel);

int main(int argc, char * argv[])
{
	FILE *pd, *pz;						// pz - plik dopisywany, pd - plik docelowy
	int pliki = 0;						// liczba dopisywanych plikow
	int ch;
	int i;

	if (argc == 1)
	{
		printf("Sposob uzycia: %s.exe nazwa_pliku_1 nazwa_pliku_2 ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ( (pd = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "Blad otwarcia %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ( setvbuf(pd, NULL, _IOFBF, ROZMIAR_BUF) != 0 )
	{
		fputs("Nie mozna utworzyc bufora wyjsciowego\n", stderr);
		exit(EXIT_FAILURE);
	}
	for (i = 2; i < argc; i++)
	{
		if ( 0 == strcmp(argv[i], argv[1]) )
		{
			fputs("Nie mozna dopisac pliku do siebie\n", stderr);
		}
		else if ( NULL == (pz = fopen(argv[i], "r")) )
		{
			fprintf(stderr, "Blad otwarcia pliku %s\n", argv[i]);
		}
		else
		{
			if (setvbuf(pz, NULL, _IOFBF, ROZMIAR_BUF) != 0)
			{
				fputs("Nie mozna utworzyc bufora wejsciowego\n", stderr);
				continue;
			}
			dopisz(pz, pd);
			if (ferror(pz) != 0)
			{
				fprintf(stderr, "Blad odczytu pliku %s\n", argv[i]);
			}
			if (ferror(pd) != 0)
			{
				fprintf(stderr, "Blad zapisu pliku %s\n", argv[1]);
			}
			fclose(pz);
			pliki++;
			printf("Plik %s dopisany.\n", argv[i]);
		}
	}
	printf("Koniec. Dopisano %d plikow.\n", pliki);
	printf("%s zawiera:\n", argv[1]);
	rewind(pd);
	while ( (ch = getc(pd)) != EOF)
	{
		putchar(ch);
	}
	puts("\nKoniec.");
	fclose(pd);
	return 0;
}

void dopisz(FILE * zrodlo, FILE * cel)
{
	size_t bajty;
	static char temp[ROZMIAR_BUF];		// jednorazowy przydzial bufora
	while ((bajty = fread(temp, sizeof(char), ROZMIAR_BUF, zrodlo)) > 0)
	{
		fwrite(temp, sizeof (char), bajty, cel);
	}
}