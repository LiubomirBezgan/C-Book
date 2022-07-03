// opis - Exercise3Chapter4.c
// v1.0
#include <stdio.h>

int main(void)
{
	float liczba;

	puts("Prosze podac liczbe zmiennoprzecinkowa:");
	scanf("%f", &liczba);
	printf("Wpisano liczbe %.1f lub %.1e.\n", liczba, liczba); // a)
	printf("Wpisano liczbe %+.3f lub %.3e.\n", liczba, liczba); // b)
	
	getchar();
	getchar();
	return 0;
}