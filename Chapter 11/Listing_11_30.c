//  modyfikuje lancuch za pomoca funkcji z ctype.h - Listing_11_30.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define GRANICA 80

/*  Prototypes ----------------------------------------------------------------*/
void DuzeLit(char *);
int LiczInter(const char *);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char wiersz[GRANICA];
	char * tutaj;

/*  Code ----------------------------------------------------------------------*/
	puts("Podaj wiersz tekstu:");
	fgets(wiersz, GRANICA, stdin);
	tutaj = strchr(wiersz, '\n');				// szukamy znaku nowego wiersza
	if (tutaj)
	{
		*tutaj = '\0';
	}

	DuzeLit(wiersz);
	puts(wiersz);
	printf("Wpisany wiersz zawiera %d znakow interpunkcyjnych.\n", LiczInter(wiersz));
	return 0;
}

void DuzeLit(char * lan)
{
	while (*lan)
	{
		*lan = toupper(*lan);
		lan++;
	}
}

int LiczInter(const char * lan)
{
	int licz = 0;
	while (*lan)
	{
		if (ispunct(*lan))
		{
			licz++;
		}
		lan++;
	}
	return licz;
}