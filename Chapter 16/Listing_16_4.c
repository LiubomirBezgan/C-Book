// uzycie operatora ##
#include <stdio.h>
#define XNAZWA(n) x ## n
#define WYPISZ_XN(n) printf("x" #n " = %d\n", x ## n)

int main(void)
{
	int XNAZWA(1) = 14;		// rozwijane do int x1 = 14;
	int XNAZWA(2) = 20;		// rozwijane do int x2 = 20;
	int x3 = 30;
	WYPISZ_XN(1);			// rozwijane do printf("x1 = %d\n", x1);
	WYPISZ_XN(2);			// rozwijane do printf("x2 = %d\n", x2);
	WYPISZ_XN(3);			// rozwijane do printf("x3 = %d\n", x3);
	return 0;
}