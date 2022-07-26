// (a-b)/(a*b) - Exercise8Chapter6.c
// v1.0
#include <stdio.h>

int main(void)
{
	float a, b;
	int i;
	
	puts("Prosze podac dwie liczby:");
	i = scanf("%f %f", &a, &b);
	
	while (0 != i)
	{
    		printf("a = %f, b = %f,\n(a-b)/(a*b) = %f\n\n", a, b, (a-b)/(a*b));
    		puts("Prosze podac dwie liczby:");
		i = scanf("%f %f", &a, &b);
	} 

    puts("\nZycze milego dnia!");
	getchar();
	getchar();
	return 0;
}