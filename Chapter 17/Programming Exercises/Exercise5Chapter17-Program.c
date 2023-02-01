// Exercise5Chapter17-Implementation.c - korzysta z interfejsu "kolejka"
// kompilowac z plikiem Exercise5Chapter17-Implementation.c
#include <stdio.h>
#include "stos.h"

int main(void)
{
	Stos slowo;
	Pozycja tymcz;
	puts("The program pushes the characters of a string onto a stack, one by one,\nand then pops the characters from the stack and displays them.\n");
	InicjujStos(&slowo);
	puts("Please input the string:");
	while ( '\n' != (tymcz = getchar()) )
	{
		Poloz(tymcz, &slowo);
	}
	if (PustyStos(&slowo))
	{
		puts("No data entered.");
	}
	else
	{
		puts("Here is the result of popping:");
		while (Zdejmij(&tymcz, &slowo))
		{
			putchar(tymcz);
		}
	}
	puts("\nBye!");
	return 0;
}