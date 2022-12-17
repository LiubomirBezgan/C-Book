//  uzycie wartosci wyliczeniowych - Listing_14_15.c
//  v1.0
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define DLUGOSC 30
char * wczytaj (char * z, int ile);
enum widmo {czerwony, pomaranczowy, zolty, zielony, niebieski, fioletowy};
const char * kolory[] = {"czerwony", "pomaranczowy", "zolty", "zielony", "niebieski", "fioletowy"};


int main(void)
{
	char wybor[DLUGOSC];
	enum widmo kolor;
	bool kolor_znaleziony = false;
	puts("Podaj kolor (pusta linia - koniec):");
	while ( wczytaj(wybor, DLUGOSC) != NULL && wybor[0] != '\0')
	{
		for (kolor = czerwony; kolor <= fioletowy; kolor++)
		{
			if (0 == strcmp(wybor, kolory[kolor]))
			{
				kolor_znaleziony = true;
				break;
			}
		}
		if (kolor_znaleziony)
		{
			switch(kolor)
			{
			case czerwony :
				puts("Roze sa czerwone.");
				break;
			case pomaranczowy :
				puts("Maki sa pomaranczowe.");
				break;
			case zolty :
				puts("Sloneczniki sa zolte.");
				break;				
			case zielony :
				puts("Trawa jest zielona.");
				break;
			case niebieski :
				puts("Dzwonki sa niebieskie.");
				break;
			case fioletowy :
				puts("Dzwonki sa fioletowe.");
				break;			
			}
		}
		else
		{
			printf("Nie wiem nic o kolorze %s\n", wybor);
		}
		kolor_znaleziony = false;
		puts("Podaj nastepny kolor, prosze (pusta linia - koniec):");

	}
	puts("Do widzenia!");	
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