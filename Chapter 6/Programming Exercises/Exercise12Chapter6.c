// ciagi - Exercise12Chapter6.c
// v1.0
#include <stdio.h>
int minusjedendopotengi(int c);
double ciagplus(float a);
double ciagminus(float b);


int main(void)
{
	float max;
	
	puts("Program oblicza wartosci wyrazow ponizszych szeregow do pewnego maksimum");
	puts("+ 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...");
	puts("- 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...");
	printf("Podaj maksimum (ujemny limit konczy program): ");
	scanf("%f", &max);
	
	while (max > 1)
	{
		printf("+ 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... +   1.0/%.1f = % f\n", max, ciagplus(max));
		printf("- 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... +/- 1.0/%.1f = % f\n", max, ciagminus(max));
		printf("\nPodaj kolejny maksimum (ujemny limit konczy program): ");
		scanf("%f", &max);
	}
	
	
	puts("Koniec");
	getchar();
	getchar();
	return 0;
}

int minusjedendopotengi(int c)
{
	int k, pot = 1;
	for (k = 0; k <= c; k++)
		pot *= -1;
	return pot;
}

double ciagplus(float a)
{
	int i;
	double out = 0;
	for (i=1; i < a; i++)
		out += (double) 1.0 / (1.0 + i);
	return out;
}

double ciagminus(float b)
{
	int j;
	double out = 0;
	for (j=1; j < b; j++)
		out += minusjedendopotengi(j+1) * (double) 1.0 / (1.0 + j);
	return out;
}