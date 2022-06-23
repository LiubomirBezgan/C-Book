/* wartosc Twojego ciezaru w zlocie */
// v1.0
#include <stdio.h>

int main(void)
	{
		float ciezar;
		float wartosc;

		printf("Czy jestes wart tyle, co Twoj ciezar w zlocie?\n");
		printf("Sprawdzmy.\n");
		printf("Podaj swoj ciezar w kilogramach: ");

		scanf("%f", &ciezar);

		wartosc = 4250.0 * ciezar * 32.151;

		printf("Twoj ciezar w zlocie jest wart %.2f zl.\n", wartosc);
		printf("Z pewnoscia jestes tyle wart! W razie spadku cen zlota\n");
		printf("jedz wiecej, aby utrzymac swoja wartosc.\n");
		getchar();
		getchar();
		return 0;
	}