// hash - Listing_5_15.c
// v1.0
#include <stdio.h>
void hash(int n); // prototyp ANSI

int main(void)
{
	int razy = 5;
	char ch = '!';
	float f = 6.0;

	hash(razy);
	hash(ch);
	hash(f);

	getchar();
	return 0;
}

void hash(int n)
{
	while (n-- > 0)
		printf("#");
	printf("\n");
}