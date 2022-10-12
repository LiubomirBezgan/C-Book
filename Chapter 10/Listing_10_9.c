//  wykorzystuje zapis wskaznikowy - Listing_10_9.c
//  v1.0
#include <stdio.h>
#define MIESIACE 12

int main(void)
{
	int dni[MIESIACE] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int index;
	for (index = 0; index < MIESIACE; index++)
	{
		printf("Miesiac %2d ma %d dni.\n", index + 1, *(dni + index));   // rownowazne dni[index]
	}
	return 0;
}