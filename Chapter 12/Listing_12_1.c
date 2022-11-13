//  zmienne w bloku - Listing_12_1.c
//  v1.0
#include <stdio.h>

int main(void)
{
	int x = 30;			// oryginalna zmienna x
	printf("x w zewnetrznym bloku: %d spod adresu %p\n", x, &x);
	{
		int x = 77;		// nowe x przeslania oryginalne x
		printf("x w wewnetrznym bloku: %d spod adresu %p\n", x, &x);		
	}
	printf("x w zewnetrznym bloku: %d spod adresu %p\n", x, &x);
	while (x++ < 33)	// oryginalne x
	{
		int x = 100;	// nowe x przeslania oryginalne x
		x++;
		printf("x w petli while: %d spod adresu %p\n", x, &x);	
	}
	printf("x w zewnetrznym bloku: %d spod adresu %p\n", x, &x);	
	return 0;
}