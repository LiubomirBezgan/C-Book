// definiowanie makrodefinicji uogolnionych
#include <stdio.h>
#include <math.h>

#define RAD_NA_ST (180/(4 * atan(1)))

// uogolniona wersja pierwiastka kwadratowego
#define SQRT(X) _Generic((X), \
	long double: sqrtl, \
	default: sqrt, \
	float: sqrtf)(X)

// uogolniona wersja sinusa (kat wyrazona w stopniach)
#define SIN(X) _Generic((X),\
	long double: sinl((X)/RAD_NA_ST),\
	default: sin((X)/RAD_NA_ST),\
	float: sinf((X)/RAD_NA_ST))

int main(void)
{
	float x = 45.0f;
	double xx = 45.0;
	long double xxx = 45.0L;
	float y = SQRT(x);
	double yy = SQRT(xx);
	long double yyy = SQRT(xxx);

	printf("%.17f\n", y);
	printf("%.17lf\n", yy);
	printf("%.17Lf\n", yyy);	
	int i = 45;
	yy = SQRT(i);
	printf("%.17lf\n", yy);
	yyy = SQRT(xxx);
	printf("%.17Lf\n", yyy);
	return 0;	
}