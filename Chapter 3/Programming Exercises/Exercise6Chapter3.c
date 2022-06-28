// opis - Exercise6Chapter3.c
// v1.0
#include <stdio.h>

int main(void)
{
	
	float litry = 0.0f;		// [l] podawana objetosc
	float m = 3.0e-23;		// [g] masa jednej czasteczki wody
	float n;				// [ ] liczba czasteczki wody w podanej objetosci
	float density = 997.3;	// [g/l] gestosc wody przy 24 °C
	
	puts("Prosze podac objetosc w litrach:");
	scanf("%f", &litry);

	n = (litry * density)/m;
	printf("W %.2f litach miesci sie %e czasteczek wody\n", litry, n);
	
	getchar();
	getchar();
	return 0;
}