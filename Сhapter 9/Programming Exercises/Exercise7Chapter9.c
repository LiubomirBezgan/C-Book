//  opis - Exercise7Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
int numer_litery(char znak);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char ch;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program odczytuje znaki z pliku i podaje numer litery w alfabecie.\n");
	
/*  Code ----------------------------------------------------------------------*/
	while ((ch=getchar()) != EOF)
	{
		if (-1 != numer_litery(ch))
		{
			printf("%c - %2d\n", ch, numer_litery(ch));
		}
		else
		{
			printf("%c nie jest litera\n", ch);
		}
	}

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

int numer_litery(char znak)
{
	if (isalpha(znak))
	{
		if (znak >= 65 && znak <= 90)
		{
			return znak - 64;
		}
		else if (znak >= 97 && znak <= 122)
		{
			return znak - 96;
		}
		else
		{
			return -1;
		}

	}
	else
	{
		return -1;
	}

}