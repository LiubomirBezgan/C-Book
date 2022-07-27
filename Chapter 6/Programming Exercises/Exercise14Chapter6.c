// opis - Exercise14Chapter6.c
// v1.0
#include <stdio.h>

int main(void)
{
	int i;
	double array1[8], array2[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	puts("Program wyswietla skumulowane sumy wprowadzonych liczb.");
	puts("Podaj 8 liczb.");

	printf("1. liczba: ");
	scanf("%lf", &array1[0]);
	array2[0] = array1[0];

	for (i=1; i < 8; i++)
	{
		printf("%d. liczba: ", i+1);
		scanf("%lf", &array1[i]);
		array2[i] = array1[i] + array2[i-1];

	}
	
	printf("\nIndex:           ");
	for (i=0; i < 8; i++)
	{
		printf(" %15d", i+1);
	}

	printf("\nTablica wartosci:");
	for (i=0; i < 8; i++)
	{
		printf(" %15lg", array1[i]);
	}

	printf("\nSumy skumulowane:");
	for (i=0; i < 8; i++)
	{
		printf(" %15lg", array2[i]);
	}

	getchar();
	getchar();
	return 0;
}