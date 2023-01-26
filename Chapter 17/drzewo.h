// drzewo.h - - drzewo binarne
//              drzewo nie moze zawierac dwoch jednakowych pozycji
#ifndef _DRZEWO_H_
#define _DRZEWO_H_
#include <stdbool.h>

// typ Pozycja nalezy zdefiniowac w zaleznosci od okolicznosci
typedef struct pozycja {
	char imie[20];
	char gatunek[20];
} Pozycja;

#define MAXPOZ 10

typedef struct wezel {
	Pozycja pozycja;
	struct wezel * lewy;		// wskaznik do prawej galezi
	struct wezel * prawy;		// wskaznik do lewej galezi
} Wezel;

typedef struct drzewo {
	Wezel * korzen;				// wskaznik do korzenia drzewa
	int rozmiar;				// liczba pozycji w drzewie
} Drzewo;

// prototypy funkcji
// dzialanie:			inicjalizuje drzewo jako puste
// warunki wstepne:		wdrzewo wskazuje na drzewo
// warunki koncowe:		drzewo zostalo zainicjalizowane
void InicjujDrzewo(Drzewo * wdrzewo);

// dzialanie:			okresla, czy drzewo jest puste
// warunki wstepne:		wdrzewo wskazuje na drzewo
// warunki koncowe:		funkcja zwraca true, jesli drzewo jest puste, w przeciwnym wypadku - false
bool PusteDrzewo(const Drzewo * wdrzewo);

// dzialanie:			okresla, czy drzewo jest pelne
// warunki wstepne:		wdrzewo wskazuje na drzewo
// warunki koncowe:		funkcja zwraca true, jesli drzewo jest pelne, w przeciwnym wypadku - false
bool PelneDrzewo(const Drzewo * wdrzewo);

// dzialanie:			okresla liczbe pozycji w drzewie
// warunki wstepne:		wdrzewo wskazuje na drzewo
// warunki koncowe:		funkcja zwraca liczbe pozycji w drzewie
int LiczbaPozycji(const Drzewo * wdrzewo);

// dzialanie:			dodaje pozycje do drzewa
// warunki wstepne:		wp jest adresem dodawanej pozycji
//						wdrzewo wskazuje na zainicjowane drzewo
// warunki koncowe:		jesli drzewo nie jest pusta, pozycja zostaje umieszczona z tylu kolejki, a funkcja zwraca true;
//						w przeciwnym wypadku drzewo pozostaje niezmieniona, a funkcja zwraca false
bool DodajPozycje(const Pozycja * wp, Drzewo * wdrzewo);

// dzialanie:			znajduje pozycje w drzewie
// warunki wstepne:		wp wskazuje na pozycje
//						wdrzewo wskazuje na zainicjowane drzewo
// warunki koncowe:		funkcja zwraca true, jesli pozycja znajduje sie w drzewie, a w przeciwnym wypadku - false					
bool WDrzewie(const Pozycja * wp, const Drzewo * wdrzewo);

// dzialanie:			usuwa pozycje z drzewa
// warunki wstepne:		wp jest adresem usuwanej pozycji
//						wdrzewo wskazuje na zainicjowane drzewo
// warunki koncowe:		jesli jest to mozliwe, funkcja usuwa pozycje z drzewa i zwraca true;
//						w przeciwnym wypadku funkcja zwraca false
bool UsunPozycje(const Pozycja * wp, Drzewo * wdrzewo);

// dzialanie:			stosuje funkcje do kazdej pozycji w drzewie
// warunki wstepne:		wfun wskazuje na funkcje, ktora przyjmuje argument typu Pozycja i nie posiada wartosci zwracanej
//						wdrzewo wskazuje na drzewo
// warunki koncowe:		funkcja wskazywana wfun zostaje zastosowana jeden raz dla kazdej pozycji w drzewie			
void Przejdz(const Drzewo * wdrzewo, void (*wfun)(Pozycja pozycja));

// dzialanie:			usuwa cale drzewo
// warunki wstepne:		wdrzewo wskazuje na zainicjowane drzewo
// warunki koncowe:		drzewo jest puste
void UsunWszystko(Drzewo * wdrzewo);
#endif
