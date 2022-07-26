// letter pyramid 2.0 - Exercise4Chapter6.c
// v1.0
#include <stdio.h>

int main(void)
{
	char ch = 'A';
	int i, j;

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j <= i; j++)
			printf("%c", ch++);
		puts("");
	}	

	getchar();
	return 0;
}