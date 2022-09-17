// hotel.h - - stale i deklaracje dla Listing_9_10.c
#define KONIEC 5
#define HOTEL1 80.00		
#define HOTEL2 125.00
#define HOTEL3 155.00
#define HOTEL4 200.00
#define RABAT 0.95
#define GWIAZDKI "**********************"
int menu(void); 							// pokazuje liste wyborow
int pobierz_noce(void);						// zwraca zadana liczbe nocy
void pokaz_cene(double hotel, int noce);	// oblicza cene na podstawie stawki i liczby noclegow i wyswietla wynik