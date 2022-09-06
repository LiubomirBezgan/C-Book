//  naglowek1 - Listing_9_1.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
#define NAZWA "SKALEN.Gaming"
#define ADRES "2 Carrier Rush Plaza"
#define MIEJSCOWOSC "Korhal IV, ST 93046"
#define LIMIT 40
void gwiazdki(void);					// prototyp funkcji

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
/*  Description ---------------------------------------------------------------*/
/*  Code ----------------------------------------------------------------------*/
	gwiazdki();							// wywolanie funkcji
	printf("%s\n", NAZWA);	
	printf("%s\n", ADRES);
	printf("%s\n", MIEJSCOWOSC);
	gwiazdki();							// wywolanie funkcji
/*  Ending --------------------------------------------------------------------*/
	return 0;
}

void gwiazdki(void)						// definicja funkcji
{
	int licznik;
	for (licznik = 1; licznik <= LIMIT; licznik++)
		putchar('*');
	putchar('\n');
}