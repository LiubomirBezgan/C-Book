// program obliczajacy oplate za pokoj - Listing_9_9.c
// kompiluj razem z listingiem 9.10
// uzyj polecenia "gcc Listing_9_9.c Listing_9_10.c" w wierszu polecen
// zostanie utworzony plik wykonywalny a.exe
#include <stdio.h>
#include "hotel.h"

int main(void)
{
	int noce;
	double hotel;
	int kod;

	while ((kod = menu()) != KONIEC)
	{
		switch(kod)
		{
			case 1 : hotel = HOTEL1;
					 break;
			case 2 : hotel = HOTEL2;
					 break;
			case 3 : hotel = HOTEL3;
					 break;
			case 4 : hotel = HOTEL4;
					 break;
			default: hotel = 0.0;
					 puts("Ups!");
					 break;
		}
		noce = pobierz_noce();
		pokaz_cene(hotel, noce);
	}
	puts("Dziekuje i do widzenia");
	return 0;
}