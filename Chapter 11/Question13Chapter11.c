//  porownanie odpowiedzi - Question13Chapter11.c
//  v1.0
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ODPOWIEDZ "SKALEN.Gaming"
#define MAX 40
char * wczytaj(char *z, int ile);
int porownaj_hasla(const char * haslo, char * odpowiedz);
void toggle(char * ch);

int main(void)
{
	char proba[MAX];
	puts("Jak sie nazywa najlepsza druzyna e-sportowa?");
	wczytaj(proba, MAX);	
	while (!(porownaj_hasla(ODPOWIEDZ, proba)))
	{
		puts("Niestety to nie jest dobra odpowiedz.\n\nSporobuj jeszcze raz.");
		wczytaj(proba, MAX);	
	}
	puts("Tak jest!");
	return 0;
}

char * wczytaj(char *z, int ile)
{
	char * wynik;
	int i = 0;
	wynik = fgets(z, ile, stdin);
	if (wynik)							// wynik rozny od NULL
	{
		while (z[i] != '\n' && z[i] != '\0')
		{
			i++;
		}
		if (z[i] == '\n')
		{
			z[i] = '\0'; 				// znak nowego wiersza -> znak pusty
		}
		else							// z[i] = '\0'
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return wynik;
}

int porownaj_hasla(const char * haslo, char * odpowiedz)		// zwraca 1, jesli lancuchy sa identyczne (niezaleznie od wielkosci liter); zwraca 0, jesli lancuchy sa rozne 
{
	int wynik = 1;
	while(*haslo && wynik)
	{
		if (*haslo != *odpowiedz)
		{
			toggle(odpowiedz);
			if (*haslo != *odpowiedz)
			{
				wynik = 0;
			}
		}
		haslo++;
		odpowiedz++;
	}
	return wynik;
}

void toggle(char * ch)											// przełącza wielkosc litery, ktora przechowuje sie pod adresem ch
{
	if (islower(*ch))
	{
		*ch = toupper(*ch);	
	}
	else if (isupper(*ch))
	{
		*ch = tolower(*ch);
	}
}