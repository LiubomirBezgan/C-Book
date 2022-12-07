//  wyswietla wszystkie wiersze, zawierajace podany lancuch znakowy - Exercise11Chapter13.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>
#define MAX_LENGTH 255

/*  Main ----------------------------------------------------------------------*/
int main(int argc, char * argv[])
{
/*  Variables -----------------------------------------------------------------*/
	FILE *wp;
	char biezacy_wiersz[MAX_LENGTH];

	
/*  Description ---------------------------------------------------------------*/
	puts("Program wyswietla wszystkie wiersze, zawierajace podany lancuch znakowy.\n");
	
/*  Code ----------------------------------------------------------------------*/
	if (3 != argc)
	{
		printf("Sposob uzycia: %s.exe lancuch_znakowy nazwa_pliku\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ( (wp = fopen(argv[2], "r")) == NULL)
	{
		printf("Nie mozna otworzyc %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while (NULL != fgets(biezacy_wiersz, MAX_LENGTH, wp))
	{
		if (NULL != strstr(biezacy_wiersz, argv[1]))
		{
			fputs(biezacy_wiersz, stdout);
		}
	}

/*  Ending --------------------------------------------------------------------*/
	fclose(wp);
	koniec('#');
	return 0;
}