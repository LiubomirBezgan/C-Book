// Exercise4Chapter17.h - interfejs dla kolejki
#ifndef _KOLEJKA_H_		// do ochrony przed wielokrotnym dolaczeniem
#define _KOLEJKA_H_
#include <stdbool.h>

// TUTAJ WSTAW DEFINICJE TYPU POZYCJA
// NA PRZYKLAD,
//typedef int Pozycja;	// na potrzeby programu Listing_17_8.c
typedef struct pozycja {
	long przybycie;
	int czaskons;
} Pozycja;// na potrzeby programu Listing_17_9.c
// LUB typedef struct pozycja {int slon; int zyrafa;} Pozycja;

#define MAXKOLEJKA 10

typedef struct wezel
{
	Pozycja pozycja;
	struct wezel * nast;
} Wezel;

typedef struct kolejka
{
	Wezel * przod;		// wskaznik do przodu kolejki
	Wezel * tyl;		// wskaznik do tylu kolejki
	int pozycje;		// liczba pozycji w kolejce
} Kolejka;

// prototypy funkcji

// dzialanie:			inicjalizuje kolejke
// warunki wstepne:		wk wskazuje na kolejke
// warunki koncowe:		kolejka zostaje zainicjalizowana jako pusta
void InicjujKolejke(Kolejka * wk);

// dzialanie:			sprawdza, czy kolejka jest pusta
// warunki wstepne:		wk wskazuje na wczesniej zainicjowana kolejke
// warunki koncowe:		funkcja zwraca true, jesli kolejka jest pusta, w przeciwnym wypadku - false
bool PustaKolejka(const Kolejka * wk);

// dzialanie:			sprawdza, czy kolejka jest pelna
// warunki wstepne:		wk wskazuje na wczesniej zainicjowana kolejke
// warunki koncowe:		funkcja zwraca true, jesli kolejka jest pelna, w przeciwnym wypadku - false
bool PelnaKolejka(const Kolejka * wk);

// dzialanie:			okresla liczbe pozycji w kolejce
// warunki wstepne:		wk wskazuje na wczesniej zainicjowana kolejke
// warunki koncowe:		funkcja zwraca liczbe pozycji w kolejce
int LiczbaPozycji(const Kolejka * wk);

// dzialanie:			ustawia pozycje z tylu kolejki
// warunki wstepne:		wk wskazuje na wczesniej zainicjowana kolejke
// warunki koncowe:		jesli kolejka nie jest pusta, pozycja zostaje umieszczona z tylu kolejki, a funkcja zwraca true;
//						w przeciwnym wypadku kolejka pozostaje niezmieniona, a funkcja zwraca false
bool Ustaw(Pozycja pozycja, Kolejka * wk);

// dzialanie:			odlacza pozycje z przodu kolejki
// warunki wstepne:		wk wskazuje na wczesniej zainicjowana kolejke
// warunki koncowe:		jesli kolejka nie jest pusta, pozycja z przodu kolejki zostaje skopiowana do *wpozycja i usunieta z koleki, a funkcja zwraca true.
//						Jesli usunieto ostatnia pozycje, kolejka jest zerowana (inicjowana).
//						Jesli kolejka byla pusta juz wczesniej, pozostaje ona bez zmian, a funkcja zwraca false.
bool Odlacz(Pozycja *wpozycja, Kolejka * wk);

// dzialanie:			oproznia kolejke
// warunki wstepne:		wk wskazuje na wczesniej zainicjowana kolejke
// warunki koncowe:		kolejka jest pusta
void WyczyscKolejke(Kolejka * wk);

// dzialanie:			sprawdza, czy wszystkie kolejki sa pelne
// warunki wstepne:		wk wskazuje na wczesniej zainicjowana kolejke
//						liczba_kolejek okersla liczbe okieniek i odpowiednich kolejek
// warunki koncowe:		funkcja zwraca true, jesli kolejka jest pelna, w przeciwnym wypadku - false
bool PelneKolejki(const Kolejka * kol, int liczba_kolejek);

// dzialanie:			okresla indeks najkrotszej na ten moment kolejki 
// warunki wstepne:		wk wskazuje na wczesniej zainicjowana kolejke
//						liczba_kolejek okersla liczbe okieniek i odpowiednich kolejek
// warunki koncowe:		funkcja zwraca indeks najkrotszej na ten moment kolejki
int NajmniejszaKolejka(const Kolejka * kol, int liczba_kolejek, long ziarno);
#endif
