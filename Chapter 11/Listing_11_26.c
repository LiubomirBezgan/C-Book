//  demo strcpy() - Listing_11_26.c
//  v1.0
#include <stdio.h>
#include <string.h>
#define ROZMIAR 40
#define SLOWO "cukier"

int main(void)
{
	const char * zrodlo = SLOWO;
	char kopia[ROZMIAR] = "Podaj mnie do sadu";
	char * wl;

	puts(zrodlo);
	puts(kopia);
	wl = strcpy(kopia + 6, zrodlo);
	puts(kopia);
	puts(wl);

	return 0;
}