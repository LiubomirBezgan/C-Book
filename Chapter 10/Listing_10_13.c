//  dzialania na wskaznikach - Listing_10_13.c
//  v1.0
#include <stdio.h>

int main(void)
{
	int urna[5] = {100, 200, 300, 400, 500};
	int * wsk1, * wsk2, * wsk3;

	wsk1 = urna;					// przypisuje adres wskaznikowi
	wsk2 = &urna[2];				// przypisuje adres wskaznikowi
	//pobranie wskaznika i pobranie wskazywanej wartosci
	puts("wartosc wskaznika,\twskazywana wartosc,\tadres wskaznika:");
	printf("wsk1 = %p,\t*wsk1 = %d,\t\t&wsk1 = %p\n", wsk1, *wsk1, &wsk1);

	// dodawanie wskaznikow
	wsk3 = wsk1 + 4;
	puts("\ndodanie int do wskaznika:");
	printf("wsk1 + 4 = %p,\t*(wsk1 + 3) = %d\n", wsk1 + 4, *(wsk1 + 3));

	// inkrementacja wskaznika
	wsk1++;
	puts("\nwartosci po wsk1++:");
	printf("wsk1 = %p,\t*wsk1 = %d,\t\t&wsk1 = %p\n", wsk1, *wsk1, &wsk1);

	// dekrementacja wskaznika
	wsk2--;
	puts("\nwartosci po wsk2--:");
	printf("wsk2 = %p,\t*wsk2 = %d,\t\t&wsk2 = %p\n", wsk2, *wsk2, &wsk2);

	// przywrocenie wartosci poczatkowych
	--wsk1;
	++wsk2;
	puts("\nWskazniki przywrocone do swoich poczatkowych wartosci:");
	printf("wsk1 = %p,\twsk2 = %p\n", wsk1, wsk2);

	// odejmowanie jednego wskaznika od drugiego
	puts("\nodejmowanie jednego wskaznika od drugiego:");
	printf("wsk2 = %p,\twsk1 = %p,\twsk2 - wsk1 = %d\n", wsk2, wsk1, wsk2 - wsk1);

	// odejmowanie zmiennej typu int od wskaznika
	puts("\nodejmowanie zmiennej typu int od wskaznika:");
	printf("wsk3 = %p,\twsk3 - 2 = %p\n", wsk3, wsk3 - 2);

	return 0;
}