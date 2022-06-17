#include <stdio.h>

int main(void)
	{
	float in;
	float out;

	printf ("Siema, Byku! \nProsze wprowadzic wartosc w calach:\n");
	scanf("%e", &in);
	out = in * 2.54;
	printf ("Wartosc w cm: %e cm", out);
	return 0;
	}
