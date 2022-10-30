//  fgets() w parze z fputs()  - Listing_11_7.c
//  v1.0
#include <stdio.h>
#define DLUGOSC 14

int main(void)
{
	char slowa[DLUGOSC];

	puts("Prosze wprowadzic lancuch.");
	fgets(slowa, DLUGOSC, stdin);
	puts("Wprowadzony lancuch (dwa razy: z puts() i fputs()):");
	puts(slowa);
	fputs(slowa, stdout);

	puts("Prosze wprowadzic kolejny lancuch.");
	fgets(slowa, DLUGOSC, stdin);
	puts("Wprowadzony lancuch (dwa razy: z puts() i fputs()):");
	puts(slowa);
	fputs(slowa, stdout);

	puts("Gotowe.");
	return 0;
}