//  wskazniki i malloc() - Listing_14_10.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DL 81

struct daneos {
	char * imie;
	char * nazw;
	int litery;
};
void pobierz(struct daneos *);				// alokuje pamiec
void oblicz(struct daneos *);
void pokaz(const struct daneos *);
void wyczysc(struct daneos *);				// zwalnia pamiec
char * wczytaj (char * z, int ile);

int main(void)
{
	struct daneos osoba;
	pobierz(&osoba);
	oblicz(&osoba);
	pokaz(&osoba);
	wyczysc(&osoba);

	return 0;
}

void pobierz(struct daneos * wsk)
{
	char temp[DL];
	printf("Podaj swoje imie.\n");
	wczytaj(temp, DL);
	wsk->imie = (char *) malloc(strlen(temp) + 1);
	strcpy(wsk->imie, temp);
	printf("Podaj swoje nazwisko.\n");
	wczytaj(temp, DL);
	wsk->nazw = (char *) malloc(strlen(temp) + 1);
	strcpy(wsk->nazw, temp);
}

void oblicz(struct daneos * wsk)
{
	wsk->litery = strlen(wsk->imie) + strlen(wsk->nazw);
}

void pokaz(const struct daneos * wsk)
{
	printf("%s %s, Twoje imie i nazwisko skladaja sie z %d liter.\n", wsk->imie, wsk->nazw, wsk->litery);
}

void wyczysc(struct daneos * wsk)
{
 	free(wsk->imie);
 	free(wsk->nazw);
}

char * wczytaj(char * z, int ile)
{
	char * wynik;
	char * tutaj;
	wynik = fgets(z, ile, stdin);
	if (wynik)
	{
		tutaj = strchr(z, '\n');	// szukamy nowego wiersza
		if (tutaj)
		{
			*tutaj = '\0';			// zamieniamy znak nowego wiersza na pusty
		}
		else
		{
			while(getchar() != '\n')
			{
				continue;
			}
		}
	}
	return wynik;
}