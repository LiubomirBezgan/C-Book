//  wyswietla dwa pliki na raz "dwa wierszy w jednym" - Exercise7b_Chapter13.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <mylib.h>
#include <stdlib.h>

/*  Main ----------------------------------------------------------------------*/
int main(int argc, char * argv[])
{
/*  Variables -----------------------------------------------------------------*/
	char ch = 'A';
	FILE *wp1, *wp2;
	bool koniec1 = false;
	bool koniec2 = false;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program wyswietla \"wierszami\" dwa pliki na raz:\n");
	
/*  Code ----------------------------------------------------------------------*/
	if (3 != argc)
	{
		printf("Sposob uzycia: %s.exe nazwa_pliku_1 nazwa_pliku_2\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ( (wp1 = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Blad otwarcia %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ( (wp2 = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Blad otwarcia %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (!koniec1 || !koniec2)
	{
		if (!koniec1)
		{
			while ( ((ch = getc(wp1)) != '\n') && (EOF != ch) )
			{
				putc(ch, stdout);
			}
			if (EOF == ch)
			{
				koniec1 = true;
			}
		}

		if (!koniec2)
		{
			while ( ((ch = getc(wp2)) != '\n') && (EOF != ch) )
			{
				putc(ch, stdout);
			}
			if (EOF == ch)
			{
				koniec2 = true;
			}
		}
		putchar('\n');
	}

/*  Ending --------------------------------------------------------------------*/
	if (fclose(wp1) != 0 || fclose(wp2) != 0)
	{
		fprintf(stderr, "Blad przy zamykaniu plikow.\n");
	}
	koniec('#');
	return 0;
}