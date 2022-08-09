// Program zamienia '.' na '!', a '!' na '!!' - Exercise4Chapter7.c
// v1.0
#include <stdio.h>

int main(void)
{
	char ch;
	int licznik_kropka = 0, licznik_wykrzyknik = 0;
    
    puts("Program zamienia '.' na '!', a '!' na '!!'; \nnastepnie podaje liczbe zmian kazdego typu.");
   	puts("Wpisz tekst ('#' konczy proces liczenia):");
	while ((ch = getchar()) != '#')
	{
		if (ch == '.') {
			putchar('!');
			licznik_kropka++;
			}
		else if (ch == '!') {
			    putchar('!');
			    putchar(ch);
			    licznik_wykrzyknik++;
			}
		else
			putchar(ch);
	}
	printf("Liczba zmian '.' -> '!'  wynosi %d\n", licznik_kropka);
	printf("Liczba zmian '!' -> '!!' wynosi %d\n", licznik_wykrzyknik);

	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}