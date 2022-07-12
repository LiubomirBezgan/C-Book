// Suma kwadratow pierwszych n liczb calkowitych - Exercise6Chapter5.c
// v1.0
#include <stdio.h>

int main(void)
{
	unsigned int licznik = 0, n;
	unsigned long long suma = 0;

	puts("Program wyswietla sume kwadratow pierwszych n liczb calkowitych.");
	puts("Prosze wprowadzic wartosc n:");
	printf("n = ");
	scanf("%u", &n);

	while (licznik++ < n)
		suma = suma + (licznik * licznik);

	printf("Suma kwadratow pierwszych %u liczb calkowitych = %llu\n", n, suma);

	getchar();
	getchar();
	return 0;
}