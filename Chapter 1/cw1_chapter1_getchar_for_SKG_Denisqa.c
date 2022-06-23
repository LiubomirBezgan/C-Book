// C Primer Plus Chapter 1 Exercise 1
// Program that converts inches to centimeters (1 inch = 2.54 cm)
// You have to delete certain Single Line Comments ("//") in the main() function in order to run target language version
// Version 2.3
#include <stdio.h>

int main(void)
	{
	float in;
	float out;

	// EN delete next "//" if you going to use English verion
	printf ("Hi Big Man! \nPlease enter an inch value:\n");

	// PL usuń następne "//", jeśli zamierzasz użyć wersji polskiej
	//printf ("Siema, Byku! \nProsze wprowadzic wartosc w calach:\n");

	scanf("%f", &in);
	out = in * 2.54;

	// EN delete next "//" if you going to use English verion
	printf ("The centimeter value equals %.2f cm", out);

	// PL usuń następne "//", jeśli zamierzasz użyć wersji polskiej
	//printf ("Wartosc w cm: %.2f cm", out);

	getchar();
	getchar();
	return 0;
	}
