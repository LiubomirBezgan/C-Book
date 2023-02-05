// drzewo_z_listami.h - drzewo binarne
#ifndef _DRZEWO_H_
#define _DRZEWO_H_
#include <stdbool.h>
#include <lista_zwierzaki.h>

// typ Pozycja_drzewa nalezy zdefiniowac w zaleznosci od okolicznosci
typedef Lista Pozycja_drzewa;

#define MAXPOZ 10

typedef struct wezel_drzewa {
	Pozycja_drzewa pozycja_drzewa;
	struct wezel_drzewa * lewy;			// wskaznik do prawej galezi
	struct wezel_drzewa * prawy;		// wskaznik do lewej galezi
} Wezel_drzewa;

typedef struct drzewo {
	Wezel_drzewa * korzen;				// wskaznik do korzenia drzewa
	int rozmiar;						// liczba pozycji w drzewie
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
int LiczbaPozycjiWDrzewie(const Drzewo * wdrzewo);

// dzialanie:			dodaje pozycje do drzewa
// warunki wstepne:		wp jest adresem dodawanej pozycji
//						wdrzewo wskazuje na zainicjowane drzewo
// warunki koncowe:		jesli drzewo nie jest pusta, pozycja zostaje umieszczona z tylu kolejki, a funkcja zwraca true;
//						w przeciwnym wypadku drzewo pozostaje niezmieniona, a funkcja zwraca false
bool DodajPozycjeWDrzewie(const Pozycja_drzewa * wp, Drzewo * wdrzewo);

// dzialanie:			znajduje pozycje w drzewie
// warunki wstepne:		wp wskazuje na pozycje
//						wdrzewo wskazuje na zainicjowane drzewo
// warunki koncowe:		funkcja zwraca true, jesli pozycja znajduje sie w drzewie, a w przeciwnym wypadku - false					
bool WDrzewie(const Pozycja_drzewa * wp, const Drzewo * wdrzewo);

// dzialanie:			usuwa pozycje z drzewa
// warunki wstepne:		wp jest adresem usuwanej pozycji
//						wdrzewo wskazuje na zainicjowane drzewo
// warunki koncowe:		jesli jest to mozliwe, funkcja usuwa pozycje z drzewa i zwraca true;
//						w przeciwnym wypadku funkcja zwraca false
bool UsunPozycje(const Pozycja_drzewa * wp, Drzewo * wdrzewo);

// dzialanie:			stosuje funkcje do kazdej pozycji w drzewie
// warunki wstepne:		wfun wskazuje na funkcje, ktora przyjmuje argument typu Pozycja_drzewa i nie posiada wartosci zwracanej
//						wdrzewo wskazuje na drzewo
// warunki koncowe:		funkcja wskazywana wfun zostaje zastosowana jeden raz dla kazdej pozycji w drzewie			
void PrzejdzWDrzewie(const Drzewo * wdrzewo, void (*wfun)(Pozycja_drzewa pozycja_drzewa));

// dzialanie:			usuwa cale drzewo
// warunki wstepne:		wdrzewo wskazuje na zainicjowane drzewo
// warunki koncowe:		drzewo jest puste
void UsunWszystko(Drzewo * wdrzewo);

// dzialanie:			znajduje pozycje w drzewie
// warunki wstepne:		szukamy jest adresem poszukiwanej pozycji
//						wdrzewo wskazuje na zainicjowane drzewo
// warunki koncowe:		funkcja zwraca adres poszukiwanej pozycji w drzewie
Pozycja_drzewa * ZnajdzPozycje(const Pozycja_drzewa * szukamy, const Drzewo * wdrzewo);
#endif
