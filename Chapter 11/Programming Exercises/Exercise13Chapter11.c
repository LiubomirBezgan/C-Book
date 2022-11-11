//  funkcja main() z argumentami (odwrocenie kolejnosci argumentow) - Exercise13Chapter11.c
//  v1.0
#include <stdio.h>

int main(int argc, char *argv[])
{
	int licznik;

	for (licznik = argc - 1; licznik >= 1; licznik--)
	{
		printf("%s ", *(argv + licznik));
	}
	putchar('\n');
	return 0;
}