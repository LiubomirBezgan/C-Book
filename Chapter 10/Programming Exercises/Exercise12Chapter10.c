//  znajduje sumy roczne, roczna srednia oraz srednia miesieczna dla danych o opadach z kilku lat (funkcje) - Exercise12Chapter10.c
//  v1.0
#include <stdio.h>
#define MIESIACE 12
#define LATA 5
void pokaz_sume_z_lat(const float (*tab)[MIESIACE], int lata, int poczatek);
float roczna_srednia(const float (*tab)[MIESIACE], int lata);
void srednie_miesieczne(const float (*tab)[MIESIACE], int lata);

int main(void)
{
	// inicjalizacja danych o opadach z lat 2010-2014
	const float deszcz[LATA][MIESIACE] = 
	{
		{4.3, 4.3 ,4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
		{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
		{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
		{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
		{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
	};

	pokaz_sume_z_lat(deszcz, LATA, 2010);
	printf("\nRoczna srednia wynosi %.1f cale\n\n", roczna_srednia(deszcz, LATA));
	srednie_miesieczne(deszcz, LATA);
	return 0;
}


void pokaz_sume_z_lat(const float tab[][MIESIACE], int lata, int poczatek)
{
	int rok, miesiac;
	float podsuma;
	puts(" ROK       OPADY (w calach)");
	for (rok = 0; rok < lata; rok++)
	{
		for (miesiac = 0, podsuma = 0; miesiac < MIESIACE; miesiac++)
		{
			podsuma += tab[rok][miesiac];
		}
		printf("%4d %12.1f\n", poczatek + rok, podsuma);
	}
}

float roczna_srednia(const float tab[][MIESIACE], int lata)
{
	int rok, miesiac;
	float podsuma, suma;
	for (rok = 0, suma = 0; rok < lata; rok++)
	{
		for (miesiac = 0, podsuma = 0; miesiac < MIESIACE; miesiac++)
		{
			podsuma += tab[rok][miesiac];
		}
		suma += podsuma;
	}
	return suma/lata;
}

void srednie_miesieczne(const float tab[][MIESIACE], int lata)
{
	int rok, miesiac;
	float podsuma;
	puts("SREDNIE MIESIECZNE:");
	puts(" Sty  Lut  Mar  Kwi  Maj  Cze  Lip  Sie  Wrz  Paz  Lis  Gru");

	for (miesiac = 0; miesiac < MIESIACE; miesiac++)
	{
		for (rok = 0, podsuma = 0; rok < lata; rok++)
		{
			podsuma += tab[rok][miesiac];
		}
		printf("%4.1f ", podsuma/lata);
	}
	putchar('\n');
}