//  Program testuje funkcje Fibonacci(n),  - Exercise11Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
void Fibonacci(unsigned long n);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	unsigned long n;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program testuje funkcje Fibonacci(n).");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Podaj numer wyrazu, do ktorego bedzie obliczany ciag Fibonacciego:");
	scanf("%lu", &n);
	printf("Ciag Fibonacciego: ");
	Fibonacci(n);	

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

void Fibonacci(unsigned long n)
{
	const int n0 = 0;
	const int n1 = 1;
	unsigned long aktualna, poprzednia, przedpoprzednia;
	unsigned int licznik;
	
	if (n > 2)
	{
		printf("%d, %d", n0, n1);
		for (przedpoprzednia = n0, poprzednia = n1, licznik = 3; licznik <= n; licznik++)
		{
			aktualna = poprzednia + przedpoprzednia;
			printf(", %lu", aktualna);
			przedpoprzednia = poprzednia;
			poprzednia = aktualna;

		}
	}
	else if (2 == n)
	{
		printf("%d, %d\n", n0, n1);
	}
	else if (1 == n)
	{
		printf("%d\n", n0);
	}
	else
	{
		puts("Zle dane. Prosze podac dodatnia liczbe calkowita.");
	}
}