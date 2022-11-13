//  czesca.c - rozne klasy zmiennych - Listing_12_5
// kompilowac razem z czescb.c
//  v1.0
#include <stdio.h>
void podaj_liczbe();
void sumuj(int k);
int liczba = 0;			// zasieg plikowy, lacznosc zewnetrzna

int main(void)
{
	int wartosc;		// zmienna automatyczna
	register int i;		// zmienna rejestrowa

	printf("Podaj dodatnia liczbe calkowita (0 to koniec): ");
	while (scanf("%d", &wartosc) == 1 && wartosc > 0)
	{
		++liczba;		// zmienna o zasiegu plikowym
		for (i = wartosc; i >= 0; i--)
		{
			sumuj(i);
		}
		printf("Podaj dodatnia liczbe calkowita (0 to koniec): ");		
	}
	podaj_liczbe();

	return 0;
}

void podaj_liczbe()
{
	printf("Petle opuszczono po %d cyklach\n", liczba);
}