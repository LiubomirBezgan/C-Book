//  spis wielu ksiazek - Listing_14_2.c
//  v1.0
#include <stdio.h>
#include <string.h>
char * wczytaj (char * z, int ile);
#define MAXTYT 40				
#define MAXAUT 40
#define MAXKS 100						// maksymalna liczba ksiazek
struct ksiazka {						// definuje szablon ksiazka
	char tytul[MAXTYT];
	char autor[MAXAUT];
	float wartosc;
};

int main(void)
{
	struct ksiazka bibl[MAXKS]; 			// tablica struktur typu ksiazka
	int licznik = 0;
	int index;
	printf("Podaj tytul ksiazki.\n");
	printf("Aby zakonczyc, nacisnij [enter] na poczatku wiersza.\n");
	while (licznik < MAXKS
		&& wczytaj(bibl[licznik].tytul, MAXTYT) != NULL
		&& bibl[licznik].tytul[0] != '\0')
	{
		printf("Teraz podaj autora.\n");
		wczytaj(bibl[licznik].autor, MAXAUT);
		printf("Teraz podaj wartosc.\n");
		scanf("%f", &bibl[licznik++].wartosc);
		while (getchar() != '\n')
		{
			continue;
		}
		if (licznik < MAXKS)
		{
			printf("Podaj kolejny tytul.\n");
		}
	}
	if (licznik > 0)
	{
		printf("Oto lista Twoich ksiasek:\n");
		for (index = 0; index < licznik; index++)
		{
			printf("%s, autor: %s, cena: %.2f zl\n", bibl[index].tytul, bibl[index].autor, bibl[index].wartosc);
		}
	}
	else
	{
		printf("Zadnych ksiasek? Szkoda\n");
	}		
	return 0;
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