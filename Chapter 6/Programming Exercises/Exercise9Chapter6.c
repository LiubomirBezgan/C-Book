// (a-b)/(a*b) + function - Exercise9Chapter6.c
// v1.0
#include <stdio.h>
float func(float a, float b);				// prototyp ANSI

int main(void)
{
	float a, b;
	int i;
	
	puts("Prosze podac dwie liczby:");
	i = scanf("%f %f", &a, &b);
	
	while (0 != i)
	{
    		printf("a = %f, b = %f,\n(a-b)/(a*b) = %f\n\n", a, b, func(a, b)); //wywolanie funkcji
    		puts("Prosze podac dwie liczby:");
		i = scanf("%f %f", &a, &b);
	} 

    puts("\nZycze milego dnia!");
	getchar();
	getchar();
	return 0;
}

float func(float a, float b)			// definicja funkcji
{
	return (a-b)/(a*b);					// zwrot wartosci
}