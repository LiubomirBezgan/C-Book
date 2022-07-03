// opis - Exercise7Chapter4.c
// v1.0
#include <stdio.h>
#include <float.h>

int main(void)
{
	float fl = 1.0/3.0;
	double db = 1.0/3.0;
	printf(" %-19s %-19s\n", "FLOAT", "DOUBLE");
	printf(" %-19.4f %-19.4f\n", fl, db);
	printf(" %-19.12f %-19.12f\n", fl, db);
	printf(" %-19.16f %-19.16f\n", fl, db);

	printf("\n FLT_DIG = %2d\n DBL_DIG = %2d", FLT_DIG, DBL_DIG);

	getchar();
	return 0;
}