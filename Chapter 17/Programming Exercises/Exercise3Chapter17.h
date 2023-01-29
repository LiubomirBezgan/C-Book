// Exercise3Chapter17.h - plik naglowkowy dla typu "prosta lista"
#ifndef _LISTA_H_
#define _LISTA_H_
#include <stdbool.h>
// deklaracje szczegolne programu
#define ROZT 45
#define MAXROZM 100
struct film
{
	char tytul[ROZT];
	int ocena;
};

// ogolne definicje typow
typedef struct film Pozycja;

typedef struct lista {
	Pozycja wpisy[MAXROZM];			// tablica pozycja
	int pozycje;					// liczba pozycji w liscie
} Lista;

// prototypy funkcji

// dzialanie:			inicjalizuje liste
// warunki wstepne:		wlista wskazuje na liste
// warunki koncowe:		lista zostaje zainicjalizowana jako pusta
void InicjujListe(Lista * wlista);

// dzialanie:			okresla, czy lista jest pusta
// warunki wstepne:		wlista wskazuje na zainicjalizowana liste
// warunki koncowe:		funkcja zwraca true, jesli lista jest pusta, a w przeciwnym wypadku false
bool PustaLista(const Lista * wlista);

// dzialanie:			okresla, czy lista jest pelna
// warunki wstepne:		wlista wskazuje na zainicjalizowana liste
// warunki koncowe:		funkcja zwraca true, jesli lista jest pelna, a w przeciwnym wypadku false
bool PelnaLista(const Lista * wlista);

// dzialanie:			okresla liczbe pozycji w liscie
// warunki wstepne:		wlista wskazuje na zainicjalizowana liste
// warunki koncowe:		funkcja zwraca liczbe pozycji w liscie
unsigned int LiczbaPozycji(const Lista * wlista);

// dzialanie:			dodaje pozycje na koncu listy
// warunki wstepne:		pozycja jest pozycja do dodania
//						wlista wskazuje na zainicjalizowana liste
// warunki koncowe:		jesli jest to mozliwe, funkcja podaje pozycja na koncu listy i zwaraca true;
//						w przeciwnym wypadku funkcja zwraca false
bool DodajPozycje(Pozycja pozycja, Lista * wlista);

// dzialanie:			stosuje funkcje do kazdej pozycji w liscie
// warunki wstepne:		wlista wskazuje na zainicjalizowana liste
//						wfun wskazuje na funcje, ktora pobiera argument typu Pozycja i nie ma wartosci zwracanej
// warunki koncowe:		funkcja wskazywana przez wfun jest uruchomiana jeden raz dla kazdej pozycji w liscie
void Przejdz(const Lista * wlista, void (* wfun)(Pozycja pozycja) );

#endif