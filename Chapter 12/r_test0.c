// r_test0.c - sprawdza funkcje rand0() - Listing_12_8
// nalezy kompilowac razem z plikiem rand0.c
#include <stdio.h>
#include <mylib.h>
extern int rand0(void);

int main(void)
{
	int liczba;
	for (liczba = 0; liczba < 5; liczba++)
	{
		printf("%hd\n", rand0());
	}

	koniec('#');
	return 0;
}