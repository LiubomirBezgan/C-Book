// opis - Exercise4Chapter4.c
// v1.0
#include <stdio.h>

int main(void)
{
	float wzrost;
	char imie[20];

	puts("Prosze podac swoj wzrost w centymetrach:");
	scanf("%f", &wzrost);
	puts("Prosze podac swoje imie:");
	scanf("%s", imie);
	printf("%s, masz %.2f metra wzrostu.", imie, wzrost/100);
	
	getchar();
	getchar();
	return 0;
}