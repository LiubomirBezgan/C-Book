//  kopiowanie pliku (tryb tekstowy) i zmiana wszystkich liter na wielkie- Exercise3Chapter13.c
//  v1.0
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>				// prototyp funkcji exit()
#define MAX_LENGTH 255
int title_comp(char * first, char * second, unsigned int max_length);

int main(void)
{
	FILE *wp_zro, *wp_doc;			// wskazniki plikowe
	char ch;
	char nazwa_zro[MAX_LENGTH], nazwa_doc[MAX_LENGTH];

	puts("Program kopiuje plik (tryb tekstowy) i zmienia wszystkie litery na wielkie.");
	
	puts("Podaj nazwe pliku zrodlowego:");
	scanf("%s", nazwa_zro);	
	if ( (wp_zro = fopen(nazwa_zro, "r")) == NULL)
	{
		printf("Nie mozna otworzyc %s do odczytu\n", nazwa_zro);
		exit(EXIT_FAILURE);
	}

	puts("Podaj nazwe pliku docelowego:");
	scanf("%s", nazwa_doc);
	while (!title_comp(nazwa_zro, nazwa_doc, MAX_LENGTH))
	{
		puts("Nazwa pliku docelowego nie moze byc taka sama, jak nazwa pliku zrodlowego.");
		puts("Podaj nazwe pliku docelowego:");
		scanf("%s", nazwa_doc);
	}
	if ( (wp_doc = fopen(nazwa_doc, "w")) == NULL)
	{
		printf("Nie mozna utworzyc %s do zapisu\n", nazwa_doc);
		exit(EXIT_FAILURE);
	}

	while ( EOF != (ch = getc(wp_zro)))
	{
		putc( toupper(ch), wp_doc);
	}


	fclose(wp_zro);
	fclose(wp_doc);
	return 0;
}

int title_comp(char * first, char * second, unsigned int max_length)
{
	char array1[max_length], array2[max_length];

	strncpy(array1, first, max_length);
	strncpy(array2, second, max_length);

	int i = 0;
	while ('\0' != array1[i])
	{
		array1[i] = tolower(array1[i]);
		i++;
	}

	i = 0;
	while ('\0' != array2[i])
	{
		array2[i] = tolower(array2[i]);
		i++;
	}

	if (0 == strcmp(array1, array2))
	{
		return 0;
	}
	return 1;
}