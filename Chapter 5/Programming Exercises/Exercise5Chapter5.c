// suma pierwszych n liczb calkowitych - Exercise5Chapter5.c
// v1.0
#include <stdio.h>

int main(void)
{
	unsigned int licznik = 0, suma = 0, n;

	puts("Program wyswietla sume pierwszych n liczb calkowitych.");
	puts("Prosze wprowadzic wartosc n:");
	printf("n = ");
	scanf("%u", &n);

	while (licznik++ < n)
		suma = suma + licznik;

	printf("Suma pierwszych %u liczb calkowitych = %u\n", n, suma);

	getchar();
	getchar();
	return 0;
}