//  wyszukiwanie z strncmp() - Listing_11_24.c
//  v1.0
#include <stdio.h>
#include <string.h>
#define ROZMIARLISTY 5

int main(void)
{
	const char * lista[ROZMIARLISTY] =
	{
		"astronomia", "asteroida",
		"astrofizyka", "ostroga",
		"asteryzm"
	};

	int licznik = 0;
	int i;
	char * tekst = "astro";
	for (i = 0; i < ROZMIARLISTY; i++)
	{
		if (!strncmp(lista[i], tekst, 5))
		{
			printf("Znaleziono: %s\n", lista[i]);
			licznik++;
		}
	}
	printf("Lista zawiera %d slowa zaczynajace sie na %s.\n", licznik, tekst);
	return 0;
}