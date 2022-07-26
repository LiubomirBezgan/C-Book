// letter pyramid - Exercise3Chapter6.c
// v1.0
#include <stdio.h>

int main(void)
{
	char ch = 'F';
	int i, j;

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j <= i; j++)
			printf("%c", ch - j);
		puts("");
	}	

	getchar();
	return 0;
}