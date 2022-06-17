// C Primer Plus Chapter 2 Exercise 8
// Version 1.0
#include <stdio.h>
void raz_trzy(void);	//prototyp funkcji wg ANSI/ISO C
void dwa(void);	//prototyp funkcji wg ANSI/ISO C

int main(void) 			// wyświetlanie tekstu za pomocą własnych fynkcji
{
	printf("zaczynamy:\n");
	raz_trzy();
	printf("koniec!\n");
	return 0;
}

void raz_trzy(void)	//definicja funkcji
{
	printf("raz\n");
	dwa();
	printf("trzy\n");

}

void dwa(void)	//definicja funkcji
{
	printf("dwa\n");
}