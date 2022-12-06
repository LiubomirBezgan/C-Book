//  opis - Exercise8Chapter13.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
#define DLAN 40

/*  Main ----------------------------------------------------------------------*/
int main(int argc, char * argv[])
{
/*  Variables -----------------------------------------------------------------*/
	unsigned int ile_razy = 0;
	char nazwa_pliku[DLAN];
	char szukany_znak;
	char ch;
	int i;
	FILE * wp;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program wyswietla liczbe wystapien znaku (podanego w wierszu polecen) w plikach.\n");
	
/*  Code ----------------------------------------------------------------------*/
	if (1 == argc)
	{
		printf("Sposob uzycia: %s.exe znak nazwa_pliku_1 nazwa_pliku_2 ...\n", argv[0]);
		puts("albo");
		printf("Sposob uzycia: %s.exe znak\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (2 == argc)
	{
		szukany_znak = argv[1][0];
		puts("Podaj nazwe pliku (pusty wiersz konczy program):");
		while ( (NULL != wczytaj(nazwa_pliku, DLAN)) && ('\0' != nazwa_pliku[0]) )
		{
			if ( (wp = fopen(nazwa_pliku, "r")) == NULL)
			{
				fprintf(stderr, "Nie moglem otworzyc pliku \"%s\"\n", nazwa_pliku);
				puts("\nPodaj nazwe kolejnego pliku (pusty wiersz konczy program):");
				continue;
			}

			while ( (ch = getc(wp)) != EOF)
			{
				if (ch == szukany_znak)
				{
					ile_razy++;
				}
			}
			fprintf(stdout, "Znak '%c' pojawia sie %u razy w pliku \"%s\".\n", szukany_znak, ile_razy, nazwa_pliku);
			ile_razy = 0;
			if (fclose(wp) != 0)
			{
				fprintf(stderr, "Blad przy zamykaniu pliku.\n");
			}
			puts("\nPodaj nazwe kolejnego pliku (pusty wiersz konczy program):");
		}
	}
	else
	{
		szukany_znak = argv[1][0];
		for (i = 2; i < argc; i++)
		{
			if ( (wp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Nie moglem otworzyc pliku \"%s\"\n", argv[i]);
				continue;
			}

			while ( (ch = getc(wp)) != EOF)
			{
				if (ch == szukany_znak)
				{
					ile_razy++;
				}
			}
			fprintf(stdout, "Znak '%c' pojawia sie %u razy w pliku \"%s\".\n", szukany_znak, ile_razy, argv[i]);
			ile_razy = 0;
			if (fclose(wp) != 0)
			{
				fprintf(stderr, "Blad przy zamykaniu pliku.\n");
			}
		}
	}


/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}