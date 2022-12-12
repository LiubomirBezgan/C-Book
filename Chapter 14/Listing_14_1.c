//  spis jednej ksiazki - Listing_14_1.c
//  v1.0
#include <stdio.h>
#include <string.h>
char * wczytaj (char * z, int ile);
#define MAXTYT 41					// maksymalna dlugosc tytulu + 1
#define MAXAUT 31					// maksymalna dlugosc nazwiska autora + 1
struct ksiazka {					// szablon struktury o nazwie "ksiazka"
	char tytul[MAXTYT];
	char autor[MAXAUT];
	float wartosc;					// koniec szablonu struktury
};

int main(void)
{
	struct ksiazka bibl; 			// deklaracja bibl jako zmiennej typu ksiazka
	printf("Podaj tytul ksiazki.\n");
	wczytaj(bibl.tytul, MAXTYT);	//dostep do skladnika "tytul"
	printf("Teraz podaj autora.\n");
	wczytaj(bibl.autor, MAXAUT);
	printf("Teraz podaj wartosc.\n");
	scanf("%f", &bibl.wartosc);
	printf("%s, autor: %s, cena: %.2f zl\n", bibl.tytul, bibl.autor, bibl.wartosc);
	printf("%s: \"%s\" (%.2f zl)\n", bibl.autor, bibl.tytul, bibl.wartosc);		
	printf("Gotowe.\n");	
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