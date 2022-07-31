// Zlicza znaki niebedace apostrofami lub cudzyslowami - Listing_7_6.c
// v1.0
#include <stdio.h>
#define KROPKA '.'

int main(void)
{
	char ch;
	int licznik = 0;
	puts("Podaj zdanie (powinno sie konczyc kropka) w celu zliczenia znakow niebedacych apostrofami lub cudzyslowami.");
	while ((ch = getchar()) != KROPKA)
	{
		if (ch != '"' && ch != '\'')
			licznik++;
	}
	printf("W zdaniu jest %d znakow niebedacych cudzyslowami lub apostrofami. \n", licznik);
	getchar();
	getchar();
	return 0;
}