// dollar pyramid - Exercise2Chapter6.c
// v1.0
#include <stdio.h>
#define ZNAK '$'

int main(void)
{
	int i, j;
	
	for (i=0; i < 5; i++)
	{
		for (j=0; j <= i; j++)
			printf("%c", ZNAK);
	puts("");
	}

	getchar();
	return 0;
}