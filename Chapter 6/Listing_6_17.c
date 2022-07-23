// nested loop - Listing_6_17.c
// v1.0
#include <stdio.h>
#define RZEDY 6
#define ZNAKI 10

int main(void)
{
	int rzad;
	char ch;

	for (rzad = 0; rzad < RZEDY; rzad++)			// petla zewnetrzna
	{
		for (ch = 'A'; ch < ('A' + ZNAKI); ch++)	// petla wewnetrzna
			printf("%c", ch);
		printf("\n");
	}

	getchar();
	return 0;
}