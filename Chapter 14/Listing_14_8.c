//  wykorzystuje wskazniki do struktury - Listing_14_8.c
//  v1.0
#include <stdio.h>
#include <string.h>
#define DL 30

struct daneos {
	char imie[DL];
	char nazw[DL];
	int litery;
};
void pobierz(struct daneos *);
void oblicz(struct daneos *);
void pokaz(const struct daneos *);
char * wczytaj (char * z, int ile);

int main(void)
{
	struct daneos osoba;
	pobierz(&osoba);
	oblicz(&osoba);
	pokaz(&osoba);
	return 0;
}

void pobierz(struct daneos * wst)
{
	printf("Podaj swoje imie.\n");
	wczytaj(wst->imie, DL);
	printf("Podaj swoje nazwisko.\n");
	wczytaj(wst->nazw, DL);	
}

void oblicz(struct daneos * wst)
{
	wst->litery = strlen(wst->imie) + strlen(wst->nazw);
}

void pokaz(const struct daneos * wst)
{
	printf("%s %s, Twoje imie i nazwisko skladaja sie z %d liter.\n", wst->imie, wst->nazw, wst->litery);
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