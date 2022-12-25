//  zapisuje zawartosc struktury w pliku - Exercise7Chapter14.c
//  v1.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * wczytaj (char * z, int ile);
#define MAXTYT 40				
#define MAXAUT 40
#define MAXKS 10						// maksymalna liczba ksiazek
struct ksiazka {						// definuje szablon ksiazka
	char tytul[MAXTYT];
	char autor[MAXAUT];
	float wartosc;
};

int main(void)
{
	struct ksiazka bibl[MAXKS]; 			// tablica struktur typu ksiazka
	int licznik = 0;
	int index, licznikp;
	FILE * pksiazki;
	int rozmiar = sizeof (struct ksiazka);

	if ((pksiazki = fopen("ksiazki.dat", "a+b")) == NULL)
	{
		fputs("Nie moge otworzyc pliku ksiazki.dat\n", stderr);
		exit(1);
	}
	rewind(pksiazki);
	while (licznik < MAXKS && 1 == fread(&bibl[licznik], rozmiar, 1, pksiazki))
	{
		if (0 == licznik)
		{
			puts("Biezaca zawartosc pliku ksiazki.dat:");
		}
		printf("%s autorstwa %s: %.2f zl\n", bibl[licznik].tytul, bibl[licznik].autor, bibl[licznik].wartosc);
		licznik++;
	}
	licznikp = licznik;
	if (licznik == MAXKS)
	{
		fputs("Plik ksiazki.dat jest pelny.", stderr);
		exit(2);
	}
	puts("Podaj nowe tytuly ksiazek.");
	puts("Aby zakonczyc, nacisnij [enter] na poczatku wiersza.");
	while (licznik < MAXKS
		&& wczytaj(bibl[licznik].tytul, MAXTYT) != NULL
		&& bibl[licznik].tytul[0] != '\0')
	{
		puts("Teraz podaj autora.");
		wczytaj(bibl[licznik].autor, MAXAUT);
		puts("Teraz podaj wartosc.");
		scanf("%f", &bibl[licznik++].wartosc);
		while (getchar() != '\n')
		{
			continue;
		}
		if (licznik < MAXKS)
		{
			printf("Podaj nastepny tytul.\n");
		}
	}
	if (licznik > 0)
	{
		puts("Oto lista Twoich ksiasek:");
		for (index = 0; index < licznik; index++)
		{
			printf("%s, autor: %s, cena: %.2f zl\n", bibl[index].tytul, bibl[index].autor, bibl[index].wartosc);
		}
		fwrite(&bibl[licznikp], rozmiar, licznik - licznikp, pksiazki);
	}
	else
	{
		puts("Zadnych ksiasek? Szkoda");
	}
	puts("Koniec.");		
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