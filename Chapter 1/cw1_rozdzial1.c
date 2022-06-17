// C Primer Plus Chapter 1 Exercise 1
// Program that converts inches to centimeters (1 inch = 2.54 cm)
// You have to delete certain Single Line Comments ("//") in the main() function in order to run target language version
// Version 2.0
#include <stdio.h>

int main(void)
	{
	float in;
	float out;

	// EN delete next "//" if you going to use English verion
	//printf ("Hi Big Man! \nPlease enter an inch value:\n");

	// PL usuń następne "//", jeśli zamierzasz użyć wersję polską
	//printf ("Siema, Byku! \nProsze wprowadzic wartosc w calach:\n");

	scanf("%e", &in);
	out = in * 2.54;

	// EN delete next "//" if you going to use English verion
	//printf ("The centimeter value equals %e cm", out);

	// PL usuń następne "//", jeśli zamierzasz użyć wersję polską
	//printf ("Wartosc w cm: %e cm", out);


	return 0;
	}
