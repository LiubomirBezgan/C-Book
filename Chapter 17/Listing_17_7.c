// Listing_17_7.c - implementacja typu "kolejka"
#include <stdio.h>
#include <stdlib.h>
#include "kolejka.h"
static void KopiujDoWezla(Pozycja pozycja, Wezel * ww);
static void KopiujDoPozycji(Wezel * ww, Pozycja * wp);

void InicjujKolejke(Kolejka * wk)
{
	wk->przod = wk->tyl = NULL;
	wk->pozycje = 0;
}

bool PelnaKolejka(const Kolejka * wk)
{
	return wk->pozycje == MAXKOLEJKA;
}

bool PustaKolejka(const Kolejka * wk)
{
	return wk->pozycje == 0;
}

int LiczbaPozycji(const Kolejka * wk)
{
	return wk->pozycje;
}

bool Ustaw(Pozycja pozycja, Kolejka * wk)
{
	Wezel * wnowy;
	if (PelnaKolejka(wk))
	{
		return false;
	}
	wnowy = (Wezel *) malloc(sizeof(Wezel));
	if (NULL == wnowy)
	{
		fprintf(stderr, "Blad alokacji pamieci!\n");
		exit(1);
	}
	KopiujDoWezla(pozycja, wnowy);
	wnowy->nast = NULL;
	if (PustaKolejka(wk))
	{
		wk->przod = wnowy;
	}
	else
	{
		wk->tyl->nast = wnowy;
	}
	wk->tyl = wnowy;
	wk->pozycje++;
	return true;
}

bool Odlacz(Pozycja * wpozycja, Kolejka * wk)
{
	Wezel * wsk;
	if (PustaKolejka(wk))
	{
		return false;
	}
	KopiujDoPozycji(wk->przod, wpozycja);
	wsk = wk->przod;
	wk->przod = wk->przod->nast;
	free(wsk);
	wk->pozycje--;
	if (0 == wk->pozycje)
	{
		wk->tyl = NULL;
	}
	return true;
}

void WyczyscKolejke(Kolejka * kol)
{
	Pozycja fikcyjny;
	while ( !PustaKolejka(kol) )
	{
		Odlacz(&fikcyjny, kol);
	}
}

// Funkcje lokalne
static void KopiujDoWezla(Pozycja pozycja, Wezel * ww)
{
	ww->pozycja = pozycja;
}

static void KopiujDoPozycji(Wezel * ww, Pozycja * wp)
{
	*wp = ww->pozycja;
}