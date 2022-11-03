//  funkcja main() z argumentami - Listing_11_31.c
//  v1.0
#include <stdio.h>

int main(int argc, char *argv[])
{
	int licznik;
	printf("Wiersz polecen zawiera %d argumentow:\n", argc - 1);
	for (licznik = 1; licznik < argc; licznik++)
	{
		printf("%d: %s\n", licznik, argv[licznik]);
	}
	putchar('\n');
	return 0;
}