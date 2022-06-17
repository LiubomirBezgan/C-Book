// C Primer Plus Chapter 2 Exercise 5
// Version 1.0
#include <stdio.h>
void br(void);	//prototyp funkcji wg ANSI/ISO C
void ic(void);	//prototyp funkcji wg ANSI/ISO C

int main(void) 			// wyświetlanie tekstu za pomocą własnych fynkcji
{
	br();
	printf(", ");
	ic();
	printf("\n");
	ic();
	printf("\n");
	br();
	printf("\n");
	return 0;
}

void br(void)	//definicja funkcji
{
	printf("Brazylia, Rosja");
}

void ic(void)	//definicja funkcji
{
	printf("Indie, Chiny");
}