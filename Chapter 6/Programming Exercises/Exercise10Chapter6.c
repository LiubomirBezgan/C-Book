// Suma kwadratow - Exercise10Chapter6.c
// v1.0
#include <stdio.h>
long sumkw(int a, int b);

int main(void)
{
	int a, b;

	printf("Podaj dolna i gorna granice przedzialu liczb calkowitych: ");
	scanf("%d %d", &a, &b);
	
	while (a < b)
	{
		printf("Suma kwadratow od %ld do %ld wynosi %ld\n", (long) a * a, (long) b * b, sumkw(a, b));
		printf("\nPodaj nastepny przedzial: ");
		scanf("%d %d", &a, &b);
	}

	puts("\nKoniec");
	getchar();
	getchar();
	return 0;
}

long sumkw(int a, int b)
{
	int j;
	long out = 0;
	for (j = 0; j <= b - a; j++)
		out += (a + j) * (a + j);
	return out;
}