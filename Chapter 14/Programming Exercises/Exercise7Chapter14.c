//  zapisuje zawartosc struktury w pliku z mozliwoscia modyfikacji zawartosci - Exercise7Chapter14.c
//  v2.0
#include <mylib.h>
char * wczytaj (char * z, int ile);
#define MAXTYT 40				
#define MAXAUT 40
#define MAXKS 10							// maksymalna liczba ksiazek
struct ksiazka {							// definuje szablon ksiazka
	char tytul[MAXTYT];
	char autor[MAXAUT];
	float wartosc;
};

void trzy_opcje_ksiazka(struct ksiazka * wsk_ksiazka);
void nastepna_pozycja (void);
void modyfikacja_rekordu(struct ksiazka * wsk_ksiazka);
void usuniecie_rekordu(struct ksiazka * wsk_ksiazka);

int main(void)
{
	struct ksiazka bibl[MAXKS]; 			// tablica struktur typu ksiazka
	int licznik = 0;
	int index;
	FILE * pksiazki;
	int rozmiar = sizeof (struct ksiazka);

	if ((pksiazki = fopen("ksiazki.dat", "r+b")) == NULL)
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
		trzy_opcje_ksiazka(&bibl[licznik]);
		licznik++;
	}
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
		rewind(pksiazki);
		puts("Oto lista Twoich ksiasek:");
		for (index = 0; index < licznik; index++)
		{
			if ('\0' != bibl[index].tytul[0])
			{
				printf("%s, autor: %s, cena: %.2f zl\n", bibl[index].tytul, bibl[index].autor, bibl[index].wartosc);
				fwrite(&bibl[index], rozmiar, 1, pksiazki);
			}
		}
	}
	else
	{
		puts("Zadnych ksiasek? Szkoda");
	}
	fclose(pksiazki);
	puts("Koniec.");		
	return 0;
}

void trzy_opcje_ksiazka(struct ksiazka * wsk_ksiazka)
{
	char ch;
	
	puts("Wybierz jedna z ponizszych opcji:");
	puts("n) nastepna pozycja    m) modyfikacja pozycji    u) usuniecie pozycji");
	printf("%s", "Podaj litere: ");
	ch = getchar();
	while(getchar() != '\n')
	{
		continue;
	}

	while ( ch != 'n' && ch != 'm' && ch != 'u' )
	{
		printf("%s", "Podaj litere n, m albo u: ");
		ch = getchar();
		while(getchar() != '\n')
		{
			continue;
		}
	}

	switch (ch)
	{
	case 'n' :
		nastepna_pozycja();
		break;
	case 'm' :
		modyfikacja_rekordu(wsk_ksiazka);
		break;
	default :
		usuniecie_rekordu(wsk_ksiazka);
	}
}

void nastepna_pozycja (void)
{
	;
}

void modyfikacja_rekordu(struct ksiazka * wsk_ksiazka)
{
	puts("Podaj nowy tytul ksiazki.");
	wczytaj(wsk_ksiazka->tytul, MAXTYT);
	puts("Teraz podaj autora.");
	wczytaj(wsk_ksiazka->autor, MAXAUT);
	puts("Teraz podaj wartosc.");
	scanf("%f", &(wsk_ksiazka->wartosc) );
	while (getchar() != '\n')
	{
		continue;
	}
}


void usuniecie_rekordu(struct ksiazka * wsk_ksiazka)
{
	wsk_ksiazka->tytul[0] = '\0';
}
