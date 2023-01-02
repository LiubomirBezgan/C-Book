// wyswietlanie liczb w systemie binarnym za pomoca operacji na bitach
#include <stdio.h>
#include <limits.h>			// CHAR_BIT, liczba bitow w typie char
char * do_binar(int, char *);
void pokaz_binar(const char *);

int main(void)
{
	char bin_lan[CHAR_BIT * sizeof(int) + 1];
	int liczba;
	puts("Ten program przelicza liczby calkowite na system binarny.");
	puts("Wpisanie danych nienumerycznych konczy dzialanie programu.");
	while (1 == scanf("%d", &liczba))
	{
		do_binar(liczba, bin_lan);
		printf("%d to inaczej ", liczba);
		pokaz_binar(bin_lan);
		putchar('\n');
	}
	puts("Gotowe!");
	return 0;
}

char * do_binar(int n, char * wsk)
{
	int i;
	static int liczba = CHAR_BIT * sizeof(int);
	for (i = liczba - 1; i >= 0; i--, n >>= 1)
	{
		wsk[i] = (01 & n) + '0';	// zakladamy kodowanie ASCII
	}
	wsk[liczba] = '\0';
	return wsk;
}

void pokaz_binar(const char * lan)
{
	int i = 0;
	while (lan[i])		// nie znak null
	{
		putchar(lan[i]);
		if (0 == ++i % 4 && lan[i])
		{
			putchar(' ');
		}
	}
}