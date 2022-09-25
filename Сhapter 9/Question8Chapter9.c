//  Question8Chapter9.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <stdio.h>
int najwiekszy(int a, int b, int c);


/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int a, b, c;
	
/*  Description ---------------------------------------------------------------*/
	puts("Program zwraca najwieksza liczbe calkowita z trzech podanych przez uzytkownika.\n");
	
/*  Code ----------------------------------------------------------------------*/
	printf("\nPodaj pierwsza liczbe calkowita: ");
	scanf("%d", &a);
	printf("\nPodaj druga liczbe calkowita: ");
	scanf("%d", &b);
	printf("\nPodaj trzecia liczbe calkowita: ");
	scanf("%d", &c);
	printf("Najwieksza liczba to %d.\n", najwiekszy(a, b, c));

/*  Ending --------------------------------------------------------------------*/
	puts("\nWpisz '#', zeby zamknac program:");
	while (getchar() != '#')
		continue;
	return 0;
}

int najwiekszy(int a, int b, int c)
{
	if (a >= b)
	{
		if (a >= c)
			return a;
		else
			return c;
	}
	else
	{
		if (b >= c)
			return b;
		else
			return c;
	}
}

// Inne rozwiazanie
/*
int najwiekszy(int a, int b, int c)
{
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
} 
*/