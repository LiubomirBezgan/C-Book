// Funkcja f(x) = x^3 - Exercise7Chapter5.c
// v2.0
#include <stdio.h>

double szescian(float x)
{
	return x*x*x;
}

int main(void)
{
	float wartosc;

	puts("Program podnosi do szescianu podana wartosc i wyswietla ja.");
	puts("Prosze wprowadzic wartosc:");
	scanf("%f", &wartosc);
	printf("(%g)^3 = ", wartosc);
	//szescian(wartosc);
	printf("%g", szescian(wartosc));
	getchar();
	getchar();
	return 0;
}