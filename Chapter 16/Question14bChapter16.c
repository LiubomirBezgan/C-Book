#include <stdio.h>
#include <string.h>
#define ROZMIAR1 100
#define ROZMIAR2 300

int main(void)
{
	int i;
	double dane1[ROZMIAR1];
	double dane2[ROZMIAR2];

	for (i = 0; i < ROZMIAR1; i++)
	{
		dane1[i] = 1.1 + (i * 0.5);
	}

	for (i = 0; i < ROZMIAR2; i++)
	{
		dane2[i] = 2.2 + (i * 2.25);
	}

	puts("\ndane1:");
	for (i = 0; i < ROZMIAR1; i++)
	{
		printf("%9g ", dane1[i]);
		if (0 == ((i + 1) % 10 ))
		{
			putchar('\n');
		}
	}

	puts("\ndane2:");
	for (i = 0; i < ROZMIAR2; i++)
	{
		printf("%9g ", dane2[i]);
		if (0 == ((i + 1) % 10 ))
		{
			putchar('\n');
		}
	}

	memcpy(dane1, dane2 + ROZMIAR2 - ROZMIAR1, ROZMIAR1 * sizeof(double));

	puts("\ndane1:");
	for (i = 0; i < ROZMIAR1; i++)
	{
		printf("%9g ", dane1[i]);
		if (0 == ((i + 1) % 10 ))
		{
			putchar('\n');
		}
	}

	puts("\ndane2:");
	for (i = 0; i < ROZMIAR2; i++)
	{
		printf("%9g ", dane2[i]);
		if (0 == ((i + 1) % 10 ))
		{
			putchar('\n');
		}
	}
	return 0;
}