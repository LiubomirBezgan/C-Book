// funkcje realizujace operacje na liscie
#include <stdio.h>
#include <stdlib.h>
#include "Exercise3Chapter17.h"

// funkcje interfejsu
// inicjalizuje liste jako pusta
void InicjujListe(Lista * wlista)
{
	int i;
	wlista->pozycje = 0;
	for (i = 0; i < MAXROZM; i++)
	{
		wlista->wpisy[i].ocena = 0;
		wlista->wpisy[i].tytul[0] = '\0';
	}
}

// zwraca prawde, jesli lista jest pusta
bool PustaLista(const Lista * wlista)
{
	if (0 == wlista->pozycje)
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
	if (MAXROZM == wlista->pozycje)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// zwraca liczbe wezlow
unsigned int LiczbaPozycji(const Lista * wlista)
{
	return (unsigned int) wlista->pozycje;
}

// tworzy wezel przechowujacy pozycje i dodaje go na koncu
// listy wskazywanej przez wlista (wolna implemetacja)
bool DodajPozycje(Pozycja pozycja, Lista * wlista)
{

	if (PelnaLista(wlista))
	{
		return false;				// konczy funkcje w razie niepowodzenia
	}
	wlista->wpisy[wlista->pozycje] = pozycja;
	wlista->pozycje++;
	return true;
}

// "odwiedza" kazdy wezel i wykonuje funkcje wskazywana przez wfun
void Przejdz( const Lista * wlista, void (* wfun)(Pozycja pozycja) )
{
	int i;
	for (i = 0; i < wlista->pozycje; i++)
	{
		(*wfun)(wlista->wpisy[i]);
	}
}
