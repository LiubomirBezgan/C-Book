// opis - Exercise?Chapter?.c
// v1.0
#include <stdio.h>
#define KOREKTA 32.0 //jeden rodzaj stalej

int main(void)
{
	const double MNOZNIK = 1.8; // drugi rodzaj stalej
	double deg_celsius, deg_fahrenheit;
	printf("Stopni Celsjusza\tStopni Fahrenheita\n");
	deg_celsius = -10.0;

	while (deg_celsius < 32.0)
		{
			deg_fahrenheit = MNOZNIK * deg_celsius + KOREKTA;
			printf("%9.1f C \t\t%9.1f F\n", deg_celsius, deg_fahrenheit);
			puts("------------------------------------------");
			deg_celsius = deg_celsius +5.0;
		}

	getchar();
	return 0;
}