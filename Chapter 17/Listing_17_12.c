// korzysta z drzewa binarnego
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "drzewo.h"
#define MAXROZ 20
char menu(void);
void dodajzw(Drzewo * wd);
void usunzw(Drzewo * wd);
void pokazzw(const Drzewo * wd);
void szukajzw(const Drzewo * wd);
void wyswpoz(Pozycja pozycja);
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
			case 'l' : printf("%d zwierzat w klubie.\n", LiczbaPozycji(&zwierz));
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
	Pozycja tymcz;
	if (PelneDrzewo(wd))
	{
		puts("Brak wolnych miejsc w klubie!");
	}
	else
	{
		puts("Podaj imie zwierzecia:");
		wczytaj(tymcz.imie, MAXROZ);
		puts("Podaj gatunek zwierzecia:");
		wczytaj(tymcz.gatunek, MAXROZ);
		duzelit(tymcz.imie);
		duzelit(tymcz.gatunek);
		DodajPozycje(&tymcz, wd);		
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
		Przejdz(wd, wyswpoz);
	}
}

void wyswpoz(Pozycja pozycja)
{
	printf("Zwierze: %-19s Gatunek %-19s\n", pozycja.imie, pozycja.gatunek);
}

void szukajzw(const Drzewo * wd)
{
	Pozycja tymcz;
	if (PusteDrzewo(wd))			// jesli drzewo jest puste
	{
		puts("Brak pozycji!");
		return;						// wychodzi z funkcji
	}
	puts("Podaj imie zwierzecia, ktore chcesz znalesc:");
	wczytaj(tymcz.imie, MAXROZ);
	puts("Podaj gatunek zwierzecia:");
	wczytaj(tymcz.gatunek, MAXROZ);
	duzelit(tymcz.imie);
	duzelit(tymcz.gatunek);
	printf("%s, %s ", tymcz.imie, tymcz.gatunek);
	if (WDrzewie(&tymcz, wd))
	{
		printf("jest czlonkiem klubu.\n");
	}
	else
	{
		printf("nie jest czlonkiem klubu.\n");
	}
}

void usunzw(Drzewo * wd)
{
	Pozycja tymcz;
	if (PusteDrzewo(wd))			// jesli drzewo jest puste
	{
		puts("Brak pozycji!");
		return;						// wychodzi z funkcji
	}
	puts("Podaj imie zwierzecia, ktore chcesz usunac:");
	wczytaj(tymcz.imie, MAXROZ);
	puts("Podaj gatunek zwierzecia:");
	wczytaj(tymcz.gatunek, MAXROZ);
	duzelit(tymcz.imie);
	duzelit(tymcz.gatunek);
	printf("%s, %s ", tymcz.imie, tymcz.gatunek);
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