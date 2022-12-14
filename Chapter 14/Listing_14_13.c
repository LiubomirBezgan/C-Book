//  przekazywanie tablicy struktur do funkcji - Listing_14_13.c
//  v1.0
#include <stdio.h>
#define FUNDDL 50
#define N 2
struct fundusze {
	char bank[FUNDDL];
	double bankfund;
	char oszcz[FUNDDL];
	double oszczfund;
};
double suma(const struct fundusze pieniadze[], int n);

int main (void)
{
	struct fundusze kowaliski[N] = {
		{
			"Bank Czosnkowo-Melonowy",
			2024.72,
			"Kasa Oszczednosciowo-Pozyczkowa \"Debet\"",
			8237.11
		},
		{
			"Bank \"Uczciwy Jan\"",
			1834.28,
			"Kasa oszczednosciowa \"Chomik\"",
			2903.89
		}
	};
	printf("Kowalscy posiadaja w sumie %.2f zl.\n", suma(kowaliski, N));
	return 0;
}

double suma(const struct fundusze pieniadze[], int n)
{
	double kwota;
	int i;
	for (i = 0, kwota = 0; i < n; i++)
	{
		kwota += pieniadze[i].bankfund + pieniadze[i].oszczfund;
	}
	return (kwota);
}