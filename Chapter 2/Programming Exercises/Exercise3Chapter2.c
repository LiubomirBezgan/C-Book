// C Primer Plus Chapter 2 Exercise 3
// Version 1.0
#include <stdio.h>

int main(void) //przeliczenie wieku w latach na wiek w dniach bez uwzględnienia ułamków lat oraz lat przestępnych
{
	int wiek;
	wiek = 28;
	printf ("Mam %d lat.\nW przeliczeniu na dni mam %d dni xD\n", wiek, wiek * 365);
	return 0;
}