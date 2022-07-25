// opis - Exercise?Chapter?.c
// v1.0
#define ROZMIAR 26 
#include <stdio.h>

int main(void)
{
	char ch;
	int i, array[ROZMIAR];

	for (i = 0, ch = 'a'; i < ROZMIAR; i++, ch++)
		array[i] = ch;
	
	for (i = 0; i < ROZMIAR; i++ )
		printf(" %c\n", array[i]);

	getchar();
	return 0;
}