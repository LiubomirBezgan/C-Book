// funkcje do obslugi drzewa
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "drzewo.h"

// lokalny typ danych
typedef struct para {
	Wezel * rodzic;
	Wezel * dziecko;
} Para;

// prototypy funkcji lokalnych
static Wezel * UtworzWezel(const Pozycja * wp);
static bool NaLewo(const Pozycja * p1, const Pozycja * p2);
static bool NaPrawo(const Pozycja * p1, const Pozycja * p2);
static void DodajWezel(Wezel * nowy, Wezel * korzen);
static void PoKolei(const Wezel * korzen, void (* wfun)(Pozycja pozycja));
static Para SzukajPozycji(const Pozycja * wp, const Drzewo * wdrzewo);
static void UsunWezel(Wezel ** wsk);
static void UsunWszystkieWezly(Wezel * wsk);

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

int LiczbaPozycji(const Drzewo * wdrzewo)
{
	return wdrzewo->rozmiar;
}

bool DodajPozycje(const Pozycja * wp, Drzewo * wdrzewo)
{
	Wezel * nowy;
	if (PelneDrzewo(wdrzewo))
	{
		fprintf(stderr, "Drzewo jest pelne\n");
		return false;
	}
	if (NULL != SzukajPozycji(wp, wdrzewo).dziecko)
	{
		fprintf(stderr, "Proba dodania istniejacej pozycji\n");
		return false;
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
		wdrzewo->korzen = nowy;			// nowy wezel jest korzeniem drzewa
	}
	else
	{
		DodajWezel(nowy, wdrzewo->korzen);	// przypadek 2: drzewo nie jest puste
	}
	return true;
}

bool WDrzewie(const Pozycja * wp, const Drzewo * wdrzewo)
{
	return (NULL == SzukajPozycji(wp, wdrzewo).dziecko) ? false : true;
}

bool UsunPozycje(const Pozycja * wp, Drzewo * wdrzewo)
{
	Para szuk;
	szuk = SzukajPozycji(wp, wdrzewo);
	if (NULL == szuk.dziecko)
	{
		return false;
	}
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
	wdrzewo->rozmiar--;
	return true;
}

void Przejdz(const Drzewo * wdrzewo, void (*wfun)(Pozycja pozycja))
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


// funkcje lokalne
static void PoKolei(const Wezel * korzen, void (* wfun)(Pozycja pozycja))
{
	if (NULL != korzen)
	{
		PoKolei(korzen->lewy, wfun);
		(*wfun)(korzen->pozycja);
		PoKolei(korzen->prawy, wfun);
	}
}

static void UsunWszystkieWezly(Wezel * wsk)
{
	Wezel * wprawy;
	if (NULL != wsk)
	{
		wprawy = wsk->prawy;
		UsunWszystkieWezly(wsk->lewy);
		free(wsk);
		UsunWszystkieWezly(wprawy);
	}	
}

static void DodajWezel(Wezel * nowy, Wezel * korzen)
{
	if (NaLewo(&nowy->pozycja, &korzen->pozycja))
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
	else if (NaPrawo(&nowy->pozycja, &korzen->pozycja))
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
	else										// nie powinno byc dwoch identycznych pozycji
	{
		fprintf(stderr, "Blad funkcji DodajWezel()\n");
		exit(1);
	}
}

static bool NaLewo(const Pozycja * p1, const Pozycja * p2)
{
	int porown1;
	if ( (porown1 = strcmp(p1->imie, p2->imie)) < 0 )
	{
		return true;	
	}
	else if (0 == porown1 && strcmp(p1->gatunek, p2->gatunek) < 0)
	{
		return true;	
	}
	else
	{
		return false;
	}
}

static bool NaPrawo(const Pozycja * p1, const Pozycja * p2)
{
	int porown1;
	if ( (porown1 = strcmp(p1->imie, p2->imie)) > 0 )
	{
		return true;	
	}
	else if (0 == porown1 && strcmp(p1->gatunek, p2->gatunek) > 0)
	{
		return true;	
	}
	else
	{
		return false;
	}
}

static Wezel * UtworzWezel(const Pozycja * wp)
{
	Wezel * nowy;
	nowy = (Wezel *) malloc(sizeof(Wezel));
	if (NULL != nowy)
	{
		nowy->pozycja = *wp;
		nowy->lewy = NULL;
		nowy->prawy = NULL;
	}
	return nowy;
}

static Para SzukajPozycji(const Pozycja * wp, const Drzewo * wdrzewo)
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
		if (NaLewo(wp, &(szuk.dziecko->pozycja)))
		{
			szuk.rodzic = szuk.dziecko;
			szuk.dziecko = szuk.dziecko->lewy;
		}
		else if (NaPrawo(wp, &(szuk.dziecko->pozycja)))
		{
			szuk.rodzic = szuk.dziecko;
			szuk.dziecko = szuk.dziecko->prawy;			
		}
		else						// jesli szukana pozycja nie znajduje sie ani po lewej, ani po prawej stronie pozycji szuk.dziecko->pozycja,
		{							// pozycje sa identyczne; szuk.dziecko jest adresem wezla przechowujacego szukana pozycje
			break;
		}
	}
	return szuk;
}

static void UsunWezel(Wezel ** wsk)
// wsk jest adresem skladnika rodzica, ktory wskazuje na usuwany wezel
{
	Wezel * tymcz;
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