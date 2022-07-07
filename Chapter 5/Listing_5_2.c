// scale - Listing_5_2.c
// v2.0 - uzycie funkcji lokalizacji
#include <stdio.h>
#define KOREKTA 32.0 //jeden rodzaj stalej
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, ""); 		// funkcja lokalizacji (zmienia "." na ",")
	const double MNOZNIK = 1.8;	// drugi rodzaj stalej
	const char DEG = -80;		/* dla stanu domyślnego (bez uzycia funkcji lokalizacji)
								   symbolowi stopnia (°) odpowiada wartość liczbowa -8 */ 
	double deg_celsius, deg_fahrenheit;
	printf("Stopni Celsjusza\tStopni Fahrenheita\n");
	deg_celsius = -10.0;

	while (deg_celsius < 32.0)
		{
			deg_fahrenheit = MNOZNIK * deg_celsius + KOREKTA;
			printf("%9.1f %cC \t\t%9.1f %cF\n", deg_celsius, DEG, deg_fahrenheit, DEG);
			puts("------------------------------------------");
			deg_celsius = deg_celsius +5.0;
		}

	getchar();
	return 0;
}