// bieg - Listing_5_16.c
// v1.0
#include <stdio.h>
#define S_W_M 60
const int S_W_H = 3600;

int main(void)
{
	double dyst, predkosc, czas_km;
	int min, sek, czas, min_km, sek_km;

	puts("Ten program zamienia Twoj czas w biegu na dowolny dystans");
	puts("na czas przebiegniecia 1 km oraz na srednia predkosc w km/h.");
	puts("Wpisz pokonana odleglosc w kilometrach:");
	scanf("%lf", &dyst);
	puts("Wpisz swoj czas w minutach i sekundach.");
	puts("Zacznij od podania liczby minut:");
	scanf("%d", &min);
	puts("Teraz podaj liczbe sekund:");
	scanf("%d", &sek);

	czas = S_W_M * min + sek; 			// [s]
	predkosc = dyst / czas * S_W_H;		// [km/h]
	czas_km = (double) czas / dyst;
	min_km = (int) czas_km / S_W_M;
	sek_km = (int) czas_km % S_W_M;
	printf("Przebiegles %1.2f km w czasie %d minut, %d sekund.\n", dyst, min, sek);
	printf("Odpowiada to przebiegnieciu 1 km w czasie %d minut, ", min_km);
	printf("%d sekund.\nTwoja srednia predkosc to %1.2f km/h.\n", sek_km, predkosc);

	getchar();
	getchar();
	return 0;
}