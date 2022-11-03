//  przetwarza argument wiersza polecen na liczbe - Listing_11_32.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, razy;
	if (argc < 2 || (razy = atoi(argv[1])) < 1)
	{
		printf("Sposob uzyca: %s liczba-dodatnia\n", argv[0]);
	}
	else
	{
		for (i = 0; i < razy; i++)
		{
			puts("Witaj, przystojniaku!");
		}
	}
	return 0;
}