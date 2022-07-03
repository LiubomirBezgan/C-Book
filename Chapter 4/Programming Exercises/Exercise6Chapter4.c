// godnosc i dlugosc - Exercise6Chapter4.c
// v1.0
#include <stdio.h>
#include <string.h>

int main(void)
{
	char imie[20], nazwisko[40];

	puts("Prosze podac swoje imie i nazwisko, rozdzielajac wartosci spacja:");
	scanf("%s %s", imie, nazwisko);
	printf("%s %s\n", imie, nazwisko);
	printf("%*d %*d\n", strlen(imie), strlen(imie), strlen(nazwisko), strlen(nazwisko));

	printf("%s %s\n", imie, nazwisko);
	printf("%-*d %-*d\n", strlen(imie), strlen(imie), strlen(nazwisko), strlen(nazwisko));

	getchar();
	getchar();
	return 0;
}