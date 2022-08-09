// Program zamienia '.' na '!', a '!' na '!!', korzystajac z switch - Exercise5Chapter7.c
// v1.0
#include <stdio.h>

int main(void)
{
	char ch;
	int licznik_kropka = 0, licznik_wykrzyknik = 0;
    
    puts("Program zamienia '.' na '!', a '!' na '!!'; \nnastepnie podaje liczbe zmian kazdego typu.");
   	puts ("Wpisz tekst ('#' konczy proces pobierania):");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case '.' : {
			    putchar('!');
			    licznik_kropka++;
			    break;
			}
			case '!' : {
			    putchar('!');
			    putchar(ch);
			    licznik_wykrzyknik++;
			    break;
			    }
			default : putchar(ch);
		}
	}
	printf("Liczba zmian '.' -> '!'  wynosi %d\n", licznik_kropka);
	printf("Liczba zmian '!' -> '!!' wynosi %d\n", licznik_wykrzyknik);

	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}