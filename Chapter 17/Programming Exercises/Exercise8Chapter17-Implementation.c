// Exercise8Chapter17-Implementation.c - funkcje do obslugi drzewa
// v1.0
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <lista_zwierzaki.h>
#include "drzewo_z_listami.h"

// lokalny typ danych
typedef struct para {
	Wezel_drzewa * rodzic;
	Wezel_drzewa * dziecko;
} Para;

// prototypy funkcji lokalnych
static Wezel_drzewa * UtworzWezel(const Pozycja_drzewa * wp);
static bool NaLewo(const Pozycja_drzewa * p1, const Pozycja_drzewa * p2);
static bool NaPrawo(const Pozycja_drzewa * p1, const Pozycja_drzewa * p2);
static void DodajWezel(Wezel_drzewa * nowy, Wezel_drzewa * korzen);
static void PoKolei(const Wezel_drzewa * korzen, void (* wfun)(Pozycja_drzewa pozycja_drzewa));
static Para SzukajPozycji(const Pozycja_drzewa * wp, const Drzewo * wdrzewo);
static void UsunWezel(Wezel_drzewa ** wsk);
static void UsunWszystkieWezly(Wezel_drzewa * wsk);

// definicje funkcji

void InicjujDrzewo (Drzewo * wdrzewo)
{
	wdrzewo->korzen = NULL;
	wdrzewo->rozmiar = 0;
}

bool PusteDrzewo(const Drzewo * wdrzewo)
{
	return (NULL == wdrzewo->korzen) ? true : false;
}

bool PelneDrzewo(const Drzewo * wdrzewo)
{
	return (MAXPOZ == wdrzewo->rozmiar) ? true : false;
}

int LiczbaPozycjiWDrzewie(const Drzewo * wdrzewo)
{
	return wdrzewo->rozmiar;
}

bool DodajPozycjeWDrzewie(const Pozycja_drzewa * wp, Drzewo * wdrzewo)
{
	Pozycja nowa_pozycja_listy;
	Wezel_drzewa * nowy;
	if (PelneDrzewo(wdrzewo))
	{
		fprintf(stderr, "Drzewo jest pelne\n");
		return false;
	}
	if (NULL != SzukajPozycji(wp, wdrzewo).dziecko)
	{
		strncpy(nowa_pozycja_listy.imie, (*wp)->pozycja.imie, ROZT);
		strncpy(nowa_pozycja_listy.gatunek, (*wp)->pozycja.gatunek, ROZT);
		DodajPozycje(nowa_pozycja_listy, &(SzukajPozycji(wp, wdrzewo).dziecko->pozycja_drzewa));
	}
	nowy = UtworzWezel(wp);					// nowy wskazuje na nowy wezel
	if (NULL == nowy)
	{
		fprintf(stderr, "Nie mozna utworzyc wezla\n");
		return false;
	}
	// utworzenie nowego wezla sie powiodlo
	wdrzewo->rozmiar++;
	if (NULL == wdrzewo->korzen)			// przypadek 1: drzewo jest puste
	{
		wdrzewo->korzen = nowy;				// nowy wezel jest korzeniem drzewa
	}
	else
	{
		DodajWezel(nowy, wdrzewo->korzen);	// przypadek 2: drzewo nie jest puste
	}
	return true;
}

bool WDrzewie(const Pozycja_drzewa * wp, const Drzewo * wdrzewo)
{
	return (NULL == SzukajPozycji(wp, wdrzewo).dziecko) ? false : true;
}

bool UsunPozycje(const Pozycja_drzewa * wp, Drzewo * wdrzewo)
{
	Para szuk;
	Pozycja poz_do_usuniecia;
	szuk = SzukajPozycji(wp, wdrzewo);
	if (NULL == szuk.dziecko)
	{
		return false;
	}
	strncpy(poz_do_usuniecia.imie, (*wp)->pozycja.imie, ROZT);
	strncpy(poz_do_usuniecia.gatunek, (*wp)->pozycja.gatunek, ROZT);
	if ( 1 == LiczbaPozycji(&(szuk.dziecko->pozycja_drzewa)) && (0 == strcmp( (szuk.dziecko->pozycja_drzewa)->pozycja.gatunek, poz_do_usuniecia.gatunek)) )
	{

		if (NULL == szuk.rodzic)		// usuwa pozycje w korzeniu
		{
			UsunWezel(&wdrzewo->korzen);
		}
		else if (szuk.rodzic->lewy == szuk.dziecko)
		{
			UsunWezel(&szuk.rodzic->lewy);
		}
		else
		{
			UsunWezel(&szuk.rodzic->prawy);
		}
	}
	else
	{
		if (!UsunPozycjeZListy( poz_do_usuniecia, &(szuk.dziecko->pozycja_drzewa) ))
		{
			return false;
		}
	}
	wdrzewo->rozmiar--;
	return true;
}

void PrzejdzWDrzewie(const Drzewo * wdrzewo, void (*wfun)(Pozycja_drzewa pozycja_drzewa))
{
	if (NULL != wdrzewo)
	{
		PoKolei(wdrzewo->korzen, wfun);
	}	
}

void UsunWszystko(Drzewo * wdrzewo)
{
	if (NULL != wdrzewo)
	{
		UsunWszystkieWezly(wdrzewo->korzen);
	}
	wdrzewo->korzen = NULL;
	wdrzewo->rozmiar = 0;
}

Pozycja_drzewa * ZnajdzPozycje(const Pozycja_drzewa * szukamy, const Drzewo * wdrzewo)
{
	return &((SzukajPozycji(szukamy, wdrzewo).dziecko)->pozycja_drzewa);	
}

// funkcje lokalne
static void PoKolei(const Wezel_drzewa * korzen, void (* wfun)(Pozycja_drzewa pozycja_drzewa))
{
	if (NULL != korzen)
	{
		PoKolei(korzen->lewy, wfun);
		(*wfun)(korzen->pozycja_drzewa);
		PoKolei(korzen->prawy, wfun);
	}
}

static void UsunWszystkieWezly(Wezel_drzewa * wsk)
{
	Wezel_drzewa * wprawy;
	if (NULL != wsk)
	{
		wprawy = wsk->prawy;
		UsunWszystkieWezly(wsk->lewy);
		free(wsk);
		UsunWszystkieWezly(wprawy);
	}	
}

static void DodajWezel(Wezel_drzewa * nowy, Wezel_drzewa * korzen)
{
	if (NaLewo(&nowy->pozycja_drzewa, &korzen->pozycja_drzewa))
	{
		if (NULL == korzen->lewy)				// puste poddziewo
		{
			korzen->lewy = nowy;				// wiec ustawiamy tu wezel
		}
		else									// w przeciwnym wypadku
		{
			DodajWezel(nowy, korzen->lewy);		// szukamy szczescia w poddrzewie
		}
	}
	else if (NaPrawo(&nowy->pozycja_drzewa, &korzen->pozycja_drzewa))
	{
		if (NULL == korzen->prawy)
		{
			korzen->prawy = nowy;
		}
		else
		{
			DodajWezel(nowy, korzen->prawy);
		}
	}
}

static bool NaLewo(const Pozycja_drzewa * p1, const Pozycja_drzewa * p2)
{
	if ( strcmp((*p1)->pozycja.imie, (*p2)->pozycja.imie) < 0 )
	{
		return true;	
	}
	else
	{
		return false;
	}
}

static bool NaPrawo(const Pozycja_drzewa * p1, const Pozycja_drzewa * p2)
{
	if ( strcmp((*p1)->pozycja.imie, (*p2)->pozycja.imie) > 0 )
	{
		return true;	
	}
	else
	{
		return false;
	}
}

static Wezel_drzewa * UtworzWezel(const Pozycja_drzewa * wp)
{
	Wezel_drzewa * nowy;
	nowy = (Wezel_drzewa *) malloc(sizeof(Wezel_drzewa));
	if (NULL != nowy)
	{
		nowy->pozycja_drzewa = *wp;
		InicjujListe(&(nowy->pozycja_drzewa));
		DodajPozycje((*wp)->pozycja, &(nowy->pozycja_drzewa));
		nowy->lewy = NULL;
		nowy->prawy = NULL;
	}
	return nowy;
}

static Para SzukajPozycji(const Pozycja_drzewa * wp, const Drzewo * wdrzewo)
{
	Para szuk;
	szuk.rodzic = NULL;
	szuk.dziecko = wdrzewo->korzen;
	if (NULL == szuk.dziecko)
	{
		return szuk;				// wczesny powrot;
	}
	while (NULL != szuk.dziecko)
	{
		if (NaLewo(wp, &(szuk.dziecko->pozycja_drzewa)))
		{
			szuk.rodzic = szuk.dziecko;
			szuk.dziecko = szuk.dziecko->lewy;
		}
		else if (NaPrawo(wp, &(szuk.dziecko->pozycja_drzewa)))
		{
			szuk.rodzic = szuk.dziecko;
			szuk.dziecko = szuk.dziecko->prawy;			
		}
		else						// jesli szukana pozycja nie znajduje sie ani po lewej, ani po prawej stronie pozycji szuk.dziecko->pozycja_drzewa,
		{							// pozycje sa identyczne; szuk.dziecko jest adresem wezla przechowujacego szukana pozycje
			break;
		}
	}
	return szuk;
}

static void UsunWezel(Wezel_drzewa ** wsk)
// wsk jest adresem skladnika rodzica, ktory wskazuje na usuwany wezel
{
	Wezel_drzewa * tymcz;
	if ( NULL == (*wsk)->lewy )			// uwzglednia tez przypadek wezla bez dzieci
	{
		tymcz = *wsk;
		*wsk = (*wsk)->prawy;
		free(tymcz);
	}
	else if (NULL == (*wsk)->prawy)
	{
		tymcz = *wsk;
		*wsk = (*wsk)->lewy;
		free(tymcz);
	}
	else		// usuwany wezel ma dwoje dzieci
	{
		// szukamy miejsca dolaczenia prawego poddrzewa
		for (tymcz = (*wsk)->lewy; NULL != tymcz->prawy; tymcz = tymcz->prawy)
		{
			continue;
		}
		tymcz->prawy = (*wsk)->prawy;
		tymcz = *wsk;
		*wsk = (*wsk)->lewy;
		free(tymcz);
	}
}