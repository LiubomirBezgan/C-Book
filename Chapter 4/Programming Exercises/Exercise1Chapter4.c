// godnosc - Exercise1Chapter4.c
// v1.0
#include <stdio.h>

int main(void)
{
	char imie[20], nazwisko[40];

	puts("Prosze podac swoje imie:");
	scanf("%s", imie);
	puts("Teraz prosze podac swoje nazwisko:");
	scanf("%s", nazwisko);
	printf("Witaj, %s %s!\n", nazwisko, imie);

	getchar();
	getchar();
	return 0;
}