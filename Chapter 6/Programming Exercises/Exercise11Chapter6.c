// Wspak cyfrowy - Exercise11Chapter6.c
// v1.0
#include <stdio.h>
#define ROZMIAR 8

int main(void)
{
	int i, array[ROZMIAR];

	puts("Podaj 8 liczb calkowitych:");
	for (i=0; i < ROZMIAR; i++)
		scanf("%d", &array[i]);
	for (i = ROZMIAR - 1; i >= 0; i--)
		printf("%d ", array[i]);
	puts("");

	getchar();
	getchar();
	return 0;
}