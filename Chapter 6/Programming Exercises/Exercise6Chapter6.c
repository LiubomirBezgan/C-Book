// kwadraty i szesciany - Exercise6Chapter6.c
// v1.0
#include <stdio.h>

int main(void)
{
	int f, g;
	puts("Podaj poczatkowa liczbe calkowita:");
	scanf("%d", &f);
	puts("");
	puts("Podaj koncowa liczbe calkowita:");
	scanf("%d", &g);
	puts("");
	puts(" Liczba");
	printf("%10s%13s%22s\n", "calkowita", "Kwadrat", "Szescian");
	for ( ; f <= g; f++)
		printf("%10d%13ld%22lld\n", f, (long) f*f, (long long) f*f*f);

	getchar();
	getchar();
	return 0;
}