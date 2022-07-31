// Wykorzystuje operator warunkowy - Listing_7_8.c
// v1.0
#include <stdio.h>
#define POKRYCIE 18 			// liczba m kw. pokrywana przez jedna puszke

int main(void)
{
	int m_kw, puszki;

	puts("Podaj liczbe metrow kwadratowych do pomalowania:");

	while (scanf ("%d", &m_kw) == 1)
	{
		puszki = m_kw / POKRYCIE;
		puszki += ((m_kw % POKRYCIE == 0)) ? 0 : 1;
		printf("Potrzeba %d %s farby.\n", puszki, puszki == 1 ? "puszki" : "puszek");
		puts("\nPodaj kolejna wartosc (q konczy program):");
	}

	return 0;
}