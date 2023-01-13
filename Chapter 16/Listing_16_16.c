// przyklad uzycia atexit()
#include <stdio.h>
#include <stdlib.h>
void koniec(void);
void wpadka(void);

int main(void)
{
	int n;
	atexit(koniec);
	puts("Podaj liczbe calkowita:");
	if (1 != scanf("%d", &n))
	{
		puts("To nie jest liczba calkowita!");
		atexit(wpadka);
		exit(EXIT_FAILURE);
	}
	printf("%d jest %s.\n", n, (0 == n % 2) ? "parzysta" : "nieparzysta");
	return 0;
}

void koniec(void)
{
	puts("Na tym konczymy kolejny wspanialy program firmy");
	puts("Hustawka Software!");
}

void wpadka(void)
{
	puts("Firma Hustawka Software sklada szczere kondolencje");
	puts("z powodu awarii programu.");
}