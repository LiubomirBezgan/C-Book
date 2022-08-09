// Program wyswietla liczbe powtorzen ciagu "ot" - Exercise5Chapter7.c
// v1.0
#include <stdio.h>

int main(void)
{
	char poprzedni = 0, aktualny;
	int licznik = 0;
    
    puts("Program wyswietla liczbe powtorzen ciagu \"ot\".");
   	puts ("Wpisz tekst ('#' konczy proces pobierania):");
	while ((aktualny = getchar()) != '#')
	{
		if (aktualny == 't' && poprzedni == 'o')
			licznik++;
		poprzedni = aktualny;
	}
	printf("Liczba powtorzen ciagu \"ot\" wynosi %d.\n", licznik);
	
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;

	return 0;
}