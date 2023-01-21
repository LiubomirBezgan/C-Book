// funkcje realizujace operacje na liscie
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// funkcje lokalne
static void KopiujDoWezla(Pozycja pozycja, Wezel * wwezel);

// funkcje interfejsu
// inicjalizuje liste jako pusta
void InicjujListe(Lista * wlista)
{
	* wlista = NULL;
}

// zwraca prawde, jesli lista jest pusta
bool PustaLista(const Lista * wlista)
{
	if (NULL == *wlista)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// zwraca prawde, jesli lista jest pelna
bool PelnaLista(const Lista * wlista)
{
	Wezel * wsk;
	bool full;
	wsk = (Wezel *) malloc(sizeof(Wezel));
	if (NULL == wsk)
	{
		full = true;
	}
	else
	{
		full = false;
	}
	free(wsk);
	return full;
}

// zwraca liczbe wezlow
unsigned int LiczbaPozycji(const Lista * wlista)
{
	unsigned int licznik = 0;
	Wezel * w = *wlista;			// ustawia na poczatek listy
	while (NULL != w)
	{
		++licznik;
		w = w->nast;				// sprawia, ze w wskazuje na nastepny wezel
	}
	return licznik;
}

// tworzy wezel przechowujacy pozycje i dodaje go na koncu
// listy wskazywanej przez wlista (wolna implemetacja)
bool DodajPozycje(Pozycja pozycja, Lista * wlista)
{
	Wezel * wnowy;
	Wezel * szuk = *wlista;
	wnowy = (Wezel *) malloc(sizeof(Wezel));

	if (NULL == wnowy)
	{
		return false;				// konczy funkcje w razie niepowodzenia
	}
	KopiujDoWezla(pozycja, wnowy);
	wnowy->nast = NULL;
	if (NULL == szuk)				// lista jest pusta,
	{
		*wlista = wnowy;			// wnowy nalezy wiec umiescic na jej poczatku
	}
	else
	{
		while (NULL != szuk->nast)
		{
			szuk = szuk->nast;
		}
		szuk->nast = wnowy;
	}
	return true;
}

// "odwiedza" kazdy wezel i wykonuje funkcje wskazywana przez wfun
void Przejdz( const Lista * wlista, void (* wfun)(Pozycja pozycja) )
{
	Wezel * wsk = *wlista;			// od poczatku listy
	while (NULL != wsk)
	{
		(*wfun)(wsk->pozycja);		// stosuje funkcje do pozycji
		wsk = wsk->nast;			// przechodzi do nastepnego wezla
	}
}

// zwalnia pamiec przydzielona przez malloc() i ustawia wskaznik na NULL
void CzyscListe(Lista * wlista)
{
	Wezel * wsk;
	while (NULL != *wlista)
	{
		wsk = (*wlista)->nast;		// zapisuje adres wezla
		free(*wlista);				// zwalnia wezel
		*wlista = wsk;				// przechodzi do nastepnego wezla
	}
}

// definicja funkcji lokalnej
// kopiuje element do wezla
static void KopiujDoWezla(Pozycja pozycja, Wezel * wwezel)
{
	wwezel->pozycja = pozycja;
}