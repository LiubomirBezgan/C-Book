// badanie programu Listing_9_13.c - Listing_9_14.c
#include <stdio.h>
void zamiana(int * u, int * v);		// deklaracja funkcji
int main(void)
{
	int x = 5, y = 10;
	printf("Poczatkowo x = %2d, a y = %2d.\n", x, y);
	zamiana(&x, &y);
	printf("A teraz    x = %2d, a y = %2d.\n", x, y);
	return 0;
}

void zamiana(int * u, int * v)		// definicja funkcji
{
	int temp;
	temp = *u;
	*u = *v;
	*v = temp;
}