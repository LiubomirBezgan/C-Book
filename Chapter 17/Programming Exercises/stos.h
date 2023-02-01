// stos.h - interfejs stosu
#ifndef _STOS_H_		// do ochrony przed wielokrotnym dolaczeniem
#define _STOS_H_
#include <stdbool.h>

// TUTAJ WSTAW DEFINICJE TYPU POZYCJA
// NA PRZYKLAD,
typedef char Pozycja;	// na potrzeby programu Exercise5Chapter17-Implementation.c
// LUB typedef int Pozycja;	// na potrzeby programu ???
// LUB typedef struct pozycja {int slon; int zyrafa;} Pozycja;

#define MAXSTOS 100

typedef struct stos
{
	Pozycja pozycje[MAXSTOS];		// przechowuje informacje
	int gora;						// indeks pierwszego wolnego miejsca
} Stos;

// prototypy funkcji

// dzialanie:			inicjalizuje stos
// warunki wstepne:		ws wskazuje na stos
// warunki koncowe:		stos zostaje zainicjalizowany jako pusty
void InicjujStos(Stos * ws);

// dzialanie:			sprawdza, czy stos jest pusty
// warunki wstepne:		ws wskazuje na wczesniej zainicjowany stos
// warunki koncowe:		funkcja zwraca true, jesli stos jest pusty, w przeciwnym wypadku - false
bool PustyStos(const Stos * ws);

// dzialanie:			sprawdza, czy stos jest pelny
// warunki wstepne:		ws wskazuje na wczesniej zainicjowany stos
// warunki koncowe:		funkcja zwraca true, jesli stos jest pelny, w przeciwnym wypadku - false
bool PelnyStos(const Stos * ws);

// dzialanie:			okresla liczbe pozycji w stosie
// warunki wstepne:		ws wskazuje na wczesniej zainicjowany stos
// warunki koncowe:		funkcja zwraca liczbe pozycji w stosie
int LiczbaPozycji(const Stos * ws);

// dzialanie:			ustawia pozycje na gorze stosu (push)
// warunki wstepne:		ws wskazuje na wczesniej zainicjowany stos
// warunki koncowe:		jesli jest to mozliwe, pozycja zostaje umieszczona na gorze stosu, a funkcja zwraca true;
//						w przeciwnym wypadku stos pozostaje niezmieniony, a funkcja zwraca false
bool Poloz(Pozycja pozycja, Stos * ws);

// dzialanie:			zdejmuje pozycje z gory stosu (pop)
// warunki wstepne:		ws wskazuje na wczesniej zainicjowany stos
// warunki koncowe:		jesli jest to mozliwe, pozycja z gory stosu zostaje skopiowana do *wpozycja i usunieta ze stosu, a funkcja zwraca true.
//						Jesli usunieto ostatnia pozycje, stos jest zerowany (inicjowany).
//						Jesli stos byl pusty juz wczesniej, pozostaje on bez zmian, a funkcja zwraca false.
bool Zdejmij(Pozycja *wpozycja, Stos * ws);
#endif