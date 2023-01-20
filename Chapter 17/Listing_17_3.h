// plik naglowkowy dla typu "prosta lista"
#ifndef _LISTA_H_
#define _LISTA_H_
#include <stdbool.h>
// deklaracje szczegolne programu
#define ROZT 45
struct film
{
	char tytul[ROZT];
	int ocena;
};
// ogolne definicje typow
typedef struct film Pozycja;
typedef struct wezel
{
	Pozycja pozycja;
	struct wezel * nast;
} Wezel;
typedef wezel * Lista;
// prototypy funkcji

// dzilanie:			inicjalizuje liste
// warunki wstepne:		wlista wskazuje na liste
// waunki koncowe:		lista zostaje zainicjalizowana jako pusta
void InicjujListe(Lista * wlista);

// dzilanie:			okresla, czy lista jest pusta
// warunki wstepne:		wlista wskazuje na zainicjalizowana liste
// waunki koncowe:		funkcja zwraca true, jesli lista jest pusta, a w przeciwnym wypadku false
bool PustaLista(const Lista * wlista);

// dzilanie:			okresla, czy lista jest pusta
// warunki wstepne:		wlista wskazuje na zainicjalizowana liste
// waunki koncowe:		funkcja zwraca true, jesli lista jest pelna, a w przeciwnym wypadku false
bool PelnaLista(const Lista * wlista);

// dzilanie:			okresla liste pozycji w liscie
// warunki wstepne:		wlista wskazuje na zainicjalizowana liste
// waunki koncowe:		funkcja zwraca liczbe pozycji w liscie
unsigned int LiczbaPozycji(const Lista * wlista);

// dzilanie:			dodaje pozycje na koncu listy
// warunki wstepne:		pozycja jest pozycja do dodania
//						wlista wskazuje na zainicjalizowana liste
// waunki koncowe:		jesli jest to mozliwe, funkcja podaje pozycja na koncu listy i zwaraca true;
//						w przeciwnym wypadku funkcja zwraca false
bool DodajPozycje(Pozycja pozycja, Lista * wlista);

// dzilanie:			stosuje funkcje do kazdej pozycji w liscie
// warunki wstepne:		wlista wskazuje na zainicjalizowana liste
//						wfun wskazuje na funcje, ktora pobiera argument typu Pozycja i nie ma wartosci zwracanej
// waunki koncowe:		funkcja wskazywana przez wfun jest uruchomiana jeden raz dla kazdej pozycji w liscie
void Przejdz(const Lista * wlista, void (* wfun)(Pozycja pozycja) );

// dzilanie:			zwalnia pamiec zajmowana przez liste
// warunki wstepne:		wlista wskazuje na zainicjalizowana liste
// waunki koncowe:		pamiec zostaje zwolniona
//						wlista ma wartosc NULL
void CzyscListe(const Lista * wlista);
#endif