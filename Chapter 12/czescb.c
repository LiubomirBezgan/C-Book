//  czescb.c - dalsza czesc programu - Listing_12_6
// kompilowac razem z czesca.c
//  v1.0
#include <stdio.h>
extern int liczba;			// deklaracja nawiazujaca, lacznosc zewnetrzna
static int suma = 0;		// definicja static, lacznosc wewnetrzna
void sumuj(int k);			// prototyp funkcji

void sumuj(int k)
{
	static int podsuma = 0; // statyczna, brak lacznosci

	if (k <= 0)
	{
		printf("Cykl petli: %d\n", liczba);
		printf("Podsuma: %d; Suma: %d\n", podsuma, suma);
		podsuma = 0;
	}
	else
	{
		podsuma += k;
		suma += k;
	}
}