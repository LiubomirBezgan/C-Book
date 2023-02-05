// korzysta z drzewa binarnego
// v1.0
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <lista_zwierzaki.h>
#include "drzewo_z_listami.h"

char menu(void);
void dodajzw(Drzewo * wd);
void usunzw(Drzewo * wd);
void pokazzw(const Drzewo * wd);
void szukajzw(const Drzewo * wd);
void wyswpoz(Pozycja_drzewa pozycja_drzewa);
void duzelit(char * lan);
char * wczytaj(char *z, int ile);

int main(void)
{
	Drzewo zwierz;
	char wybor;
	InicjujDrzewo(&zwierz);
	while ('q' != (wybor = menu()))
	{
		switch(wybor)
		{
			case 'd' : dodajzw(&zwierz);
					   break;
			case 'w' : pokazzw(&zwierz);
					   break;
			case 's' : szukajzw(&zwierz);
					   break;
			case 'l' : printf("%d zwierzat w klubie.\n", LiczbaPozycjiWDrzewie(&zwierz));
					   break;
			case 'u' : usunzw(&zwierz);
					   break;
			default : puts("Blad w instrukcji switch");
		}
	}
	UsunWszystko(&zwierz);
	puts("Do widzenia.");
	return 0;
}

char menu(void)
{
	int ch;
	puts("\nKlub Zwierzat Domowych - baza danych czlonkow");
	puts("Podaj litere odpowiadajaca wybranej opcji:");
	puts("d) dodaj zwierze      w) wyswietl liste zwierzat");
	puts("l) liczba zwierzat    s) szukaj zwierzecia");
	puts("u) usun zwierze       q) koniec");
	while (EOF != (ch = getchar()))
	{
		while ('\n' != getchar())		// porzuca reszte wiersza
		{
			continue;
		}
		ch = tolower(ch);
		if (NULL == strchr("dwlsuq", ch))
		{
			puts("Wpisz d, w, l, s, u lub q:");
		}
		else
		{
			break;
		}
	}
	if (EOF == ch)						// sprawia, że EOF konczy program
	{
		ch = 'q';
	}
	return ch;
}

void dodajzw(Drzewo * wd)
{
	Pozycja_drzewa tymcz;
	Pozycja tymcz_p_listy;
	if (PelneDrzewo(wd))
	{
		puts("Brak wolnych miejsc w klubie!");
	}
	else
	{
		InicjujListe(&tymcz);
		puts("Podaj imie zwierzecia:");
		wczytaj(tymcz_p_listy.imie, ROZT);
		puts("Podaj gatunek zwierzecia:");
		wczytaj(tymcz_p_listy.gatunek, ROZT);
		duzelit(tymcz_p_listy.imie);
		duzelit(tymcz_p_listy.gatunek);
		DodajPozycje(tymcz_p_listy, &tymcz);
		DodajPozycjeWDrzewie(&tymcz, wd);
	}
}

void pokazzw(const Drzewo * wd)
{
	if (PusteDrzewo(wd))
	{
		puts("Brak pozycji!");
	}
	else
	{
		PrzejdzWDrzewie(wd, wyswpoz);
	}
}

void wyswpoz(Pozycja_drzewa pozycja_drzewa)
{
	Wezel * wsk;
	wsk = pozycja_drzewa->nast; // nie rabotajet
	
	Wezel * biezacy;
	biezacy = pozycja_drzewa;
	while (NULL != wsk)
	{
		printf("Zwierze: %-19s Gatunek: %-19s\n", biezacy->pozycja.imie, biezacy->pozycja.gatunek);
		biezacy = wsk;
		wsk = wsk->nast;
	}
	printf("Zwierze: %-19s Gatunek: %-19s\n", biezacy->pozycja.imie, biezacy->pozycja.gatunek);
}

void szukajzw(const Drzewo * wd)
{
	Pozycja_drzewa tymcz;
	Pozycja_drzewa * poszukiwana;
	if (PusteDrzewo(wd))			// jesli drzewo jest puste
	{
		puts("Brak pozycji!");
		return;						// wychodzi z funkcji
	}
	puts("Podaj imie zwierzecia, ktore chcesz znalesc:");
	wczytaj(tymcz->pozycja.imie, ROZT);
	duzelit(tymcz->pozycja.imie);

	if (WDrzewie(&tymcz, wd))
	{
		poszukiwana = ZnajdzPozycje(&tymcz, wd);
		wyswpoz(*poszukiwana);
	}
	else
	{
		printf("%s nie jest czlonkiem klubu.\n", tymcz->pozycja.imie);
	}	
}

void usunzw(Drzewo * wd)
{
	Pozycja_drzewa tymcz;
	Pozycja tymcz_p_listy;	
	if (PusteDrzewo(wd))			// jesli drzewo jest puste
	{
		puts("Brak pozycji!");
		return;						// wychodzi z funkcji
	}
	InicjujListe(&tymcz);
	puts("Podaj imie zwierzecia, ktore chcesz usunac:");
	wczytaj(tymcz_p_listy.imie, ROZT);
	puts("Podaj gatunek zwierzecia:");
	wczytaj(tymcz_p_listy.gatunek, ROZT);
	duzelit(tymcz_p_listy.imie);
	duzelit(tymcz_p_listy.gatunek);	
	DodajPozycje(tymcz_p_listy, &tymcz);	
	printf("%s, %s ", tymcz->pozycja.imie, tymcz->pozycja.gatunek);
	if (UsunPozycje(&tymcz, wd))
	{
		printf("zostal(a) usuniety/a z klubu.\n");
	}
	else
	{
		printf("nie jest czlonkiem klubu.\n");
	}
}

void duzelit(char * lan)
{
	while ('\0' != *lan)
	{
		*lan = toupper(*lan);
		lan++;
	}
}

char *wczytaj(char * z, int ile)
{
	char * wynik;
	char * tutaj;
	wynik = fgets(z, ile, stdin);
	if (wynik)
	{
		tutaj = strchr(z, '\n');		// szukamy nowego wiersza
		if (tutaj)						// jesli adres jest rozny od NULL
		{
			*tutaj = '\0';
		}
		else
		{
			while ('\n' != getchar())
			{
				continue;
			}
		}
	}
	return wynik;
}