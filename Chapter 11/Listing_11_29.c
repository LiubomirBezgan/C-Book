//  pobiera lancuchy i je porzadkuje - Listing_11_29.c
//  v1.1
#include <stdio.h>
#include <string.h>
#define ROZMIAR 81							// granica dlugosci lancucha, wlacznie z \0
#define GRAN 20								// maksymalna liczba wierszy
void srtlan(char *lancuchy[], int num);		// funkcja sortujaca lancuchy
char * wczytaj(char *z, int ile);

int main(void)
{
	char dane[GRAN][ROZMIAR];
	char *wsklan[GRAN];						// tablica zmiennych wskaznikowych
	int licz = 0;
	int k;
	printf("Podaj maksymalnie %d wierszy, a ja je uporzadkuje.\n", GRAN);
	puts("Aby zakonczyc, wcisnij ENTER na poczatku wiersza.");
	while (licz < GRAN && wczytaj(dane[licz], ROZMIAR) != NULL && dane[licz][0] != '\0')
	{
		wsklan[licz] = dane[licz];			// ustawienie wskaznikow na lancuchy
		licz++;
	}
	srtlan(wsklan, licz);
	puts("\nOto uporzadkowana lista:");
	for (k = 0; k < licz; k++)
	{
		puts(wsklan[k]);
	}
	return 0;
}

void srtlan(char *lancuchy[], int num)
{
	char *temp;
	int dol, szuk;
	for (dol = 0; dol < num - 1; dol++)
	{
		for (szuk = dol + 1; szuk < num; szuk++)
		{
			if (strcmp(lancuchy[dol], lancuchy[szuk]) > 0) 
			{
				temp = lancuchy[dol];
				lancuchy[dol] = lancuchy[szuk];
				lancuchy[szuk] = temp;
			}
		}
	}
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