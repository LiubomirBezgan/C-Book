// talkback - Listing_4_1.c
#include <stdio.h>
#include <string.h>
#define GEST0SC 62.4

int main(void)
{
	float waga, objetosc;
	int rozmiar, litery;
	char nazwa[39];

	printf("Witam! Podaj swoje imie.\n");
	scanf("%s", nazwa);
	printf("%s, ile funtow wazysz?\n", nazwa);
	scanf("%f", &waga);
	rozmiar = sizeof nazwa;
	litery = strlen(nazwa);
	objetosc = waga / GEST0SC;
	printf("Zatem, %s, twoja ojetosc wynosi %2.2f stopy szescienne.\n", nazwa, objetosc);
	printf("Ponadto Twoje imie zawiera %d liter(y),\n", litery);
	printf("a na jego przechowanie przeznaczylismy %d bajtow.\n", rozmiar);

	getchar();
	return 0;
}