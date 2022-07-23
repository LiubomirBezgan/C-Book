// piramidka (nested loop) - Listing_6_18.c
// v1.0
#include <stdio.h>

int main(void)
{
	const int RZEDY = 6;
	const int ZNAKI = 6;
	
	int rzad;
	char ch;

	for (rzad = 0; rzad < RZEDY; rzad++)					// petla zewnetrzna
	{
		for (ch = ('A' + rzad); ch < ('A' + ZNAKI); ch++)	// petla wewnetrzna
			printf("%c", ch);
		printf("\n");
	}

	getchar();
	return 0;
}