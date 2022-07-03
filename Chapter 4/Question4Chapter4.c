// "Pech" - Question4Chapter4.c
// v1.0
#include <stdio.h>
#define X 10
#define P "pech"

int main(void)
{
	int wiek, xp;
	char imie[40];

	printf("Podaj swoje imie.\n");
	scanf("%s", imie);
	printf("W porzadku, %s, ile masz lat?\n", imie);
	scanf("%d", &wiek);
	xp = wiek + X;
	printf("A to %s! Musisz miec co najmniej %d lat.\n", P, xp);

	getchar();
	getchar();
	return 0;
}