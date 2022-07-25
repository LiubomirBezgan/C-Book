// Question5Chapter6.c
// v1.0
#include <stdio.h>
int main(void)
{
	int i, j, lista[10];
	
	for (i = 1; i <= 10; i++)
	{
		lista[i-1] = 2*i + 3;
		for (j = 1; j <= i; j++)
			printf(" %d", lista[j-1]);
		printf("\n");
	}

	getchar();
	return 0;
}
