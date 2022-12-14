//  przekazuje i zwraca struktury - Listing_14_9.c
//  v1.0
#include <stdio.h>
#include <string.h>
#define DL 30

struct daneos {
	char imie[DL];
	char nazw[DL];
	int litery;
};
struct daneos pobierz(void);
struct daneos oblicz(struct daneos);
void pokaz(struct daneos);
char * wczytaj (char * z, int ile);

int main(void)
{
	struct daneos osoba;
	osoba = pobierz();
	osoba = oblicz(osoba);
	pokaz(osoba);
	return 0;
}

struct daneos pobierz(void)
{
	struct daneos temp;
	printf("Podaj swoje imie.\n");
	wczytaj(temp.imie, DL);
	printf("Podaj swoje nazwisko.\n");
	wczytaj(temp.nazw, DL);
	return temp;
}

struct daneos oblicz(struct daneos info)
{
	info.litery = strlen(info.imie) + strlen(info.nazw);
	return info;
}

void pokaz(struct daneos info)
{
	printf("%s %s, Twoje imie i nazwisko skladaja sie z %d liter.\n", info.imie, info.nazw, info.litery);
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