// Exercise4Chapter17-Program.c - korzysta z interfejsu "kolejka"
// kompilowac lacznie z Exercise4Chapter17-Implementation.c
// v0.1
#include <stdio.h>
#include <stdlib.h>						// dla funkcji rand() i srand()
#include <time.h>						// dla funkcji time()
#include "Exercise4Chapter17.h"

#define MIN_W_GODZ 60.0
#define LICZBA_KOLEJEK 2

bool nowyklient(double x);				// czy jest nowy klient?
Pozycja czasklienta(long kiedy);		// ustawia parametry klienta

int main(void)
{
	Kolejka kol[LICZBA_KOLEJEK];
	Pozycja tymcz;							// dane o nowym kliencie
	int godz;								// liczba godzin symulacji
	int nagodz;								// srednia liczba nowych klientow na godz.
	long cykl, gran_cyklu;					// licznik petli, granica
	long odeslani = 0;						// klienci odeslani z braku miejsc
	long klienci = 0;						// klienci, ktorzy weszli do kolejki
	long obsluzeni[LICZBA_KOLEJEK] = {0};	// obsluzeni w czasie symulacji
	long suma_kol[LICZBA_KOLEJEK] = {0};	// kumulatywna dlugosc kolejki
	int czas_czek[LICZBA_KOLEJEK] = {0};	// czas do obsluzenia nastepnego klienta
	double min_na_kl;						// sredni czas miedzy przybylymi klientami
	long kol_czek[LICZBA_KOLEJEK] = {0};	// kumulatywny czas stania w kolejce
	int i;

	for (i = 0; i < LICZBA_KOLEJEK; i++)
	{
		InicjujKolejke(&(kol[i]));
	}
	srand((unsigned int) time(0));		// losowa inicjalizacja funkcji rand()
	puts("Studium przypadku: Punkt porad Zygmunta Prywaciarza");
	puts("Podaj liczbe godzin symulacji:");
	scanf("%d", &godz);
	gran_cyklu = (long) MIN_W_GODZ * godz;
	puts("Podaj srednia liczbe klientow w ciagu godziny:");
	scanf("%d", &nagodz);
	min_na_kl = (double) MIN_W_GODZ / nagodz;

	for (cykl = 0; cykl < gran_cyklu; cykl++)
	{
		if (nowyklient(min_na_kl))
		{
			if (PelneKolejki(kol, LICZBA_KOLEJEK))
			{
				odeslani++;
			}
			else
			{
				klienci++;
				tymcz = czasklienta(cykl);
				Ustaw(tymcz, &kol[NajmniejszaKolejka(kol, LICZBA_KOLEJEK, cykl)]);
			}
		}
		for (i = 0; i < LICZBA_KOLEJEK; i++)
		{
			if (czas_czek[i] <= 0 && !PustaKolejka(&kol[i]))
			{
				Odlacz(&tymcz, &kol[i]);
				czas_czek[i] = tymcz.czaskons;
				kol_czek[i] += cykl - tymcz.przybycie;
				obsluzeni[i]++;
			}
			if (czas_czek[i] > 0)
			{
				czas_czek[i]--;
			}
			suma_kol[i] += LiczbaPozycji(&kol[i]);
		}
	}
	if (klienci > 0)
	{
		printf("       klienci przyjeci do kolejki: %ld\n", klienci);
		for (i = 0; i < LICZBA_KOLEJEK; i++)
		{		
			printf("klienci obsluzeni przez %d. okienko: %ld\n", i + 1, obsluzeni[i]);
		}
		printf("                              suma: %ld\n", obsluzeni[0] + obsluzeni[1]);		
		printf("                  klienci odeslani: %ld\n", odeslani);
		for (i = 0; i < LICZBA_KOLEJEK; i++)
		{
			printf("           srednia dlugosc %d. kolejki: %.5f\n", i + 1, (double) suma_kol[i] / gran_cyklu);
		}
		for (i = 0; i < LICZBA_KOLEJEK; i++)
		{
			printf("   sredni czas oczekiwania %d. kolejki: %.2f minut\n", i + 1, (double) kol_czek[i] / obsluzeni[i]);
		}
	}
	else
	{
		puts("Brak klientow!");
	}
	for (i = 0; i < LICZBA_KOLEJEK; i++)
	{
		WyczyscKolejke(&kol[i]);
	}
	puts("Do widzenia!");
	return 0;
}


// x = sredni czas w minutach miedzy wejsciem kolejnych klientow
// wartoscia zwracana jest True, jesli w tej minucie pojawil sie klient
bool nowyklient(double x)
{
	if (rand() * x / RAND_MAX < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// kiedy jest czasem wejscia klienta do kolejki
// funkcja zwraca strukture typu Pozycja z czasem przybycia
// ustawionym na kiedy i czasem konsultacji ustawionym na
// wartosc losowa z przedzialu 1 - 3
Pozycja czasklienta(long kiedy)
{
	Pozycja klient;
	klient.czaskons = rand() % 3 + 1;
	klient.przybycie = kiedy;
	return klient;
}