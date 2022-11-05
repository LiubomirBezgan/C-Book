// Question12Chapter11.c
// v2.0
#include <stdio.h>
#include <string.h>
#define DLUGOSC 81
char * gdzie_spacja(const char *z);
char * wczytaj(char *z, int ile);
//char * lansp(char * lancuch);
//char * lansp(const char * lancuch);

int main(void)
{
	char slowa[DLUGOSC];

	puts("Prosze wprowadzic lancuch (pusty wiersz zakonczy program):");
	
	while (wczytaj(slowa, DLUGOSC) != NULL && slowa[0] != '\0')
	{
		puts(gdzie_spacja(slowa));
	}
	puts("Gotowe.");
	return 0;
}

char * gdzie_spacja(const char *z)
{
	char * wynik;
	wynik = strchr(z, ' ');
	return wynik;
}

char * wczytaj(char *z, int ile)
{
	char * wynik;
	char * koniec;
	wynik = fgets(z, ile, stdin);
	if (wynik)							// wynik rozny od NULL
	{
		if ((koniec = strchr(wynik, '\n')))
		{
			*koniec = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return wynik;
}

/*char * lansp(char * lancuch)
{
	while (*lancuch != ' ' && *lancuch != '\0')
	{
		lancuch++;
	}
	if (*lancuch == '\0')
	{
		return NULL;				// NULL jest wskaznikiem zerowym
	}
	else
	{
		return lancuch;
	}
}*/

/*char * lansp(const char * lancuch)
{
	while (*lancuch != ' ' && *lancuch != '\0')
	{
		lancuch++;
	}
	if (*lancuch == '\0')
	{
		return NULL;				// NULL jest wskaznikiem zerowym
	}
	else
	{
		return (char *) lancuch;	// odrzucenie const
	}
}*/