// dwukrotnie dolacza plik naglowkowy
#include <stdio.h>
#include "Listing_16_10_daneos.h"
#include "Listing_16_10_daneos.h"	// przypadkowe drugie dolaczenie
int main(void)
{
	daneos zwyciezca = {"Less", "Ismoor"};
	printf("Zwyciezca jest %s %s\n", zwyciezca.imie, zwyciezca.nazw);
	return 0;
} 