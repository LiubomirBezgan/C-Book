//  naglowek2 - Listing_9_2.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>    // zawiera prototyp strlen()
#define NAZWA "SKALEN.Gaming"
#define ADRES "2 Carrier Rush Plaza"
#define MIEJSCOWOSC "Korhal IV, ST 93046"
#define LIMIT 40
#define ODSTEP ' '
void n_znak(char ch, int num);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int odstepy;
/*  Description ---------------------------------------------------------------*/
/*  Code ----------------------------------------------------------------------*/
	n_znak('*', LIMIT);
	putchar('\n');
	n_znak(ODSTEP, 12);
	printf("%s\n", NAZWA);
	odstepy = (LIMIT - strlen(ADRES)) / 2;
	n_znak(ODSTEP, odstepy);
	printf("%s\n", ADRES);
	n_znak(ODSTEP, (LIMIT - strlen(MIEJSCOWOSC)) / 2);
	printf("%s\n", MIEJSCOWOSC);
	n_znak('*', LIMIT);
	putchar('\n');
/*  Ending --------------------------------------------------------------------*/
	return 0;
}

void n_znak(char ch, int num)
{
	int licznik;
	for (licznik = 1; licznik <= num; licznik++)
		putchar(ch);
}