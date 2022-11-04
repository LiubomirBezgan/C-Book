// Question10Chapter11.c
#include <stdio.h>
#define DLUGOSC 81
int MyStrlen(char * string);
char * wczytaj(char *z, int ile);

int main(void)
{
	char slowa[DLUGOSC];

	puts("Prosze wprowadzic lancuch (pusty wiersz zakonczy program):");
	
	while (wczytaj(slowa, DLUGOSC) != NULL && slowa[0] != '\0')
	{
		printf("%d znakow.\n", MyStrlen(slowa));
	}
	puts("Gotowe.");
	return 0;
}

int MyStrlen(char * string)
{
	int licznik = 0;
	while (*string != '\0')
	{
		licznik++;
		string++;
	}

	return licznik;
}

char * wczytaj(char *z, int ile)
{
	char * wynik;
	wynik = fgets(z, ile, stdin);
	if (wynik)							// wynik rozny od NULL
	{
		while (*z != '\n' && *z != '\0')
		{
			z++;
		}
		if (*z == '\n')
		{
			*z = '\0'; 				// znak nowego wiersza -> znak pusty
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