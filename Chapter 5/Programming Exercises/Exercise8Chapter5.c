// Modulo - Exercise8Chapter5.c
// v1.0
#include <stdio.h>

int main(void)
{
	int dzielnik, dzielna;

	puts("Program obliczajacy reszte z dzielenia.");
	printf("Podaj dzielnik (liczba calkowita): ");
	scanf("%d", &dzielnik);
	printf("Podaj dzielna (<=0, aby zakonczyc): ");
	scanf("%d", &dzielna);
	

	while (dzielna > 0)
	{
		printf("%d %% %d wynosi %d\n\n", dzielna, dzielnik, dzielna % dzielnik);
		printf("Podaj dzielna (<=0, aby zakonczyc): ");
		scanf("%d", &dzielna);
	}

	puts("\nKoniec");

	getchar();
	getchar();
	return 0;
}