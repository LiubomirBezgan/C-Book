//  licznik malych i wielkich liter oraz pozostalych znakow - Exercise3Chapter8.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	char ch;
	unsigned int licznik_male=0, licznik_wielkie=0, licznik_pozostale=0;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program zlicza malych i wielkich liter oraz pozostalych znakow.\n");
	
/*  Code ----------------------------------------------------------------------*/
	while ((ch=getchar()) != EOF)
	{
		if (islower(ch))
			licznik_male++;
		else if (isupper(ch))
			licznik_wielkie++;
		else
			licznik_pozostale++;
	}
	printf("Liczba malych liter       - %u\n", licznik_male);
	printf("Liczba wielkich liter     - %u\n", licznik_wielkie);
	printf("Liczba pozostalych znakow - %u\n", licznik_pozostale);
	return 0;
}