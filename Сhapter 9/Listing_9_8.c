//  wyswietla liczbe calkowita w postaci dwojkowej - Listing_9_8.c
//  v1.0
#include <stdio.h>
void do_binar(unsigned long n);

int main(void)
{
	unsigned long liczba;
	puts("Podaj liczbe calkowita (q konczy program):");
	while (1 == scanf("%lu", &liczba))
	{
		printf("Odpowiednik dwojkowy: ");
		do_binar(liczba);
		putchar('\n');
		puts("Podaj liczbe calkowita (q konczy program):");
	}
	puts("Gotowe.");

	return 0;
}

void do_binar(unsigned long n)			// funkcja rekurencyjna
{
	int r;
	r = n % 2;
	if (n >= 2)
	{
		do_binar(n / 2);
	}
	putchar(r == 0 ? '0' : '1');
	return;
}