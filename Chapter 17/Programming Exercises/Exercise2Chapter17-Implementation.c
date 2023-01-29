// Exercise2Chapter17-Implementation.c - funkcje realizujace operacje na liscie
#include <stdio.h>
#include <stdlib.h>
#include "Exercise2Chapter17.h"

// funkcje lokalne
static void KopiujDoWezla(Pozycja pozycja, Wezel * wwezel);
static void RekurencjaOdKonca(Wezel * wwezel, void (* wfun)(Pozycja pozycja) );

// funkcje interfejsu
// inicjalizuje liste jako pusta
void InicjujListe(Lista * wlista)
{
	wlista->glowny = NULL;
	wlista->koniec = NULL;
}

// zwraca prawde, jesli lista jest pusta
bool PustaLista(const Lista * wlista)
{
	if (NULL == wlista->glowny && NULL == wlista->koniec)
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
	Wezel * w = wlista->glowny;			// ustawia na poczatek listy
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
	Wezel * szuk = wlista->glowny;
	wnowy = (Wezel *) malloc(sizeof(Wezel));

	if (NULL == wnowy)
	{
		return false;				// konczy funkcje w razie niepowodzenia
	}
	KopiujDoWezla(pozycja, wnowy);
	wnowy->nast = NULL;
	if (NULL == szuk)				// lista jest pusta,
	{
		wlista->glowny = wnowy;			// wnowy nalezy wiec umiescic na jej poczatku
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
	Wezel * wsk = wlista->glowny;			// od poczatku listy
	while (wlista->koniec != wsk)
	{
		(*wfun)(wsk->pozycja);		// stosuje funkcje do pozycji
		wsk = wsk->nast;			// przechodzi do nastepnego wezla
	}
}

// "odwiedza" kazdy wezel od konca listy do jej poczatku i wykonuje funkcje wskazywana przez wfun
void OdKonca(const Lista * wlista, void (* wfun)(Pozycja pozycja) )
{
	RekurencjaOdKonca(wlista->glowny, wfun);
}

// zwalnia pamiec przydzielona przez malloc() i ustawia wskaznik na NULL
void CzyscListe(Lista * wlista)
{
	Wezel * wsk;
	while (NULL != wlista->glowny)
	{
		wsk = (wlista->glowny)->nast;		// zapisuje adres wezla
		free(wlista->glowny);				// zwalnia wezel
		wlista->glowny = wsk;				// przechodzi do nastepnego wezla
	}
}

// definicja funkcji lokalnej
// kopiuje element do wezla
static void KopiujDoWezla(Pozycja pozycja, Wezel * wwezel)
{
	wwezel->pozycja = pozycja;
}

// rekurencja 
static void RekurencjaOdKonca(Wezel * wwezel, void (* wfun)(Pozycja pozycja) )
{
	if (NULL != wwezel)
	{
		RekurencjaOdKonca(wwezel->nast, wfun);
		(*wfun)(wwezel->pozycja);		// stosuje funkcje do pozycji
	}
}