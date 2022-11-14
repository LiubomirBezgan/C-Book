// r_test1.c - sprawdza funkcje rand1() i srand1() - Listing_12_10
// nalezy kompilowac razem z plikiem s_i_r.c
#include <stdio.h>
#include <mylib.h>
extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
	int liczba;
	unsigned ziarno;
	puts("Podaj wartosc ziarna:");
	while (scanf("%u", &ziarno) == 1)
	{
		srand1(ziarno);					// reset ziarna
		for (liczba = 0; liczba < 5; liczba++)
		{
			printf("%hd\n", rand1());
		}
		puts("Podaj nastepna wartosc ziarna (k to koniec):\n");
	}

	koniec('#');
	return 0;
}