// DOLLARDOLLARDOLLARNUTYPONIALJE - Question6Chapter6.c
// v1.0
#include <stdio.h>
#define DOLLAR '$'
int main(void)
{
	int i, j;
	
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 8; j++)
			printf("%c", DOLLAR);
		printf("\n");
	}

	getchar();
	return 0;
}
