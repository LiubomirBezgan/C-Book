// opis - Exercise4Chapter4.c
// v1.0
#include <stdio.h>

int main(void)
{
	float speed, size;
	// const int k = ;

	puts("Prosze podac rozmiar pliku [MB] oraz predkosc pobierania [Mb/s], rozdzielajac wartosci spacja:");
	scanf("%f %f", &size, &speed);
	printf("Przy %.2f megabitow na sekunde plik o rozmiarze %.2f megabajta\n", speed, size);
	printf("zostanie pobrany w %.2f sekundy.", (8*size)/speed);
	
	getchar();
	getchar();
	return 0;
}