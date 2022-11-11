//  dzialania na tablicy lancuchow - Exercise11Chapter11.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/

#define ROZMIAR 81
#define WIERSZE 10
#define PIERWSZA_OPCJA "a) wyswietlenie pierwotnej listy lancuchow"
#define DRUGA_OPCJA "b) wyswietlenie lancuchow w porzadku ASCII"
#define TRZECIA_OPCJA "c) wyswietlenie lancuchow wedlug dlugosci"
#define CZWARTA_OPCJA "d) wyswietlenie lancuchow wedlug dlugosci 1. slowa"
#define PIATA_OPCJA "e) koniec"
#include <stdio.h>
#include <mylib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
unsigned int wczytaj_lan_do_tab(char (*lista)[ROZMIAR], int wiersze);
void wyswietl_liste(char (*lista)[ROZMIAR], int wiersze);
void wyswietl_liste_ASCII(char *lista[], int wiersze);
void wyswietl_liste_dlugosc(char *lista[], int wiersze);
void wyswietl_liste_dlugosc_slowa(char *lista[], int wiersze);
int dlugosc_1_slowa(char * lancuch, int dlugosc_lan);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	unsigned int licznik;
	int opcja;
	int i;
	char lista_lan[WIERSZE][ROZMIAR];
	char *wsklan[WIERSZE];							// tablica zmiennych wskaznikowych
	
/*  Description ---------------------------------------------------------------*/
	puts("Program wykonuje dzialania na tablicy lancuchow (max. 10 lancuchow).\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Wprowadz lancuchy (zasymuluj EOF, aby zakonczyc):");
	licznik = wczytaj_lan_do_tab(lista_lan, WIERSZE);
	printf("Pobrano %u lancuchow.\n\n", licznik);
	
	for (i = 0; i < licznik; i++)			//	ustaw wskazniki na lancuchy
	{
		wsklan[i] = lista_lan[i];
	}
	
	puts("Wybierz jedna z ponizszych opcji");
	while ((opcja = menu_5(PIERWSZA_OPCJA, DRUGA_OPCJA, TRZECIA_OPCJA, CZWARTA_OPCJA, PIATA_OPCJA))!= 5)
	{
		switch (opcja) 
		{
			case 1 :	puts("Pierwotna lista lancuchow:");
						ciag_znakow('-', ROZMIAR);
						wyswietl_liste(lista_lan, licznik);
						ciag_znakow('-', ROZMIAR);
						putchar('\n');
						break;
			case 2 :	puts("Lista lancuchow w porzadku ASCII:");
						ciag_znakow('-', ROZMIAR);
						wyswietl_liste_ASCII(wsklan, licznik);
						ciag_znakow('-', ROZMIAR);
						putchar('\n');
						break;
			case 3 :	puts("Lista lancuchow wedlug dlugosci:");
						ciag_znakow('-', ROZMIAR);
						wyswietl_liste_dlugosc(wsklan, licznik);
						ciag_znakow('-', ROZMIAR);
						putchar('\n');
						break;
			default :	puts("Lista lancuchow wedlug dlugosci 1. slowa:");
						ciag_znakow('-', ROZMIAR);
						wyswietl_liste_dlugosc_slowa(wsklan, licznik);
						ciag_znakow('-', ROZMIAR);
						putchar('\n');
						break;
		}
		while (getchar() != '\n')
		{
			continue;
		}
		puts("Wybierz kolejna opcje");
	}
	puts("Do widzenia!");
/*  Ending --------------------------------------------------------------------*/
	koniec('#');
	return 0;
}

unsigned int wczytaj_lan_do_tab(char (*lista)[ROZMIAR], int wiersze)
{
	unsigned int licznikY;
	unsigned int licznikX;
	char ch;
	bool koniec_pobierania = false;
	for (licznikY = 0; licznikY < wiersze; licznikY++)
	{
		for (licznikX = 0; licznikX < ROZMIAR; licznikX++)
		{
			if ((ch = getchar()) == EOF)	
			{
				ch = '\0';
				koniec_pobierania = true;
			}
			if (ch == '\n')
			{
				ch = '\0';	
			}
			*(*(lista + licznikY) + licznikX) = ch;
			if (ch == '\0')
			{
				break;
			}
			if (koniec_pobierania)
			{
				break;
			}
		}
		if (koniec_pobierania)
		{
			if (*(*(lista + licznikY)) != '\0')
			{
				    licznikY++;
			}
			break;
		}
	}
	return licznikY;
}


void wyswietl_liste(char (*lista)[ROZMIAR], int wiersze)
{
	int j;
	for (j = 0; j < wiersze; j++)
	{
		puts(lista[j]);
	}
}

void wyswietl_liste_ASCII(char *lista[], int wiersze)
{
	char *temp;
	int dol, szuk;
	for (dol = 0; dol < wiersze - 1; dol++)
	{
		for (szuk = dol + 1; szuk < wiersze; szuk++)
		{
			if (strcmp(lista[dol], lista[szuk]) > 0)
			{
				temp = lista[dol];
				lista[dol] = lista[szuk];
				lista[szuk] = temp;
			}
		}
	}
	for (dol = 0; dol < wiersze; dol++)
	{
		puts(lista[dol]);
	}
}

void wyswietl_liste_dlugosc(char *lista[], int wiersze)
{
	char *temp;
	int dol, szuk;
	for (dol = 0; dol < wiersze - 1; dol++)
	{
		for (szuk = dol + 1; szuk < wiersze; szuk++)
		{
			if (strlen(lista[dol]) > strlen(lista[szuk]))
			{
				temp = lista[dol];
				lista[dol] = lista[szuk];
				lista[szuk] = temp;
			}
		}
	}
	for (dol = 0; dol < wiersze; dol++)
	{
		puts(lista[dol]);
	}
}

void wyswietl_liste_dlugosc_slowa(char *lista[], int wiersze)
{
	char *temp;
	int dol, szuk;
	for (dol = 0; dol < wiersze - 1; dol++)
	{
		for (szuk = dol + 1; szuk < wiersze; szuk++)
		{
			if (dlugosc_1_slowa(lista[dol], ROZMIAR) > dlugosc_1_slowa(lista[szuk], ROZMIAR))
			{
				temp = lista[dol];
				lista[dol] = lista[szuk];
				lista[szuk] = temp;
			}
		}
	}
	for (dol = 0; dol < wiersze; dol++)
	{
		puts(lista[dol]);
	}
}

int dlugosc_1_slowa(char * lancuch, int dlugosc_lan)
{
	bool w_slowie = false;
	int i = 0;
	int dlugosc_slowa = 0;
	while ((*(lancuch + i) != '\0') && (i < dlugosc_lan))
	{
		if (w_slowie)				// jesli jestesmy w slowie
		{
			if (!isspace(*(lancuch + i)))
			{
				dlugosc_slowa++;
			}
			else
			{
				break;
			}

		}
		else						// jesli nie jestesmy w slowie
		{
			if (!isspace(*(lancuch + i)))
			{
				w_slowie = true;
				dlugosc_slowa++;
			}
		}
		i++;
	}
	return dlugosc_slowa;
}