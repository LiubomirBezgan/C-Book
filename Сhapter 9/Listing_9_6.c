//  ilustracja rekurancji - Listing_9_6.c
//  v1.0
#include <stdio.h>
void gora_i_dol(int);
int main(void)
{
	gora_i_dol(1);
	return 0;
}

void gora_i_dol(int n)
{
	printf("Poziom: %d: adres zmiennej n: %p\n", n, &n);
	if (n < 4)
		gora_i_dol(n+1);
	printf("POZIOM: %d: adres zmiennej n: %p\n", n, &n);
}