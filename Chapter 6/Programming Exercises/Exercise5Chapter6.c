// letter pyramid 3.0 - Exercise5Chapter6.c
// v1.0
#include <stdio.h>
#define R (ch - 'A')

int main(void)
{
	char ch;
	int i, j, k;	

	puts("Podaj wielka litere:");
	scanf("%c", &ch);
	for (i = 0; i <= R; i++)
	{
		for (j = 0; j < R - i; j++)
			printf(" ");
		for (k = 0; k < R - j; k++)
			printf("%c", 'A' + k);
		for ( ; k >= 0; k--)
			printf("%c", 'A' + k);
		printf("\n");
	}	

	getchar();
	getchar();
	return 0;
}