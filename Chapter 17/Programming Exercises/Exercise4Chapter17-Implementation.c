// Exercise4Chapter17-Implementation.c - implementacja typu "kolejka"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Exercise4Chapter17.h"
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

bool PelneKolejki(const Kolejka * kol, int liczba_kolejek)
{
	int i;
	for (int i = 0; i < liczba_kolejek; ++i)
	{
		if (!PelnaKolejka(&kol[i]))
		{
			return false;
		}
	}
	return true;
}

int NajmniejszaKolejka(const Kolejka * kol, int liczba_kolejek, long ziarno)
{
	//int indeks = 0;
	//int tymcz = MAXKOLEJKA;
	//int i;

	srand((unsigned int) time(0) + ziarno);

	if (2 == liczba_kolejek)
	{
		if ( LiczbaPozycji(&kol[0]) > LiczbaPozycji(&kol[1]) )
		{
			return 1;
		}
		else if ( LiczbaPozycji(&kol[0]) < LiczbaPozycji(&kol[1]) )
		{
			return 0;
		}
		else	// jesli LiczbaPozycji(&kol[0]) == LiczbaPozycji(&kol[1])
		{
			return (int) rand() % 2;	// losowo zwraca 0 albo 1
		}
	}
	/*else
	{
		// nalezy dopisac ogolny przypadek:
		// okreslenie najmniejszej liczby pozycji, tworzenie listy wskaznikow na kolejki o najm. liczbie pozycji,
		// losowy wybor wsrod ww. wskaznikow, podanie indeksu kolejki na podstawie wybranego losowo wskaznika

		for (int i = 0; i < liczba_kolejek; ++i)
		{
			if (LiczbaPozycji(&kol[i]) < tymcz)
			{
				indeks = i;
				tymcz = LiczbaPozycji(&kol[i]);
			}
		}
	}
	return indeks;*/
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