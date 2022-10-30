//  gets() w parze z puts()  - Listing_11_6.c
//  v1.0
#include <stdio.h>
#define DLUGOSC 81

int main(void)
{
	char slowa[DLUGOSC];
	puts("Prosze wprowadzic lancuch.");
	gets(slowa);
	puts("Wprowadzony lancuch (dwa razy):");
	printf("%s\n", slowa);
	puts(slowa);
	puts("Gotowe.");
	return 0;
}