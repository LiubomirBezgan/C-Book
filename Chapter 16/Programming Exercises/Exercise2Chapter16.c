//  The HARMONIC_MEAN() macro - Exercise2Chapter16.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	int i;
	double a = 1.0;
	double b = 3.0;
/*  Description ---------------------------------------------------------------*/
	puts("The program is used to test the macro \"function\" HARMONIC_MEAN().\n");
	
/*  Code ----------------------------------------------------------------------*/
	for (i = 0; i < 5; i++, a += 1.0, b -= 1.0)
	{
		printf("The harmonic mean of %g and %g is %g.\n", a, b, HARMONIC_MEAN(a, b));
	}
	printf("The harmonic mean of %g and %g is %g.\n", 4.0, -4.0, HARMONIC_MEAN(4.0, -4.0));

/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}